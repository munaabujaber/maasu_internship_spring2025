#pragma once
#include "stm32f4xx.h"

class Clock {
public:
    static void init(uint32_t hse_freq, uint32_t pll_n, uint32_t pll_m, uint32_t pll_p = 2);
};
