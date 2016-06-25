#include <DS3231.h>
#include "BLE.h"
#include "DRV2605.h"
#include "Sensors.h"
#include "OLED.h"
#include "Power_Management.h"
#include "User_Biodata.h"
#include "Pedometer.h"

//Watch Mode:   
#define NORMAL_MODE 0
#define PEDOMETER_MODE 1
volatile uint8_t WATCH_MODE=NORMAL_MODE;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SCREEN_REFRESH_INTERVAL 200 //ms
uint8_t count=0;      //Awake time counter(1u = SCREEN_REFRESH_INTERVAL)
#define count_MAX 50  //10 sec

//For MPU6050 Setup
bool NORMAL_SETUP_FLAG=false;
bool PEDOMETER_SETUP_FLAG=false;

//Page ptr:
#define HOME_PAGE             0x0
#define PEDOMETER_PAGE        0x1
#define COMPASS_PAGE          0X2
#define BLANK_PAGE            0xA

volatile uint8_t Page_ptr=HOME_PAGE;  //Current page pointer

bool isReceived = false;  //To check if data is recieved from REMOTE  
bool is_Connected=false;  //Connection Status with Android phone

/////////////////////////////////////////////////////////PINS///////////////////////////////////////////////////////////////

//A4 (SDA), A5 (SCL)
#define ALARM_INTPIN 2                //Alarm Interrupt Pin (INT0)
#define ACC_INTPIN 3                  //For counting steps/Wake on Tilt(other applications requiring accelerometer)  (INT1) 

#define ON_OFF_INTPIN 8               //To stop Alarm vibration/To Wake up the screen (PCINT0)
#define Button1_INTPIN 9              //UI Button 1 (PCINT0)
#define Button2_INTPIN 10             //UI Button 2 (PCINT0)

#define BATTERY_SENSE_PIN A0          //select the input pin for the battery sense point

#define USB_CHARGING_STAT_PIN 4       //USB Connection status
#define BLE_CONNECTION_STAT_PIN 5     //BLE Connection status

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

volatile bool ALRM_ON_OFF = false;  //to disarm alarm
volatile bool ALRM_TRIGGERED = false;
bool is_ALRM_SET =false;

volatile bool Wake_via_INT=false; //Waking up screen via INT(button/Acc)

/////////////////////////////////////////////////////////////WDT/////////////////////////////////////////////////////////////////

ISR (WDT_vect) 
{
    wdt_disable();  // disable watchdog   
}  // end of WDT_vect

///////////////////////////////////////////////////////////DATA////////////////////////////////////////////////////////////////

USER_BIODATA USER;
Pedometer_Data Pedo_DATA;

/////////////////////////////////////////////////////Peripheral Devices///////////////////////////////////////////////////////

DS3231 RTC;
RTCDateTime Time;

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // A structure for controlling I2C OLED (128X64)  // I2C / TWI 
 
Adafruit_DRV2605 drv; // A structure for controlling Haptic driver DRV2605
#define alrm_vibe_count_MAX 20

Sensors GY_S; //11 DOF sensor GY87
volatile bool ACC_INT_FLAG =false;

////////////////////////////////////////////////////////ISR////////////////////////////////////////////////////////////////////
//Keep these as small as possible!!

//For UI buttons(3)
ISR (PCINT0_vect) 
{  

    if(digitalRead(ON_OFF_INTPIN)==0)
    {
        WATCH_MODE=NORMAL_MODE;
        Page_ptr=HOME_PAGE;
        Wake_via_INT=true;
        ALRM_ON_OFF=false;
    }
  
    else if(digitalRead(Button1_INTPIN)==0)
    {   
        WATCH_MODE=PEDOMETER_MODE;
        Page_ptr=PEDOMETER_PAGE;     
    }
  
    else if(digitalRead(Button2_INTPIN)==0)
    {   
        WATCH_MODE=NORMAL_MODE;
        Page_ptr=COMPASS_PAGE;    
    }

}

