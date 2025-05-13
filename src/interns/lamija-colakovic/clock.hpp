#ifndef CLOCK_HPP
#define CLOCK_HPP
#include "stm32f4xx.h"
#include <cstdint>

struct ClockConfig {
    bool useHSE;            
    bool bypassHSE;           
    uint32_t hseFreq;         
    uint32_t sysclkFreq;      
    uint32_t apb1Freq;       
    uint32_t apb2Freq;       
    float supplyVoltage;      
};

void configure_clocks(const ClockConfig& config);

#endif 
