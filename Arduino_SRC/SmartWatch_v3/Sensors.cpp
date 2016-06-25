#include "Sensors.h"


void Sensors::Initialize(uint8_t Mode)
{
    detachInterrupt(1);
    accelgyro.initialize();
    accelgyro.setIntMotionEnabled(1);//Set Motion Detection interrupt enabled status.
    accelgyro.setIntFreefallEnabled(1);
    accelgyro.setIntZeroMotionEnabled(0);
    accelgyro.setIntFIFOBufferOverflowEnabled(0);
    accelgyro.setIntDataReadyEnabled(0); //New interrupt enabled status
  
    //Specific settings for MPU6050
    switch (Mode)
    {
        case 0:
        barometer.initialize();
        mag.initialize();
        accelgyro.setDHPFMode(3); // high-pass filter configuration more than 1.25Hz pass
        accelgyro.setDLPFMode(5); // low-pass filter configuration below 10Hz pass
        
        accelgyro.setMotionDetectionThreshold(threshold_N);  
        accelgyro.setMotionDetectionDuration(detcdur1); // motion detection duration threshold value (LSB = 1ms)   
      
        accelgyro.setStandbyXAccelEnabled(1); //Disable X,Y axis
        accelgyro.setStandbyYAccelEnabled(1);
        
        delay(50); 
        break;
    
        case 1:
        accelgyro.setDHPFMode(4); //New high-pass filter configuration more than 0.63Hz pass
        accelgyro.setDLPFMode(5); //New low-pass filter configuration below 10Hz pass
        
        accelgyro.setMotionDetectionThreshold(threshold_P_MIN);  
        accelgyro.setMotionDetectionDuration(detcdur2); // Motion detection duration threshold value (LSB = 1ms) 
        
        accelgyro.setStandbyXAccelEnabled(0);
        accelgyro.setStandbyYAccelEnabled(0);
        
        delay(50);    
        break;
  
    }
  
        accelgyro.setInterruptMode(1); //New interrupt mode (0=active-high, 1=active-low)
        accelgyro.setInterruptDrive(0); //New interrupt drive mode (0=push-pull, 1=open-drain)
        accelgyro.setInterruptLatch(0); //New latch mode (0=50us-pulse, 1=latch-until-int-cleared)
        accelgyro.setInterruptLatchClear(0); //New latch clear mode (0=status-read-only, 1=any-register-read)
        
        accelgyro.setRate(7); //Set the rate to disable the gyroscope
        accelgyro.setWakeFrequency(3); //Wake up the accelerometer at 1.25Hz to save power
        accelgyro.setWakeCycleEnabled(1); //Enable only accel. ON - Low power mode, waking it up from time to time
        
        delay(50);
        
        accelgyro.setTempSensorEnabled(0);
        accelgyro.setStandbyXGyroEnabled(1);
        accelgyro.setStandbyYGyroEnabled(1);
        accelgyro.setStandbyZGyroEnabled(1);
        
        delay(50);    
}

void Sensors::Update_Threshold()
{
    if(threshold_flag)
    {   if(threshold_P < threshold_P_MAX)
        {
            threshold_P++;
            accelgyro.setMotionDetectionThreshold(threshold_P);         
        }
        else
        {
            threshold_flag=false;
        }        
    }
    
    else
    {   
        if(threshold_P > threshold_P_MIN)  
        {
            threshold_P--;
            accelgyro.setMotionDetectionThreshold(threshold_P);
        }
  
        else
        {
            threshold_flag=true;
        }          
    }
        
}


float Sensors::Get_Compass_Reading()
{
    int16_t mx, my, mz; 
    mag.getHeading(&mx, &my, &mz);  // read raw heading measurements from device
    
    float heading = atan2(my, mx);
    if(heading < 0)
    {
        heading += 2 * M_PI;
    }

    return heading;
      
}


//Celsius/Pa/m
void Sensors::Get_Temp_Pressure_Alt(float &temperature,float &pressure,float &altitude)
{
    
    barometer.setControl(BMP085_MODE_TEMPERATURE);  // request temperature
    delay(5);    
    temperature= barometer.getTemperatureC(); // read calibrated temperature value in degrees Celsius
 
    // MODES,conv delay: 3:Ultra High Res [25.5],2:High Res [13.5],1:Standard [7.5], 0:Ultra Low Power [4.5]
    barometer.setControl(BMP085_MODE_PRESSURE_1); // request pressure 
    delay(8);   
    pressure= barometer.getPressure();  // read calibrated pressure value in Pascals (Pa)

    altitude=barometer.getAltitude(pressure);
  
}

