#ifndef MOTOR_H
#define MOTOR_H

#include <arduino.h>

//https://www.precisionmicrodrives.com/application-notes/ab-013-advanced-vibration-alerting-waveforms

#define VIB_MOTOR_PIN 6
#define Overdrive_Val 255    //VBAT
#define Normal_Val 200       //3v3

void Vibe_Pulse(int active_T,int idle_T,int overdrivelength,int pulse_count);

void Vibrate_A();
void Vibrate_C(); //Vibe alert for incoming Call  //Fixed Pattern
void Vibrate_M(); //Vibe alert for recieved Message //Fixed Pattern

#endif
