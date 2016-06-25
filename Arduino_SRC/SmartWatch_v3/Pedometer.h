#ifndef Pedometer_H
#define Pedometer_H

#include <arduino.h>
#include <EEPROM.h>
#include "EEPROM_ADDR.h"

//Refer http://www.analog.com/library/analogdialogue/archives/44-06/pedometer.html

class Pedometer_Data
{    
    uint8_t Height;             //cm
    uint8_t Weight;             //Kg
    long StepCount;             
    long StepCount_Prev;
    uint8_t Steps_per_2s;
    float Stride_Length;        //m
    float Speed;                //m/s
    float KM;
    float Calories;             //Cal

    public:
    //Constructor
    Pedometer_Data()
    {      
        //Height=EEPROM.read(addHeight);
        //Weight=EEPROM.read(addWeight);
        Height=176;
        Weight=82;
    }
     
    void Update_StepCount();
    void Update_Steps_per_2s();
    void Update_Stride_Length();
    void Update_Speed();
    void Update_Calories();
    void Update_KM();
    void Get_Steps_Cal_Dist(long &Steps,float &Cal, float &Dist);
    void RESET();
    //void STORE();
    
};

#endif
