#include <stdint.h>
#include <stdio.h>

//#define STM32F411xE
#include "stm32f4xx.h"

// main.cpp
// Entry point of the program

// Declare the initialization functions



extern void gpio_init(GPIO_TypeDef* GPIOx, uint32_t pin, uint32_t mode); //declares gpio_init() from gpio.cpp
extern void gpio_write(GPIO_TypeDef* GPIOx, uint32_t pin, uint8_t value);
extern void gpio_toggle(GPIO_TypeDef* GPIOx, uint32_t pin);

extern void clock_init(); //declares clock_init() from clock.cpp

extern void usart_init(USART_TypeDef* USARTx, uint32_t baudrate, uint8_t oversampling); //declares usart_init()
extern void usart_write_string(USART_TypeDef* USARTx, const char* str);


// Tick counter
uint32_t ticks{}; //used for SysTick timer

// SysTick timer, used for milisecond delays
void systick_handler()
{
    ticks++;
}

// Delay in milliseconds
// Wait delay using ticks variable
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

int main()
{
    // Set up clock and timer
    // 1. Initialize system clock
    clock_init();

    // 2. Configure SysTick for 1ms tick rate (SystemCoreClock = 100 MHz -> 100,000 ticks/ms)
    SysTick_Config(100000);
    __enable_irq();

    // Initialize GPIO for LED and USART for communication
    // 3. Initialize GPIOA pin 5 (output mode = 01)
    gpio_init(GPIOA, 5, 1);

    // 4. Initialize USART2 with baudrate 9600 and oversampling by 16
    usart_init(USART2, 9600, 16);
    usart_write_string(USART2, "USART Initialized.\r\n");


    // Blinks the LED and sends message via USART
    while (1)
    {
        // Toggle LED
        gpio_toggle(GPIOA, 5);
        delay_ms(500);

        // Send a message via USART
        usart_write_string(USART2, "Toggled LED\r\n");
    }
}
