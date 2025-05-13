#include <stdint.h>
#include <stdio.h>
#include "clock.h"
#include "gpio.h"
#include "usart.h"

#define STM32F411xE
#include "stm32f4xx.h"


uint32_t ticks{};

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

int main() {
     // Config systick at 1khz = 1ms, our HSI (high speed internal oscillator = 8mhz/8khz = 1khz)
     SysTick_Config(get_core_clock() / 1000);  // 1ms tick
     // Enable interupts
     __enable_irq();
 
    // Init pin here (instantiate gpio object with needed GPIO port and pin)
    // We will be using the same port and pin as an example: GPIOA and pin 5
    // Set mode
    // Initialize system clock to 100 MHz (using 25 MHz external crystal)
    clock_init(
        25,       // PLLM
        200,      // PLLN
        0,        // PLLP (÷2 → gives 100 MHz)
        AHB_DIV_1,
        APB_DIV_2,
        APB_DIV_1,
        FLASH_ACR_LATENCY_3WS,
        SCALE_1
    );

    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure PA5 (LED) as output, push-pull, high speed, no pull
    gpio_init(PORTA, 5, OUTPUT, PUSH_PULL, HIGH_SPEED, NO_PULL, 0);

    // Configure PA2 (USART2 TX) and PA3 (USART2 RX) as alternate function AF7
    gpio_init(PORTA, 2, ALT, PUSH_PULL, HIGH_SPEED, NO_PULL, 7);
    gpio_init(PORTA, 3, ALT, PUSH_PULL, HIGH_SPEED, NO_PULL, 7);

    // Initialize USART2 (on APB1) with baud rate 9600, 16x oversampling
    usart_init(USART2,9600,OVER8_16);

    //Send startup message
    usart_write(USART2, 'S');
    usart_write(USART2, 't');
    usart_write(USART2, 'a');
    usart_write(USART2, 'r');
    usart_write(USART2, 't');
    usart_write(USART2, '\n');

    while (1) {
        
        gpio_toggle_pin(PORTA, 5); // Toggle PA5 (LED)
       
        usart_write(USART2, '.');  // Send a dot over USART2

        delay_ms(500);
    }

    return 0;
}
