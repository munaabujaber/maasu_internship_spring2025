#include "stm32f4xx.h"
#include "clock.hpp"  

int32_t ticks{};

void systick_handler()
{
    ticks++;
}

void delay_ms(const uint32_t &ms)
{
    uint32_t start = ticks;
    uint32_t end = start + ms;

    // Check overflow
    if (end < start)
        while (ticks > start);

    // Wait for ticks to wrap around to zero
    while (ticks < end);
}

int main(void) {
    /*ClockConfig config;
    config.pll_n = 200;  
    config.pll_p = 2;    
    config.flash_latency = FlashLatency::_3ws; 
    config.voltage_scale = VoltageScale::Scale1; 

    clock_init(config);
    */
    
    clock_init_100MHz();
    SystemCoreClockUpdate();
    //100MHz / x = 1KHz
    SysTick_Config(100000);
    // Glavni loop sistema
    while (1) {
        
    }

    return 0;
}
