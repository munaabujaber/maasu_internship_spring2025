#include "stm32f4xx.h"

void gpio_init(GPIO_TypeDef* GPIOx, uint32_t pin, uint32_t mode)
{
    if (GPIOx == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (GPIOx == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (GPIOx == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (GPIOx == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOx->MODER &= ~(3U << (pin * 2));
    GPIOx->MODER |= (mode << (pin * 2));
}

void gpio_write(GPIO_TypeDef* GPIOx, uint32_t pin, uint8_t value)
{
    if (value)
        GPIOx->ODR |= (1U << pin);
    else
        GPIOx->ODR &= ~(1U << pin);
}

void gpio_toggle(GPIO_TypeDef* GPIOx, uint32_t pin)
{
    GPIOx->ODR ^= (1U << pin);
}
