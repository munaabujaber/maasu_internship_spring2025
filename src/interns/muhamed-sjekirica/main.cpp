#include "stm32f4xx.h"
#include "clock.hpp"  

int main(void) {
    ClockConfig config;
    config.pll_n = 200;  
    config.pll_p = 2;    
    config.flash_latency = FlashLatency::_3ws; 
    config.voltage_scale = VoltageScale::Scale1; 

    clock_init(config);

    // Alternativno, pozivanje fiksne funkcije za 100MHz
    // clock_init_100MHz();

    // Glavni loop sistema
    while (1) {
        
    }

    return 0;
}
