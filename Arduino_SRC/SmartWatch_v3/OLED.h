#ifndef OLED_H
#define OLED_H

#include <arduino.h>
#include <U8glib.h>
#include "Wire.h"
#include "bitmap.h"
#include <DS3231.h>
#include "Sensors.h"
#include "Pedometer.h"

// b0111100/b0111101 for DC LOW/HIGH
#define OLED_ADDR 0x3c  //(Default DC-LOW)
#define CONTRASTREG 0x81

#define clockCentreX  96 // used to fix the centre the analog clock
#define clockCentreY  32 // used to fix the centre the analog clock

void setContrast(uint8_t CONTRAST);

void displayTime_Analog(U8GLIB_SSD1306_128X64 &u8g,RTCDateTime &Time);
void displayTime_Digital(U8GLIB_SSD1306_128X64 &u8g,RTCDateTime &Time);

void displayHomeScreenData(U8GLIB_SSD1306_128X64 &u8g,Sensors &GY);
void displayPedometerData(U8GLIB_SSD1306_128X64 &u8g,Pedometer_Data &Data);

void displayCompass(U8GLIB_SSD1306_128X64 &u8g,Sensors &GY);

#endif