//For DS3231
void ISR_ALARM()
{
    ALRM_TRIGGERED=true;    
}


//For Acc
void ISR_Update_StepCount()
{
    ACC_INT_FLAG=true;
}

void ISR_Wake_Via_Acc()
{
    Wake_via_INT=true;
    Page_ptr=HOME_PAGE;
}


/////////////////////////////////////////////////////////////////Li-Po Battery Parameters///////////////////////////////////////////////////////
 
float Battery_Voltage;
uint8_t Battery_Lvl;
bool is_Charged=false;  //Charging complete status
bool is_Charging=false; //USB charging status

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void setup() 
{
    
    //Set Baud Rate for BLE HM10 
    Serial.begin(57600);  //Chosen to match Bootloader BAUD Rate of Arduino PRO-MINI for OTA programming
  
    pinMode(ON_OFF_INTPIN, INPUT_PULLUP);
    pinMode(Button1_INTPIN, INPUT_PULLUP);
    pinMode(Button1_INTPIN, INPUT_PULLUP);
    pinMode(USB_CHARGING_STAT_PIN, INPUT_PULLUP);
    pinMode(BLE_CONNECTION_STAT_PIN, INPUT_PULLUP);  
  
    //Unused Pins (Set as Output :LOW to conserve power)
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    
    cli();                    // switch interrupts off while messing with their settings  
    PCICR =0x01;              // Enable PCINT0 interrupt
    PCMSK0 = 0b00000111;      //Enable interrupts on Pins 8,9,10
    sei();                    // turn interrupts back on
    
    //Personalise
    USER.Set_BIODATA("Abhishek  ",176,20,0,82);
     
    analogReference(INTERNAL);  //Use internal precise 1v1 reference voltage for measuring battery volatge
    
    Wire.begin();
      
    DRV2605_Setup(drv); //Setup DRV2605
        
    attachInterrupt (0,ISR_ALARM,FALLING);  //DS3231 alarm INT

    //Load alarms for present day  
    Time=RTC.getDateTime();
    uint8_t temp_day= Time.dayOfWeek;   
    RTC.setAlarm1(temp_day,EEPROM.read(temp_day),EEPROM.read(temp_day+1), 0,DS3231_MATCH_DY_H_M_S); // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)    
    RTC.setAlarm2(temp_day,EEPROM.read(temp_day+2),EEPROM.read(temp_day+3),DS3231_MATCH_DY_H_M);  // setAlarm2(Date or Day, Hour, Minute, Mode, Armed = true)
  
    u8g.setFont(u8g_font_profont15r); //Set Display font

    //Launch Animation
    u8g.firstPage();
    do 
    {
    u8g.setColorIndex(1);
    u8g.drawBox(5, 5, 118, 54);
    u8g.setColorIndex(0);
    u8g.drawBox(10, 10, 108, 44);
    u8g.setColorIndex(1);
    u8g.drawBox(15, 15, 98, 34);
    u8g.setColorIndex(0);
    u8g.drawBox(20, 20, 88, 24);
    u8g.setColorIndex(1);
    u8g.drawBox(25, 25, 78, 14);
    delay(3000); 
    } while ( u8g.nextPage() );
    
    //Display Logo
    u8g.firstPage();
    do 
    {
        setContrast(0xFF);        
        u8g.drawBitmapP( 16, 0, 12, 64, IMG_logo_96x64);
        delay(3000);
        setContrast(0x02);
    } while ( u8g.nextPage() );
    
    delay(5000);

}


