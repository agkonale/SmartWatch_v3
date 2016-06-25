#include "Motor.h"

void Vibe_Pulse(int active_T,int idle_T,int overdrivelength,int pulse_count)
{   
    for (int i=0;i<pulse_count;i++)  
    {
        analogWrite(VIB_MOTOR_PIN,Overdrive_Val);
        delay(overdrivelength);
        analogWrite(VIB_MOTOR_PIN,Normal_Val);
        delay(active_T);
        analogWrite(VIB_MOTOR_PIN,0);
        delay(idle_T);      
    }   
}


void Vibrate_A()
{
    int idle_T; 
    randomSeed(analogRead(A1));
    idle_T=random(150,600);
    
    Vibe_Pulse(300,idle_T,20,3);
    delay(1000);  
}

void Vibrate_C()
{
    for(int i=0;i<3;i++)
    {
        Vibe_Pulse(50,300,20,3);
        Vibe_Pulse(150,100,20,2);
        Vibe_Pulse(50,300,20,3); 
        delay(1000); 
    }    
}


void Vibrate_M()
{
    for(int i=0;i<3;i++)
    {
        Vibe_Pulse(50,100,20,3);
        Vibe_Pulse(150,100,20,2);
        Vibe_Pulse(50,100,20,3);  
        delay(1000);
    }   
}

