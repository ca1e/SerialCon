#ifndef _COMMON_H
#define _COMMON_H

//#include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>

#include <LUFA/Drivers/Board/LEDs.h>
#include <LUFA/Drivers/Peripheral/Serial.h>
//#include <LUFA/Drivers/Board/Joystick.h>
//#include <LUFA/Drivers/Board/Buttons.h>

#define LED_DURATION 50

// UART && LEDS Init
void CommonInit(void);

#define TurnOnLED LEDs_TurnOnLEDs
#define TurnOffLED LEDs_TurnOffLEDs

#endif