void loop() 
{     
     
    Battery_Voltage=Get_Battery_Voltage(A0);
    Battery_Lvl=Get_Battery_Lvl(Battery_Voltage);
 
    uint8_t temp_day=Time.dayOfWeek;     
    Time=RTC.getDateTime();
    //Loading stored alarms for new day 
    if(temp_day!=Time.dayOfWeek and is_ALRM_SET==true)
    {    
        temp_day= Time.dayOfWeek;       
        RTC.setAlarm1(temp_day,EEPROM.read(temp_day),EEPROM.read(temp_day+1),0,DS3231_MATCH_DY_H_M_S);  // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)       
        RTC.setAlarm2(temp_day,EEPROM.read(temp_day+2),EEPROM.read(temp_day+3),DS3231_MATCH_DY_H_M);  // setAlarm2(Date or Day, Hour, Minute, Mode, Armed = true)
    } 
      
    if(ALRM_TRIGGERED)
    {      
         
        u8g.drawBitmapP(80,16 ,4 ,32,ICON_BITMAP_Alarm_32x32);  // setAlarm2(Date or Day, Hour, Minute, Mode, Armed = true)
        displayTime_Digital(u8g,Time);

        //Reset flag
        ALRM_TRIGGERED=false;             
        ALRM_ON_OFF = true;
               
        uint8_t temp=0; //cylce counter
        //Load User Specific Alarm waveform stored in EEPROM
        uint8_t num=EEPROM.read(addDRVnum);
        uint8_t buf[7];
    
        for (uint8_t i = 0; i < num; i++)
        {
            buf[i]=EEPROM.read(addDRVeffects+i);
        }
    
        while(ALRM_ON_OFF==true)
        {
            Vibrate_A(drv,buf,num);
            temp++;
            if(temp>alrm_vibe_count_MAX)
              {
                  break;
              }
        }  
    } 
    


    if(WATCH_MODE==NORMAL_MODE)
    {
        if(NORMAL_SETUP_FLAG==false)
            {   
                GY_S.Initialize(NORMAL_MODE);
                attachInterrupt (1,ISR_Wake_Via_Acc,RISING); 
                PEDOMETER_SETUP_FLAG=false; 
                NORMAL_SETUP_FLAG=true; 
            }
                
        isReceived = receiveBluetoothData();  // Receive data from remote and parse
      
        // If data doesn't arrive
        if(!isReceived)
        {          
            is_Charging=digitalRead(USB_CHARGING_STAT_PIN);
            is_Connected=digitalRead(BLE_CONNECTION_STAT_PIN);
        
            //Turn on watch only if screen is properly oriented or USB is connected or Wake button is pressed
            if(is_Charging or Wake_via_INT)
            {   
                if(Wake_via_INT)
                {
                    count++;
                    if(count>count_MAX)
                    {
                        Wake_via_INT=false;
                        count=0;
                    }
                } 
                 
                Display(Page_ptr);        
                delay(SCREEN_REFRESH_INTERVAL);   
            }
          
            else
            {                    
                Display(BLANK_PAGE);  //Turn off Display
                Sleep(0b000111);  //Sleep for 2s    
            }  
        
      }
      
    }
  
  
  
    if(WATCH_MODE==PEDOMETER_MODE)
    { 
          
        if(PEDOMETER_SETUP_FLAG==false)
        {
            GY_S.Initialize(PEDOMETER_MODE);
            attachInterrupt (1,ISR_Update_StepCount,RISING); 
            NORMAL_SETUP_FLAG=false;   
            PEDOMETER_SETUP_FLAG=true; 
        }
        
        //PedoMeter algorithm       
        unsigned long T1,T2,deltaT;
        
        if(ACC_INT_FLAG)
        {   
            ACC_INT_FLAG=false;            
            deltaT = millis()-T1;
            T1=millis();
            
            //assume that people can run as rapidly as five steps per second and walk as slowly as one step every two seconds. delta T(0.2 -2 sec)
            if(deltaT>200 and deltaT<2000)
            {   
                Pedo_DATA.Update_StepCount();
            }  

            else
            {   
                GY_S.Update_Threshold();  //Dynamic Threshold Update
            }
        }
        
        if(millis()-T2 >2000)
        {   
            T2 =millis();
            Pedo_DATA.Update_Steps_per_2s();
            Pedo_DATA.Update_Stride_Length();
            Pedo_DATA.Update_Speed();
            Pedo_DATA.Update_Calories();
            Pedo_DATA.Update_KM();               
        }
                
        Display(Page_ptr);  //Display data on screen
        delay(SCREEN_REFRESH_INTERVAL);
                          
  }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(uint8_t Page_ptr)
{
    switch (Page_ptr)
    {
        //////////////////////////////////////////////////////////HOME-PAGE///////////////////////////////////////////////////////////////////      
        case HOME_PAGE:
        displayTime_Analog(u8g,Time);
        displayTime_Digital(u8g,Time);
        displayHomeScreenData(u8g,GY_S);
        
        switch (Battery_Lvl)
        {
            case 3:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_3);
            break;
  
            case 2:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_2);
            break;
  
            case 1:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_1);
            break;
  
            case 0:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_0);
            break;
        }

        if (is_Connected)
        {          
            u8g.drawBitmapP(16, 0, 2, 16,ICON_BITMAP_Bluetooth);                   
        }


        if (is_Charging)
        {           
            u8g.drawBitmapP(32, 0, 2, 16,ICON_BITMAP_Charging);           
        }

        if (is_ALRM_SET)
        {
            u8g.drawBitmapP(48, 0, 2, 16, ICON_BITMAP_Alarm_16x16);
        }
        break;
     
        //////////////////////////////////////////////////////////PEDOMETER-PAGE//////////////////////////////////////////////////////////////
        case PEDOMETER_PAGE:
        displayTime_Digital(u8g,Time);
        displayPedometerData(u8g,Pedo_DATA); 
          
        switch (Battery_Lvl)
        {
            case 3:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_3);
            break;
  
            case 2:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_2);
            break;
  
            case 1:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_1);
            break;
  
            case 0:
            u8g.drawBitmapP(0, 0, 2, 16, ICON_BITMAP_Batt_Lvl_0);
            break;
        } 
        break;

        //////////////////////////////////////////////////////////COMPASS-PAGE////////////////////////////////////////////////////////////////
        case COMPASS_PAGE:
        displayCompass(u8g,GY_S);
        break;

        //////////////////////////////////////////////////////////BLANK-PAGE/////////////////////////////////////////////////////////////////
        case BLANK_PAGE:
        u8g.firstPage();
        do  
        {       
        } 
        while ( u8g.nextPage() );
        break;
                      
    }
          
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----- BT, Data parsing functions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Parsing packet according to current mode
boolean receiveBluetoothData() 
{
    bool isTransactionEnded = false;    
    while(!isTransactionEnded) 
    {
        if(Serial.available()) 
        {
            byte c = Serial.read();
            switch(TRANSACTION_POINTER)
            {
                case TR_MODE_IDLE:
                if(c == TRANSACTION_START_BYTE) 
                {
                    TRANSACTION_POINTER = TR_MODE_WAIT_CMD;
                    TR_COMMAND = CMD_TYPE_NONE;
                }
                break;

                case TR_MODE_WAIT_CMD:
                parseCommand(c);
                break;

                case TR_MODE_WAIT_TIME:
                parseTime(c);
                break;

                case TR_MODE_WAIT_ALARM_TIME:
                parseAlarmTime(c);
                break;

                case TR_MODE_WAIT_COMPLETE:
                if(c == TRANSACTION_END_BYTE) 
                {
                    TRANSACTION_POINTER = TR_MODE_IDLE;
                    isTransactionEnded = true;
                }

                else
                {
                    isTransactionEnded = false;
                }
   
                break;
              
            }          
      }  
      
      else 
      {
          isTransactionEnded = true;
      }
      
    }  // End of while()
    return true;
}  // End of receiveBluetoothData()



