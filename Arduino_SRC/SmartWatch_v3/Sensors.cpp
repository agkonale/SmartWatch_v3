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
        
        accelgyro.setMotionDetectionThreshold(threshold1);  
        accelgyro.setMotionDetectionDuration(detcdur1); // motion detection duration threshold value (LSB = 1ms)   
  
        //Disable X,Y axis
        accelgyro.setStandbyXAccelEnabled(1);
        accelgyro.setStandbyYAccelEnabled(1);
        
        delay(50); 
        break;
    
        case 1:
        accelgyro.setDHPFMode(3); //New high-pass filter configuration more than 1.25Hz pass
        accelgyro.setDLPFMode(5); //New low-pass filter configuration below 10Hz pass
        
        accelgyro.setMotionDetectionThreshold(threshold2);  
        accelgyro.setMotionDetectionDuration(detcdur2); // motion detection duration threshold value (LSB = 1ms) 
        
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

float Sensors::Get_Compass_Reading()
{
    int16_t mx, my, mz;
    // read raw heading measurements from device
    mag.getHeading(&mx, &my, &mz);
    
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
    // request temperature
    barometer.setControl(BMP085_MODE_TEMPERATURE);   
    delay(5);
    // read calibrated temperature value in degrees Celsius
    temperature= barometer.getTemperatureC();

    // request pressure 
    //MODES,conv delay: 3:Ultra High Res [25.5],2:High Res [13.5],1:Standard [7.5], 0:Ultra Low Power [4.5]
    barometer.setControl(BMP085_MODE_PRESSURE_1);
    delay(8);
    // read calibrated pressure value in Pascals (Pa)
    pressure= barometer.getPressure();

    altitude=barometer.getAltitude(pressure);
  
}

