#ifndef SYSTEM_H
#define SYSTEM_H

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/power.h>

#include <LUFA/Drivers/Peripheral/Serial.h>
#include <LUFA/Platform/Platform.h>

void SystemInit(void);

#endif