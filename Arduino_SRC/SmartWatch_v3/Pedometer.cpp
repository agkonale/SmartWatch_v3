#include "Pedometer.h"

void Pedometer_Data::Update_StepCount()
{
    StepCount++;
}

void Pedometer_Data::Update_Steps_per_2s()
{   
    Steps_per_2s= StepCount-StepCount_Prev;
    StepCount_Prev=StepCount;
}


void Pedometer_Data::Update_Stride_Length()
{
    Stride_Length= (float)Height*(0.002 + Steps_per_2s/800.0);
}


void Pedometer_Data::Update_Speed()
{
    Speed=(float)Stride_Length*Steps_per_2s/2.0;
}


//Depends upon : Body weight, intensity of workout, conditioning level, and metabolism
//Provides Calories burnt 
void Pedometer_Data::Update_Calories()
{
    //Active Period
    if(Speed>0)
    {
        Calories+= (float)Speed*Weight/400.0; 
    }
  
    //Inactive Period
    else 
    {
        Calories+= (float)Weight/1800.0;
    }
}

void Pedometer_Data::Update_KM()
{
    KM+= (float)Stride_Length*Steps_per_2s/1000.0;
}


void Pedometer_Data::Get_Steps_Cal_Dist(long &Steps,float &Cal, float &Dist)
{
    Steps =StepCount;
    Cal =Calories;
    Dist =KM;
}

void Pedometer_Data::RESET()
{
    StepCount=0;
    StepCount_Prev=0;
    Steps_per_2s=0;
    Stride_Length=0;
    Speed=0;
    KM=0;
    Calories=0;
}

/*
void Pedometer_Data::STORE()
{
    EEPROM.put(addStp,StepCount);
    EEPROM.put(addCal,Calories);
    EEPROM.put(addKm,KM);
}
*/
