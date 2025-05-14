#include <stdint.h>
#include "clock.h"
#include "gpio.h"
#include "usart.h"
#include "stm32f4xx.h"

int main() {
    // Configure the system clock to 100 MHz using a 25 MHz external crystal
    clock_init(
        25,        // PLLM
        200,       // PLLN
        0,         // PLLP (÷2, gives 100 MHz)
        AHB_DIV_1, // AHB prescaler
        APB_DIV_2, // APB1 prescaler
        APB_DIV_1, // APB2 prescaler
        FLASH_ACR_LATENCY_3WS // Flash latency for 100 MHz
    );

    // Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Initialize PA5 as output for LED (high speed, push-pull, no pull-up/down)
    gpio_init(PORTA, 5, OUTPUT, PUSH_PULL, HIGH_SPEED, NO_PULL, 0);

    // Initialize PA2 as USART2_TX and PA3 as USART2_RX with AF7
    gpio_init(PORTA, 2, ALT, PUSH_PULL, HIGH_SPEED, NO_PULL, 7);
    gpio_init(PORTA, 3, ALT, PUSH_PULL, HIGH_SPEED, NO_PULL, 7);

    // Initialize USART2 on APB1 with baud rate 9600 and 16x oversampling
    usart_init(USART2, 9600, get_apb1_clock(), OVER8_16);

    // Send a startup message
    const char* msg = "Start\n";
    for (const char* p = msg; *p != '\0'; ++p) {
        usart_write(USART2, *p);
    }

    // Main loop
    while (1) {
        // Toggle PA5 LED
        GPIOA->ODR ^= (1 << 5);

        // Send heartbeat over USART2
        usart_write(USART2, '.');

        // Delay loop (crude timing)
        for (volatile int i = 0; i < 100000; i++);
    }

    return 0;
}
