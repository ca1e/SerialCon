#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <avr/interrupt.h>

#define read_bit(r,b) ((r) & (1u << (b)))
#define reset_bit(r,b) ((r) &= ~(1u << (b)))
#define set_bit(r,b) ((r) |= (1u << (b)))

inline void PCIInit(void)
{
    /*Assumes that you are using PCINT0.
     *It is also known as PB0
     */
    // pinMode(PB0, INPUT_PULLUP);
    reset_bit(DDRB, PB5);
    // DDRB &= ~(1 << PB0); /* Set PB0 as input */
    set_bit(PORTB, PB5);
    // PORTB |= (1 << PB0); /* Activate PULL UP resistor */
    PCMSK0 |= (1 << PCINT5); /* Enable PCINT5 */
    // Activate PCINT7-0
    PCICR |= (1 << PCIE0);   /* Activate interrupt on enabled PCINT7-0 */
}

#endif
