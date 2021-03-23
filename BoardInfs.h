#ifndef __BOARD_INF_H__
#define __BOARD_INF_H__

#if (REAL_BOARD == Leonardo)
    #define MEM_SIZE 924
    #define LEDMASK_TX   LEDS_LED2
    #define LEDMASK_RX   LEDS_LED1
#elif (REAL_BOARD == TEENSY2pp)
    #define MEM_SIZE 924
    #define LEDMASK_TX   LEDS_LED1
    #define LEDMASK_RX   LEDS_LED1
#elif (REAL_BOARD == Teensy2)
    #define MEM_SIZE 924
    #define LEDMASK_TX   LEDS_LED1
    #define LEDMASK_RX   LEDS_LED1
#elif (REAL_BOARD == Beetle)
    #define MEM_SIZE 924
    #define LEDMASK_TX   LEDS_LED3
    #define LEDMASK_RX   LEDS_LED3
#elif (REAL_BOARD == UNO)
    #define MEM_SIZE 412
    #define LEDMASK_TX   LEDS_LED2
    #define LEDMASK_RX   LEDS_LED1
#endif

#endif