void parseCommand(byte c) 
{
    switch(c)
    {
        case CMD_TYPE_SET_TIME:
        TRANSACTION_POINTER = TR_MODE_WAIT_TIME;
        TR_COMMAND = c; 
        break;

        case CMD_TYPE_SET_ALARM_TIME:
        TRANSACTION_POINTER = TR_MODE_WAIT_ALARM_TIME;
        TR_COMMAND = c;
        break;

        case CMD_TYPE_SET_ALARM_1:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;       
        RTC.setAlarm1(alarm_day,alarm_hour,alarm_minute,0,DS3231_MATCH_DY_H_M_S); // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)  
        EEPROM.write(alarm_day*4, alarm_hour);
        EEPROM.write(alarm_day*4+1, alarm_minute);
        break;

        case CMD_TYPE_SET_ALARM_2:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;        
        RTC.setAlarm2(alarm_day,alarm_hour,alarm_minute,DS3231_MATCH_DY_H_M); // setAlarm2(Date or Day, Hour, Minute, Mode, Armed = true)
        EEPROM.write(alarm_day*4+2, alarm_hour);
        EEPROM.write(alarm_day*4+3, alarm_minute);        
        break;

        case CMD_TYPE_ALARM_ON:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;
        is_ALRM_SET=true;
        break;

        case CMD_TYPE_ALARM_OFF:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;
        is_ALRM_SET=false;
        RTC.armAlarm1(false);
        RTC.armAlarm2(false);
        RTC.clearAlarm1();
        RTC.clearAlarm2();
        break;

        case CMD_TYPE_MESSAGE_RECIEVED:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;
        u8g.firstPage();
        do 
        {   
            u8g.drawBitmapP(32, 0, 8, 64, ICON_BITMAP_Message_Recieved_64x64);
        } while ( u8g.nextPage() );
        Vibrate_M(drv);
        delay(3000); 
        break;

        case CMD_TYPE_INCOMING_CALL:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;
        u8g.firstPage();
        do 
        {   
            u8g.drawBitmapP(40, 8, 6, 48, ICON_BITMAP_Incoming_Call_48x48);
        } while ( u8g.nextPage() );
        Vibrate_C(drv);
        delay(3000); 
        break;

        case CMD_TYPE_GET_PEDOMETER_DATA:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;
        long StepCount;
        float Calories,KM;
        Pedo_DATA.Get_Steps_Cal_Dist(StepCount,Calories,KM);

        Serial.println("S");
        Serial.println(StepCount);

        Serial.println("D");
        Serial.println(KM,3);
        
        Serial.println("C");
        Serial.println(Calories,3);
        break;

        case CMD_TYPE_RESET_PEDOMETER_DATA:
        TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        TR_COMMAND = c;
        Pedo_DATA.RESET();
        break;
        
        default:
        TRANSACTION_POINTER = TR_MODE_IDLE;
        TR_COMMAND = CMD_TYPE_NONE;
               
    }
    
}



