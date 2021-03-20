#include "System.h"

volatile uint8_t systick_ms = 0;
volatile uint16_t systickmillis = 0;

ISR(USART1_RX_vect) {
	// Serial_Task(Serial_ReceiveByte());
}
ISR (TIMER1_COMPA_vect)
{
    if(systickmillis == 1000) {
        systickmillis = 0;
    }
    systickmillis++;
}
ISR (TIMER0_OVF_vect) // timer0 overflow interrupt
{
    TCNT0 += 6; // add 6 to the register (our work around)

    systick_ms ^= 0x1;
    systickmillis++;
}

inline void timer0_init(void) {
    // set prescaler to 64 and start the timer
    TCCR0B |= (1 << CS01) | (1 << CS00);    // 16,000,000(F_CPU) / 64  = 250,000 Hz
    TCNT0 = 6;
    TIMSK0 |= (1 << TOIE0); // Initialize timer0 interrupt
}

inline void timer1_init(void) {
    // configurations for timer1
    TCNT1 = 0;  // set counter to 0.
    OCR1A = 15999;
    TCCR1B |= (1 << WGM12);  // use wave genreation
    TCCR1B |= (1 << CS10);   // use system clock
    TIMSK1 |= (1 << OCIE1A); // Timer/Counter 1, Output Compare A Match Interrupt Enable

    //TCCR0A |= (1<<WGM01);   //sets mode to CTC
    //OCR0A = 240;      // 250000 / 24 = 0.1ms
    //TIMSK0 |= (1<<OCIE0A);              //Output Compare Match A Interrupt Enable
}

inline void enable_rx_isr(void) {
	UCSR1B |= _BV(RXCIE1);
}

inline bool SystemTick1ms(void)
{
    // return systickmillis == 0;
    return systick_ms == 0;
}

inline bool SystemTick100ms(void)
{
    if (systickmillis % 100 == 0) {
        systickmillis = 0;
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

    cli();
    timer0_init();
    //timer1_init();
    sei();
    // We'll then enable global interrupts for our use.
    GlobalInterruptEnable();
}

void SystemInterruptInit(void)
{
    //
}
