#include "Common.h"

ISR(USART1_RX_vect)
{
    // Serial_Task(Serial_ReceiveByte());
}

void CommonInit(void)
{
    // Initialize serial port.
    Serial_Init(115200, false);
    // Initialize LEDs.
    LEDs_Init();
}