#ifndef BLE_H
#define BLE_H


//-----BLE Protocol

//----- Bluetooth transaction parsing
#define TR_MODE_IDLE 0x11
#define TR_MODE_WAIT_CMD 0x21
#define TR_MODE_WAIT_MESSAGE 0x31
#define TR_MODE_WAIT_TIME 0x41
#define TR_MODE_WAIT_ALARM_TIME 0x51
#define TR_MODE_WAIT_COMPLETE 0x61

#define TRANSACTION_START_BYTE 0xfc
#define TRANSACTION_END_BYTE 0xfd

#define CMD_TYPE_NONE 0x00
#define CMD_TYPE_SET_TIME 0x10
#define CMD_TYPE_SET_ALARM_TIME 0x20
#define CMD_TYPE_SET_ALARM_1 0x30
#define CMD_TYPE_SET_ALARM_2 0x40
#define CMD_TYPE_ALARM_ON 0x50
#define CMD_TYPE_ALARM_OFF 0x60
#define CMD_TYPE_MESSAGE_RECIEVED 0x70
#define CMD_TYPE_INCOMING_CALL 0x80
#define CMD_TYPE_GET_PEDOMETER_DATA 0x90
#define CMD_TYPE_RESET_PEDOMETER_DATA 0xf0

uint8_t alarm_day = 0;
uint8_t alarm_hour = 0;
uint8_t alarm_minute = 0;

byte TRANSACTION_POINTER = TR_MODE_IDLE;
byte TR_COMMAND = CMD_TYPE_NONE;

#define TIME_BUFFER_MAX 4
char timeParsingIndex = 0;
char timeBuffer[4] ;

#define ALARM_TIME_BUFFER_MAX 3
char alarmTimeParsingIndex = 0;
char alarmTimeBuffer[3] ;


#endif
