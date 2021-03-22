#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <avr/interrupt.h>

ISR(PCINT0_vect)
{
    /* This is where you get when an interrupt is happening */
}

inline void PCIInit(void)
{
    /*Assumes that you are using PCINT0.
     *It is also known as PB0
     */
    // pinMode(PB0, INPUT_PULLUP);
    DDRB &= ~(1 << PB0); /* Set PB0 as input */
    PORTB |= (1 << PB0); /* Activate PULL UP resistor */

    PCMSK0 |= (1 << PCINT0); /* Enable PCINT0 */
    PCICR |= (1 << PCIE0);   /* Activate interrupt on enabled PCINT7-0 */
}

#endif
