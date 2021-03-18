/*
Nintendo Switch Fightstick - Proof-of-

Based on the LUFA library's Low-Level Joystick 
    (C) Dean 
Based on the HORI's Pokken Tournament Pro Pad 
    (C) 

This project implements a modified version of HORI's Pokken Tournament Pro 
USB descriptors to allow for the creation of custom controllers for 
Nintendo Switch. This also works to a limited degree on the PS3.

Since System Update v3.0.0, the Nintendo Switch recognizes the 
Tournament Pro Pad as a Pro Controller. Physical design limitations 
the Pokken Controller from functioning at the same level as the 
Controller. However, by de...fault most of the descriptors are there, with 
exception of Home and Capture. Descriptor modification allows us to 
these buttons for our use.
*/

#include "Joystick.h"

volatile uint8_t tick1000ms = 0;

int main(void)
{
    SystemInit();
    // The USB stack should be initialized last.
    HID_Init();
 
    while(1)
    {
        if(SystemTick1ms()) { // tick tock 1ms
            tick1000ms++;
        }
        if(tick1000ms == 500) {
            LEDs_TurnOffLEDs(LEDS_LED2);
        }
        if(tick1000ms == 1000) {
            tick1000ms = 0;
            LEDs_TurnOnLEDs(LEDS_LED2);
        }
        HID_Task();
        //ApplicationTask();
    }
}