void parseTime(byte c) 
{  
    if(TR_COMMAND == CMD_TYPE_SET_TIME) 
    {    
        if(timeParsingIndex < TIME_BUFFER_MAX) 
        {
            timeBuffer[timeParsingIndex] = (int)c;
            timeParsingIndex++;
        }
    
        else
        {
            processTransaction();
            TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        }
    }
}


void parseAlarmTime(byte c) 
{

    if(TR_COMMAND == CMD_TYPE_SET_ALARM_TIME) 
    {       
        if(alarmTimeParsingIndex < ALARM_TIME_BUFFER_MAX) 
        {
            alarmTimeBuffer[alarmTimeParsingIndex] = (int)c;
            alarmTimeParsingIndex++;
        }
    
        else
        {
            processTransaction();
            TRANSACTION_POINTER = TR_MODE_WAIT_COMPLETE;
        }
    }
}



void processTransaction() 
{
    switch(TR_COMMAND)
    {
        case CMD_TYPE_SET_TIME:
        SetTime(timeBuffer);
        timeParsingIndex = 0;
        break;

        case CMD_TYPE_SET_ALARM_TIME:
        alarm_day=alarmTimeBuffer[0];
        alarm_hour=alarmTimeBuffer[1];
        alarm_minute=alarmTimeBuffer[2];
        alarmTimeParsingIndex = 0;
        break;
    }  
}
 
void SetTime(char timeBuffer[4])
{
  
}
