#include "stm32f4xx.h"
#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>

void gpio_init(GPIO_TypeDef *port, uint16_t pin, GPIO_Mode mode, GPIO_OType otype, GPIO_OSpeed ospeed, GPIO_PuPd pupd, GPIO_AF alternate_function)
{
    // Clock enabling for appropriate port
    if(port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if(port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if(port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if(port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if(port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if(port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;

    // Mode configuration
    port->MODER &= ~(3U << (pin * 2)); // reset mode
    port->MODER |= ((mode & 3) << (pin * 2)); // set new mode

    if(mode == GPIO_MODE_OUTPUT || mode == GPIO_MODE_AF) // Checking if pin is in output mode or alternate function mode
    {
        // Output type selection
        port->OTYPER &= ~(1U << pin); // reset output type (push-pull)
        port->OTYPER |= ((otype & 1) << pin); // set output type

        // outout speed configuration
        port->OSPEEDR &= ~(3U << (pin * 2)); // reset output speed
        port->OSPEEDR |= ((ospeed & 3) << (pin * 2)); // set output speed
    }

    // Input state selection
    port->PUPDR &= ~(3U << (pin * 2));
    port->PUPDR |= ((pupd & 3) << (pin * 2));

    // Alternate function selection (if GPIO is alternate function mode)
    if (mode == GPIO_MODE_AF)
    {
        if (pin <= 7)
        {
            port->AFR[0] &= ~(15U << (pin * 4));
            port->AFR[0] |= (alternate_function << (pin * 4));
        }
        else
        {
            port->AFR[1] &= ~(15U << ((pin - 8) * 4));
            port->AFR[1] |= (alternate_function << ((pin - 8) * 4));
        }
    }
}


bool gpio_read_pin(GPIO_TypeDef *port, uint16_t pin)
{
    return port->IDR & (1 << pin);
}

void gpio_write_pin(GPIO_TypeDef *port, uint16_t pin, bool value)
{
    if(value)
        port->BSRR = (1 << pin); // set
    else
        port->BSRR = (1 << (pin + 16)); // reset
}

uint16_t gpio_read_port(GPIO_TypeDef *port)
{
    return port->IDR;
}

void gpio_write_port(GPIO_TypeDef *port, uint16_t value)
{
    port->ODR = value;
}

void gpio_toggle(GPIO_TypeDef *port, uint16_t pin)
{
    port->ODR ^= (1 << pin);
}