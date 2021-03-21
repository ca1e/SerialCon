#ifndef SYSTEM_H
#define SYSTEM_H

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/power.h>

#include <stdbool.h>
#include <LUFA/Platform/Platform.h>

void SystemInit(void);
void SystemInterruptInit(void);

bool SystemTick1ms(void);
bool SystemTick100ms(void);

#endif