#include "clock.hpp"
#include "gpio.hpp"
#include "usart.hpp"
#include "stm32f4xx.h"

int main() {
    SystemCoreClockUpdate();     

    USARTDriver usart2(
        USART2, GPIOA, 2,        
        GPIOA, 3                  
    );

    usart2.usart2_init(9600);                     
    gpio_init(GPIOA, 5, GPIOMode::Output);          
    usart2.usart2_send_string("USART2 ready\r\n");  

    while (1) {
        gpio_toggle(GPIOA, 5);
        for (volatile int i = 0; i < 1000000; i++);
    }
}

