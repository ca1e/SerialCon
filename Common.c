#include "Common.h"

volatile uint8_t led_ms = 0;

ISR(USART1_RX_vect)
{
    // Serial_Task(Serial_ReceiveByte());
}

inline void disable_rx_isr(void) {
	UCSR1B &= ~_BV(RXCIE1);
}

inline void enable_rx_isr(void) {
	UCSR1B |= _BV(RXCIE1);
}

void CommonInit(void)
{
    // Initialize serial port.
    Serial_Init(115200, false);
        enable_rx_isr();
    // Initialize LEDs.
    LEDs_Init();
}

void BlinkLED(void)
{
    led_ms = LED_DURATION;
    TurnOnLED(LEDMASK_TX);
}

void Serial_Send(const char DataByte)
{
    Serial_SendByte(DataByte);
    BlinkLED();
}