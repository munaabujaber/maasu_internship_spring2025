#include "gpio.hpp"
#include "stm32f4xx.h"
#include <stdint.h> 

void gpio_init(GPIO_TypeDef* port, uint8_t pin, GPIOMode mode,
    GPIOOutputType type,
    GPIOPull pull,
    GPIOSpeed speed) {
    
    if (port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    
    port->MODER &= ~(0b11 << (pin * 2));
    port->MODER |= (static_cast<uint32_t>(mode) << (pin * 2));

    port->OTYPER &= ~(1 << pin);
    port->OTYPER |= (static_cast<uint32_t>(type) << pin);

    port->PUPDR &= ~(0b11 << (pin * 2));
    port->PUPDR |= (static_cast<uint32_t>(pull) << (pin * 2));

    port->OSPEEDR &= ~(0b11 << (pin * 2));
    port->OSPEEDR |= (static_cast<uint32_t>(speed) << (pin * 2));
}

void gpio_set_alt_func(GPIO_TypeDef* port, uint8_t pin, uint8_t af) {
    uint8_t index = pin / 8;
    uint8_t shift = (pin % 8) * 4;
    port->AFR[index] &= ~(0xF << shift);
    port->AFR[index] |= (af << shift);
}

void gpio_write(GPIO_TypeDef* port, uint8_t pin, bool value) {
    if (value)
        port->BSRR = (1 << pin);  
    else
        port->BSRR = (1 << (pin + 16)); 
}

void gpio_toggle(GPIO_TypeDef* port, uint8_t pin) {
    port->ODR ^= (1 << pin);
}

bool gpio_read(GPIO_TypeDef* port, uint8_t pin) {
    return (port->IDR & (1 << pin));
}
