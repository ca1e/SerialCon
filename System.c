#include "System.h"

volatile uint8_t systick_ms = 0;

ISR(USART1_RX_vect) {
	// Serial_Task(Serial_ReceiveByte());
}

ISR (TIMER0_OVF_vect) // timer0 overflow interrupt
{
    // add 6 to the register (our work around)
    TCNT0 += 6;

    systick_ms = 1;
}

inline void enable_rx_isr(void) {
	UCSR1B |= _BV(RXCIE1);
}

inline bool SystemTick1ms(void)
{
    if (systick_ms == 1) {
        systick_ms = 0;
        return true;
    }

    return false;
}


void SystemInit(void)
{
    // We need to disable watchdog if enabled by bootloader/fuses.
    MCUSR &= ~(1 << WDRF);
    wdt_disable();
    // We need to disable clock division before initializing the USB hardware.
    clock_prescale_set(clock_div_1);

    // Initialize timer0 interrupt
    TIMSK0 |= (1 << TOIE0);
    // set prescaler to 64 and start the timer
    TCCR0B |= (1 << CS01) | (1 << CS00);

    SystemInterruptInit();
}

void SystemInterruptInit(void)
{
    //enable interrupts
    sei();

    GlobalInterruptEnable();
}
