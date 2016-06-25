#ifndef Power_Management_H
#define Power_Management_H

#include <arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

//Vmax=4.43 V     Param: Pin No.(A0-A7)     Precision :0.0043304 V
float Get_Battery_Voltage(uint8_t SENSE_PIN);

//(0-3)   Param: Battery Voltage
uint8_t Get_Battery_Lvl(float battery_voltage);

//For Power Saving    Param: Sleep Interval(in sec)   Credit :http://www.gammon.com.au 
void Sleep(byte interval);

#endif
