#ifndef _COMMON_H
#define _COMMON_H

#include <LUFA/Drivers/Board/LEDs.h>
#include <LUFA/Drivers/Peripheral/Serial.h>
//#include <LUFA/Drivers/Board/Joystick.h>
//#include <LUFA/Drivers/Board/Buttons.h>

#include "EasyCon.h"

#define Max(a, b) ((a > b) ? (a) : (b))
#define Min(a, b) ((a < b) ? (a) : (b))

#define LED_DURATION 50

// UART && LEDS Init
void CommonInit(void);
void BlinkLED(void);
void BlinkLEDTick(void);
void Serial_Send(const char DataByte);

#define TurnOnLED LEDs_TurnOnLEDs
#define TurnOffLED LEDs_TurnOffLEDs

#endif