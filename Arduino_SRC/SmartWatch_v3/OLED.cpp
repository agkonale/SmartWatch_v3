#include "OLED.h"

//Display functions

//Setting Contrast (0-255) (0x00-0xFF)  Current consumption increases with higher contrast
//Refer SSD1306 Datasheet for more details
void setContrast(uint8_t CONTRAST) 
{
    Wire.beginTransmission(OLED_ADDR);
    Wire.write(0x00);
    Wire.write(CONTRASTREG);
    Wire.endTransmission();
    Wire.beginTransmission(OLED_ADDR);
    Wire.write(0x00);
    Wire.write(CONTRAST);
    Wire.endTransmission();
}


//For displaying device logo
void drawLOGO(U8GLIB_SSD1306_128X64 &u8g)
{
    u8g.drawBitmapP( 15, 3, 12, 64, IMG_logo_96x64);
}



void displayTime_Analog(U8GLIB_SSD1306_128X64 &u8g, RTCDateTime &Time) 
{    

   /** Style 1 Circular
    u8g.drawCircle(clockCentreX, clockCentreY, 30); // main outer circle
    u8g.drawCircle(clockCentreX, clockCentreY, 2);  // small inner circle
    
    //hour ticks
    for( int z=0; z < 360; z += 30)
    {
        //Begin at 0° and stop at 360°
        float angle = z ;
        angle=(angle/57.29577951) ; //Convert degrees to radians
        int x2=(clockCentreX+(sin(angle)*30));
        int y2=(clockCentreY-(cos(angle)*30));
        int x3=(clockCentreX+(sin(angle)*(25)));
        int y3=(clockCentreY-(cos(angle)*(25)));
        u8g.drawLine(x2,y2,x3,y3);
    }
    **/

    //Style 2 Square
    u8g.drawFrame(66,2,60,60);
    //hour ticks
    u8g.drawLine(96,2,96,7);
    u8g.drawLine(126,32,121,32);
    u8g.drawLine(96,62,96,57);
    u8g.drawLine(66,32,71,32);

    float angle = 30/57.29577951 ;
    int T1 = (tan(angle))*25;
    int T2 = (tan(angle))*30;
    
    u8g.drawLine(clockCentreX+ T1,clockCentreY-25,clockCentreX+ T2,clockCentreY-30);
    u8g.drawLine(clockCentreX- T1,clockCentreY-25,clockCentreX- T2,clockCentreY-30);

    u8g.drawLine(clockCentreX+ T1,clockCentreY+25,clockCentreX+ T2,clockCentreY+30);
    u8g.drawLine(clockCentreX- T1,clockCentreY+25,clockCentreX- T2,clockCentreY+30);

    u8g.drawLine(clockCentreX+25,clockCentreY- T1,clockCentreX+30,clockCentreY- T2);
    u8g.drawLine(clockCentreX+25,clockCentreY+ T1,clockCentreX+30,clockCentreY+ T2);

    u8g.drawLine(clockCentreX-25,clockCentreY- T1,clockCentreX-30,clockCentreY- T2);
    u8g.drawLine(clockCentreX-25,clockCentreY+ T1,clockCentreX-30,clockCentreY+ T2);
    
    // display second hand
    angle = Time.second*6 ;
    angle=(angle/57.29577951) ; //Convert degrees to radians  
    int x3=(clockCentreX+(sin(angle)*(20)));
    int y3=(clockCentreY-(cos(angle)*(20)));
    u8g.drawLine(clockCentreX,clockCentreY,x3,y3);
    

    
    // display minute hand
    angle = Time.minute*6 ;
    angle=(angle/57.29577951) ; //Convert degrees to radians  
    x3=(clockCentreX+(sin(angle)*(17)));
    y3=(clockCentreY-(cos(angle)*(17)));
    u8g.drawLine(clockCentreX,clockCentreY,x3,y3);

    
    // display hour hand
    angle = Time.hour*30 + int((Time.minute / 12) * 6 )   ;
    angle=(angle/57.29577951) ; //Convert degrees to radians  
    x3=(clockCentreX+(sin(angle)*(9)));
    y3=(clockCentreY-(cos(angle)*(9)));
    u8g.drawLine(clockCentreX,clockCentreY,x3,y3);

    u8g.setPrintPos(70,40);  
    u8g.print(Time.day);
    u8g.print("/");
    u8g.print(Time.month);
   
}

void displayTime_Digital(U8GLIB_SSD1306_128X64 &u8g, RTCDateTime &Time) 
{
    String thisTime = "";
    thisTime=String(Time.hour) + ":";
    if (Time.minute < 10){ thisTime=thisTime + "0";} // add leading zero if required
    thisTime=thisTime + String(Time.minute) + ":";
    if (Time.second < 10){ thisTime=thisTime + "0";} // add leading zero if required
    thisTime=thisTime + String(Time.second);
    const char* newTime = (const char*) thisTime.c_str();
    u8g.drawStr(0,20, newTime); 
}


void displayHomeScreenData(U8GLIB_SSD1306_128X64 &u8g,Sensors &GY)
{
    float temperature,pressure,altitude;

    GY.Get_Temp_Pressure_Alt(temperature,pressure,altitude);
    
    u8g.setPrintPos(0,30);
    u8g.print("T: <");
    u8g.print(temperature);
    u8g.print("> C");

    u8g.setPrintPos(0,40);
    u8g.print("P: <");
    u8g.print(pressure);
    u8g.print("> Pa");
  
    u8g.setPrintPos(0,50);
    u8g.print("A: <");
    u8g.print(altitude);
    u8g.print("> m");

}


void displayPedometerData(U8GLIB_SSD1306_128X64 &u8g,Pedometer_Data &Data)
{ 

    long StepCount;
    float Calories,KM;
    Data.Get_Steps_Cal_Dist(StepCount,Calories,KM);
    
    u8g.drawFrame(64,0,64,21);
    u8g.drawFrame(64,21,64,21);
    u8g.drawFrame(64,42,64,21);
    
    u8g.setPrintPos(64,10);
    u8g.print("Steps :");
    u8g.print(StepCount);
    
    u8g.setPrintPos(64,30);
    u8g.print("KM :");
    u8g.print(KM);

    u8g.setPrintPos(64,50);
    u8g.print("Calories :");
    u8g.print(Calories);  

   
}


void displayCompass(U8GLIB_SSD1306_128X64 &u8g,Sensors &GY)
{
    u8g.drawCircle(96, 32, 30);
    
    for( int z=0; z < 360; z += 30)
    {
        //Begin at 0° and stop at 360°
        float angle = z ;
        angle=(angle/57.29577951) ; //Convert degrees to radians
        int x1=(clockCentreX+(sin(angle)*30));
        int y1=(clockCentreY-(cos(angle)*30));
        int x2=(clockCentreX+(sin(angle)*(25)));
        int y2=(clockCentreY-(cos(angle)*(25)));
        u8g.drawLine(x1,y1,x2,y2);
    } 
    
    float direction = GY.Get_Compass_Reading();
    u8g.setPrintPos(10,32);
    u8g.print(direction);
    u8g.print(" Deg");
    
    direction=direction/57.29577951;
    u8g.drawLine(96,32,96+20*sin(direction),32-20*cos(direction));
  
}

