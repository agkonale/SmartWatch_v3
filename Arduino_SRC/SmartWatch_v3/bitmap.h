#ifndef BITMAP_H
#define BITMAP_H

//device logo (96 X 64)
//Generated using LCD Assistant
//Horizontal Byte Orientation
//Refer : https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples

const unsigned char PROGMEM IMG_logo_96x64[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFE, 0x0F, 0xFC, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0xFE, 0x0F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x01,
    0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00,
    0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00,
    0x00, 0x00, 0x3F, 0x80, 0x00, 0x7F, 0xE0, 0x00, 0x07, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x7F, 0x81,
    0x83, 0x3F, 0xFF, 0xF0, 0x3F, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0x81, 0x06, 0x3F, 0xFF, 0xFC,
    0x7F, 0xFF, 0xFC, 0x60, 0x00, 0x00, 0xFF, 0x81, 0x0C, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x60,
    0x00, 0x00, 0xFF, 0x81, 0x18, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x60, 0x00, 0x01, 0xF7, 0xC3,
    0x30, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x60, 0x00, 0x03, 0xE7, 0xC3, 0xE0, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x6C, 0x00, 0x07, 0xE7, 0xC3, 0xC0, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6C,
    0x00, 0x07, 0xE7, 0xC3, 0x60, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6C, 0x00, 0x0F, 0x87, 0xC2,
    0x20, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6C, 0x00, 0x0F, 0x87, 0xE6, 0x30, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x6D, 0x80, 0x1F, 0x07, 0xE6, 0x18, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D,
    0x80, 0x1F, 0x07, 0xEC, 0x0C, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D, 0x80, 0x3E, 0x07, 0xEC,
    0x0C, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D, 0x80, 0x7E, 0x03, 0xE0, 0x00, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x6D, 0x80, 0x7C, 0x03, 0xE0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D,
    0x80, 0xF8, 0x03, 0xE0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D, 0x80, 0xF8, 0x03, 0xE0,
    0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D, 0x81, 0xF0, 0x01, 0xF0, 0x00, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x6D, 0x83, 0xF0, 0x01, 0xF0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D,
    0x87, 0xE0, 0x01, 0xF0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D, 0x87, 0xE0, 0x01, 0xF0,
    0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6D, 0x8F, 0xC0, 0x01, 0xF0, 0x00, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x6D, 0x8F, 0x80, 0x01, 0xF0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6C,
    0x1F, 0xFF, 0xFF, 0xF0, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6C, 0x3F, 0xFF, 0xFF, 0xF0,
    0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x6C, 0x3F, 0xFF, 0xFF, 0xF0, 0x00, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x60, 0x7F, 0xFF, 0xFF, 0xF8, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x60,
    0x7F, 0xFF, 0xFF, 0xF8, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x60, 0xF8, 0x00, 0x00, 0xF8,
    0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0xF8, 0x00, 0x00, 0xF8, 0x00, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x01, 0xF0, 0x00, 0x00, 0xFC, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x03,
    0xF0, 0x00, 0x00, 0xFC, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x07, 0xE0, 0x00, 0x00, 0xFC,
    0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x07, 0xC0, 0x00, 0x00, 0xFC, 0x00, 0x1F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFC, 0x07, 0xC0, 0x00, 0x00, 0xFC, 0x00, 0x1F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFC, 0x0F,
    0x80, 0x00, 0x00, 0x7C, 0x00, 0x1F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFE, 0x0F, 0x80, 0x00, 0x00, 0x7C,
    0x00, 0x3F, 0xFF, 0xFC, 0x1F, 0xFF, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x3F, 0xFF, 0xF8,
    0x00, 0x7F, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x00, 0x3F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 16x16 bitmap icons
const unsigned char PROGMEM ICON_BITMAP_Batt_Lvl_3[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x3f,0xfc,
    0x20,0x04,
    0x6d,0xb4,
    0x6d,0xb4,
    0x6d,0xb4,
    0x20,0x04,
    0x3f,0xfc,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
}; 

const unsigned char PROGMEM ICON_BITMAP_Batt_Lvl_2[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x3f,0xfc,
    0x20,0x04,
    0x61,0xb4,
    0x61,0xb4,
    0x61,0xb4,
    0x20,0x04,
    0x3f,0xfc,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
}; 

const unsigned char PROGMEM ICON_BITMAP_Batt_Lvl_1[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x3f,0xfc,
    0x20,0x04,
    0x60,0x34,
    0x60,0x34,
    0x60,0x34,
    0x20,0x04,
    0x3f,0xfc,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
}; 

const unsigned char PROGMEM ICON_BITMAP_Batt_Lvl_0[] = 
{
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x3f,0xfc,
    0x20,0x04,
    0x60,0x04,
    0x60,0x04,
    0x60,0x04,
    0x20,0x04,
    0x3f,0xfc,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00
}; 


//Generated from https://www.iconfinder.com <Horizontal Byte Orientation>
const unsigned char  PROGMEM ICON_BITMAP_Bluetooth[] = 
{
    0x00, 0x80, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xB0, 0x0C, 0x98, 0x06, 0xB0, 0x03, 0xE0, 0x01, 0xC0,
    0x01, 0xC0, 0x03, 0xE0, 0x06, 0xB0, 0x0C, 0x98, 0x00, 0xB0, 0x00, 0xE0, 0x00, 0xC0, 0x00, 0x80
};


const unsigned char PROGMEM ICON_BITMAP_Charging[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x0E, 0x01, 0x1F, 0x06, 0x1F, 0x8E, 0x3F, 0xFC,
    0x7B, 0xFC, 0x61, 0xF8, 0x80, 0xF8, 0x00, 0x70, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM ICON_BITMAP_Alarm_16x16[] = 
{
    0x38, 0x0C, 0x70, 0x0E, 0x67, 0xE6, 0x5E, 0x7A, 0x19, 0x98, 0x31, 0x8C, 0x21, 0x84, 0x61, 0x86,
    0x61, 0xF6, 0x60, 0x06, 0x20, 0x0C, 0x30, 0x0C, 0x18, 0x18, 0x1F, 0xF8, 0x37, 0xEC, 0x20, 0x04
};



// 32x32 bitmap images
const unsigned char PROGMEM ICON_BITMAP_Alarm_32x32[] = 
{
    0x0F, 0x00, 0x00, 0xF0, 0x3F, 0xC0, 0x03, 0xFC, 0x7F, 0xE0, 0x07, 0xFE, 0x7F, 0x80, 0x01, 0xFE,
    0xFE, 0x0F, 0xF0, 0x7F, 0xFC, 0x3F, 0xFC, 0x3F, 0xF8, 0xFF, 0xFF, 0x1F, 0xF1, 0xFF, 0xFF, 0x8F,
    0x63, 0xF8, 0x1F, 0xC6, 0x47, 0xE0, 0x07, 0xE2, 0x0F, 0x81, 0x81, 0xF0, 0x0F, 0x03, 0xC0, 0xF0,
    0x1F, 0x03, 0xC0, 0xF8, 0x1E, 0x03, 0xC0, 0x78, 0x3E, 0x03, 0xC0, 0x7C, 0x3C, 0x03, 0xC0, 0x3C,
    0x3C, 0x03, 0xC0, 0x3C, 0x3C, 0x03, 0xC0, 0x3C, 0x3C, 0x07, 0xC0, 0x3C, 0x3C, 0x0F, 0x80, 0x3C,
    0x3C, 0x0F, 0x00, 0x3C, 0x3E, 0x06, 0x00, 0x7C, 0x1E, 0x00, 0x00, 0x78, 0x1F, 0x00, 0x00, 0xF8,
    0x0F, 0x00, 0x00, 0xF0, 0x0F, 0x80, 0x01, 0xF0, 0x07, 0xE0, 0x07, 0xE0, 0x0F, 0xF8, 0x1F, 0xF0,
    0x1F, 0xFF, 0xFF, 0xF8, 0x3E, 0xFF, 0xFF, 0x7C, 0x3C, 0x3F, 0xFC, 0x3C, 0x18, 0x0F, 0xF0, 0x18
};


//48x48 bitmap images
const unsigned char PROGMEM ICON_BITMAP_Incoming_Call_48x48[] = 
{
    0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF,
    0xE0, 0x00, 0x00, 0x0F, 0xE0, 0x07, 0xF0, 0x00, 0x00, 0x3F, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x7C,
    0x00, 0x00, 0x3E, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x0F, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x07, 0x80,
    0x03, 0xC0, 0x30, 0x00, 0x03, 0xC0, 0x07, 0x80, 0xF8, 0x00, 0x01, 0xE0, 0x0F, 0x00, 0xF8, 0x00,
    0x00, 0xF0, 0x0E, 0x03, 0x7C, 0x00, 0x00, 0x70, 0x1C, 0x07, 0x7E, 0x00, 0x00, 0x38, 0x3C, 0x0F,
    0xBE, 0x00, 0x00, 0x3C, 0x38, 0x0F, 0x9F, 0x00, 0x00, 0x1C, 0x38, 0x0F, 0xDF, 0x00, 0x00, 0x1C,
    0x70, 0x0F, 0xEF, 0x00, 0x00, 0x0E, 0x70, 0x0F, 0xEE, 0x00, 0x00, 0x0E, 0x70, 0x0F, 0xF0, 0x00,
    0x00, 0x0E, 0x60, 0x0F, 0xE0, 0x00, 0x00, 0x06, 0xE0, 0x0F, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x07,
    0xC0, 0x00, 0x00, 0x07, 0xE0, 0x07, 0xC0, 0x00, 0x00, 0x07, 0xE0, 0x07, 0xE0, 0x00, 0x00, 0x07,
    0xE0, 0x03, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x03, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x01, 0xF0, 0x00,
    0x00, 0x07, 0xE0, 0x01, 0xF0, 0x00, 0x00, 0x07, 0x60, 0x00, 0xF8, 0x03, 0x00, 0x06, 0x70, 0x00,
    0xFC, 0x0F, 0x00, 0x0E, 0x70, 0x00, 0x7E, 0x0F, 0x80, 0x0E, 0x70, 0x00, 0x3F, 0xAF, 0xC0, 0x0E,
    0x38, 0x00, 0x3F, 0xF7, 0xC0, 0x1C, 0x38, 0x00, 0x1F, 0xF3, 0xE0, 0x1C, 0x3C, 0x00, 0x0F, 0xFB,
    0xE0, 0x3C, 0x1C, 0x00, 0x07, 0xFD, 0xF0, 0x38, 0x0E, 0x00, 0x03, 0xFD, 0xF0, 0x70, 0x0F, 0x00,
    0x01, 0xFE, 0xE0, 0xF0, 0x07, 0x80, 0x00, 0xFE, 0x41, 0xE0, 0x03, 0xC0, 0x00, 0x7E, 0x03, 0xC0,
    0x01, 0xE0, 0x00, 0x00, 0x07, 0x80, 0x00, 0xF0, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x7C, 0x00, 0x00,
    0x3E, 0x00, 0x00, 0x3F, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x0F, 0xE0, 0x07, 0xF0, 0x00, 0x00, 0x07,
    0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00
};


// 64x64 bitmap images
const unsigned char PROGMEM ICON_BITMAP_Message_Recieved_64x64[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
    0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x04, 0x60, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x04,
    0x60, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x04, 0x60, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x04,
    0x60, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xFC, 0x04, 0x60, 0x37, 0xC0, 0x00, 0x00, 0x03, 0xEC, 0x04,
    0x60, 0x33, 0xE0, 0x00, 0x00, 0x0F, 0xCC, 0x04, 0x60, 0x31, 0xF0, 0x00, 0x00, 0x1F, 0x8C, 0x04,
    0x60, 0x30, 0xF8, 0x00, 0x00, 0x3F, 0x0C, 0x04, 0x60, 0x30, 0x7C, 0x00, 0x00, 0x7E, 0x0C, 0x04,
    0x60, 0x30, 0x3E, 0x00, 0x00, 0xFC, 0x0C, 0x04, 0x60, 0x30, 0x1F, 0x00, 0x01, 0xF0, 0x0C, 0x04,
    0x60, 0x30, 0x0F, 0x80, 0x03, 0xE0, 0x0C, 0x04, 0x60, 0x30, 0x07, 0xC0, 0x07, 0xC0, 0x0C, 0x04,
    0x60, 0x30, 0x03, 0xF0, 0x0F, 0x80, 0x0C, 0x04, 0x60, 0x30, 0x01, 0xF8, 0x1F, 0x00, 0x0C, 0x04,
    0x60, 0x30, 0x01, 0xFC, 0x3F, 0x80, 0x0C, 0x04, 0x60, 0x30, 0x03, 0xFF, 0xFF, 0xC0, 0x0C, 0x04,
    0x60, 0x30, 0x07, 0xDF, 0xFB, 0xE0, 0x0C, 0x04, 0x60, 0x30, 0x0F, 0x8F, 0xF1, 0xF0, 0x0C, 0x04,
    0x60, 0x30, 0x1F, 0x07, 0xC0, 0xF8, 0x0C, 0x04, 0x60, 0x30, 0x3E, 0x00, 0x00, 0x7C, 0x0C, 0x04,
    0x60, 0x30, 0x7C, 0x00, 0x00, 0x3E, 0x0C, 0x04, 0x60, 0x30, 0xF8, 0x00, 0x00, 0x1F, 0x0C, 0x04,
    0x60, 0x31, 0xF0, 0x00, 0x00, 0x0F, 0x8C, 0x04, 0x60, 0x37, 0xE0, 0x00, 0x00, 0x07, 0xCC, 0x04,
    0x60, 0x3F, 0xC0, 0x00, 0x00, 0x03, 0xFC, 0x04, 0x60, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xFC, 0x04,
    0x60, 0x3E, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x04, 0x60, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x04,
    0x60, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x04, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
    0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif