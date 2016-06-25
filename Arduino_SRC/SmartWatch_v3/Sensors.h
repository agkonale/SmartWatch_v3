#ifndef SENSORS_H
#define SENSORS_H

#include <arduino.h>
#include "I2Cdev.h"
#include "BMP085.h"
#include "HMC5883L.h"
#include "MPU6050.h"


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

/**
NORMAL_MODE 0
PEDOMETER_MODE 1
**/

//For NORMAL_MODE
#define threshold_N  5
#define detcdur1    10

//For PEDOMETER_MODE
#define threshold_P_MAX  10
#define threshold_P_MIN  5
#define detcdur2    20


class Sensors 
{ 
   
    //BMP180
    // class default I2C address is 0x77
    // specific I2C addresses may be passed as a parameter here
    // (though the BMP085 supports only one address)
    BMP085 barometer;   
    
    //HMC5883L
    // specific I2C addresses may be passed as a parameter here
    // this device only supports one I2C address (0x1E)
    HMC5883L mag;
    
    //MPU6050
    // class default I2C address is 0x68
    // specific I2C addresses may be passed as a parameter here
    // AD0 low = 0x68 (default for InvenSense evaluation board)
    // AD0 high = 0x69
    MPU6050 accelgyro;
    //MPU6050 accelgyro(0x69); // <-- use for AD0 high  
    uint8_t threshold_P;
    bool threshold_flag=true;
      
    public:
    void Initialize(uint8_t Mode);

    void Update_Threshold();
    
    //in degrees 0:North
    float Get_Compass_Reading();

    void Get_Temp_Pressure_Alt(float &temperature,float &pressure,float &altitude);
    
};



#endif
