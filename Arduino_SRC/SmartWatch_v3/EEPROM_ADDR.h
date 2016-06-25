#ifndef EEPROM_ADDR_H
#define EEPROM_ADDR_H

/**EEPROM addresses

0-3   sun
4-7   mon
8-11  tue
12-15 wed
16-19 thu
20-23 fri
24-27 sat


#define addStp 28 //address to store number of steps
#define addCal 32 //address to store number of calories 
#define addKm  36 //address to store number of km 

#define addHeight 40
#define addAge    41
#define addGender 42
#define addWeight 43
#define addName   44  //10 byte char Array

#define addDRVnum 54 //Number of effects
#define addDRVeffects 55 //effect ids

**/

#endif
