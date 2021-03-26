#pragma once

#if (REAL_BOARD == Leonardo)
    #include "pins/pins_leonardo.h"
#elif (REAL_BOARD == TEENSY2pp)
    #include "pins/pins_leonardo.h"
#endif

static inline void PINs_Init(void) {}