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

int main(void)
{
    SystemInit();
    // The USB stack should be initialized last.
    HID_Init();
 
    for(;;)
    {
        if(true) { // tick tock 1ms
            // AppTick();
        }
        HIDTask();
    }
}
