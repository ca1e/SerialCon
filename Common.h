#ifndef _COMMON_H
#define _COMMON_H

#include <avr/eeprom.h>

//#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <LUFA/Drivers/Board/LEDs.h>
#include <LUFA/Drivers/Peripheral/Serial.h>
//#include <LUFA/Drivers/Board/Joystick.h>
//#include <LUFA/Drivers/Board/Buttons.h>

void CommonInit(void);

#endif