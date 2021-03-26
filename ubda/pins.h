#pragma once

#if (REAL_BOARD == Leonardo)
    #include "leonardo/pins.h"
#elif (REAL_BOARD == TEENSY2pp)
    #include "leonardo/pins.h"
#endif

#if !defined(MEM_SIZE)
    #define MEM_SIZE      924
#endif
#if !defined(LEDMASK_TX)
    #define LEDMASK_TX      LEDS_LED2
#endif
#if !defined(LEDMASK_RX)
    #define LEDMASK_RX      LEDS_LED1
#endif

static inline void PINs_Init(void) {}