#include "clock.hpp"
#include "gpio.hpp"
#include "usart.hpp"
#include "stm32f4xx.h"

uint32_t ticks{};


void SysTick_Handler() {
    ticks++;
}

void delay_ms(const uint32_t &ms) {
    uint32_t start = ticks;
    uint32_t end = start + ms;

    if (end < start) { // Overflow
        while (ticks > start);
    }

    while (ticks < end);
}

int main() {
    SystemCoreClockUpdate(); 


    SysTick_Config(SystemCoreClock / 1000);

    USART usart= { USART2, GPIOA, 2, GPIOA, 3 };


    usart.init(9600);
    gpio_init(GPIOA, 5, GPIOMode::Output);

    usart.send_string("USART2 ready\r\n");

    while (1) {
        gpio_toggle(GPIOA, 5);
        delay_ms(500); 
    }
}


