#ifndef GPIO_HPP
#define GPIO_HPP

#include <stdint.h>
#include "stm32f4xx.h"

enum class GPIOMode {
    Input     = 0b00,
    Output    = 0b01,
    AltFunc   = 0b10,
    Analog    = 0b11
};

enum class GPIOOutputType {
    PushPull  = 0,
    OpenDrain = 1
};

enum class GPIOPull {
    NoPull    = 0b00,
    PullUp    = 0b01,
    PullDown  = 0b10
};

enum class GPIOSpeed {
    Low       = 0b00,
    Medium    = 0b01,
    Fast      = 0b10,
    High      = 0b11
};

void gpio_init(GPIO_TypeDef* port, uint8_t pin, GPIOMode mode,
    GPIOOutputType type = GPIOOutputType::PushPull,
    GPIOPull pull = GPIOPull::NoPull,
    GPIOSpeed speed = GPIOSpeed::Low);

void gpio_set_alt_func(GPIO_TypeDef* port, uint8_t pin, uint8_t af);
void gpio_write(GPIO_TypeDef* port, uint8_t pin, bool value);
void gpio_toggle(GPIO_TypeDef* port, uint8_t pin);
bool gpio_read(GPIO_TypeDef* port, uint8_t pin);

#endif 

