#include <stdint.h>
#include "stm32f4xx.h"
#include "clock.cpp"
#include "gpio.cpp"
#include "usart.cpp"


// External declarations
extern void clock_init();
extern void gpio_init(GPIO_TypeDef* GPIOx, uint32_t pin, uint32_t mode);
extern void gpio_toggle(GPIO_TypeDef* GPIOx, uint32_t pin);
extern void usart_init(USART_TypeDef* USARTx, uint32_t baudrate, uint8_t oversampling);
extern void usart_write_string(USART_TypeDef* USARTx, const char* str);

volatile uint32_t ticks = 0;

extern "C" void SysTick_Handler()
{
    ticks++;
}

void delay_ms(uint32_t ms)
{
    uint32_t start = ticks;
    while ((ticks - start) < ms);
}

int main()
{
    clock_init();

    SysTick_Config(100000);  
    __enable_irq();

    gpio_init(GPIOA, 5, 1);  
    usart_init(USART2, 9600, 16);
    usart_write_string(USART2, "System started.\r\n");

    while (1)
    {
        gpio_toggle(GPIOA, 5);
        usart_write_string(USART2, "Toggled LED\r\n");
        delay_ms(500);
    }
}
