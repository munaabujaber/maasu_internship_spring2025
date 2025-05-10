#include <stdint.h>
#include "clock.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx.h"

int main() {
    // Initialize system clock to 100 MHz (using 25 MHz external crystal)
    clock_init(
        25,       // PLLM
        200,      // PLLN
        0,        // PLLP (÷2 → gives 100 MHz)
        AHB_DIV_1,
        APB_DIV_2,
        APB_DIV_1,
        FLASH_ACR_LATENCY_3WS
    );

    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure PA5 (LED) as output, push-pull, high speed, no pull
    gpio_init(PORTA, 5, OUTPUT, PUSH_PULL, HIGH_SPEED, NO_PULL, 0);

    // Configure PA2 (USART2 TX) and PA3 (USART2 RX) as alternate function AF7
    gpio_init(PORTA, 2, ALT, PUSH_PULL, HIGH_SPEED, NO_PULL, 7);
    gpio_init(PORTA, 3, ALT, PUSH_PULL, HIGH_SPEED, NO_PULL, 7);

    // Initialize USART2 (on APB1) with baud rate 9600, 16x oversampling
    // get_apb1_clock() is calculated APB1 clock from clock_init
    usart_init(USART2,9600,get_apb1_clock(),OVER8_16);

    //Send startup message
    usart_write(USART2, 'S');
    usart_write(USART2, 't');
    usart_write(USART2, 'a');
    usart_write(USART2, 'r');
    usart_write(USART2, 't');
    usart_write(USART2, '\n');

    while (1) {
        // Toggle PA5 (LED)
        GPIOA->ODR ^= (1 << 5);

        // Send a dot over USART2
        usart_write(USART2, '.');

        //delay loop 
        for (volatile int i = 0; i < 100000; i++);
    }

    return 0;
}
