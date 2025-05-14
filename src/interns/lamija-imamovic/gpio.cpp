#include <stdint.h>
#include <stdio.h>

#define STM32F411xE
#include "stm32f4xx.h"
#include "gpio.h"

// Configures the pin mode (Input, Output, Alternate, Analog)
void gpio_set_mode(GPIOPort port_base, GPIOMode mode, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;

    // Clear existing mode (2 bits per pin)
    port->MODER &= ~(0b11 << (pin * 2));

    // Set new mode
    port->MODER |= (mode << (pin * 2));
}

// Sets the output type (Push-Pull or Open-Drain)
void gpio_set_output_type(GPIOPort port_base, GPIOOutputType type, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;

    port->OTYPER &= ~(1 << pin);
    port->OTYPER |= (type << pin);
}

// Sets output speed for the given pin
void gpio_set_speed(GPIOPort port_base, OutputSpeed speed, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;

    port->OSPEEDR &= ~(0b11 << (pin * 2));
    port->OSPEEDR |= (speed << (pin * 2));
}

// Configures internal pull-up/pull-down resistors
void gpio_set_pull(GPIOPort port_base, PullType pull_type, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;

    port->PUPDR &= ~(0b11 << (pin * 2));
    port->PUPDR |= (pull_type << (pin * 2));
}

// Reads the digital state of a pin (0 or 1)
uint8_t gpio_read(GPIOPort port_base, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;
    return (port->IDR & (1 << pin)) ? 1 : 0;
}

// Writes a digital value (0 or 1) to the pin
void gpio_write(GPIOPort port_base, uint8_t pin, uint8_t value) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;

    if (value)
        port->ODR |= (1 << pin);
    else
        port->ODR &= ~(1 << pin);
}

// Assigns an alternate function (AF0–AF15) to a pin
void gpio_select_alternate_function(GPIOPort port_base, uint8_t pin, uint8_t af_number) {
    if (pin > 15) return;

    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;

    if (pin < 8) {
        port->AFR[0] &= ~(0xF << (pin * 4));
        port->AFR[0] |= (af_number << (pin * 4));
    } else {
        port->AFR[1] &= ~(0xF << ((pin - 8) * 4));
        port->AFR[1] |= (af_number << ((pin - 8) * 4));
    }
}

// Atomically sets the pin to HIGH
void gpio_set(GPIOPort port_base, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;
    port->BSRR = (1 << pin);
}

// Atomically resets the pin to LOW
void gpio_reset(GPIOPort port_base, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) port_base;
    port->BSRR = (1 << (pin + 16));
}

// Unified GPIO initializer
void gpio_init(GPIOPort port_base, uint8_t pin,
               GPIOMode mode,
               GPIOOutputType output_type,
               OutputSpeed speed,
               PullType pull_type,
               uint8_t alternate_function) {

    gpio_set_mode(port_base, mode, pin);
    gpio_set_output_type(port_base, output_type, pin);
    gpio_set_speed(port_base, speed, pin);
    gpio_set_pull(port_base, pull_type, pin);

    if (mode == ALT) {
        gpio_select_alternate_function(port_base, pin, alternate_function);
    }
}
