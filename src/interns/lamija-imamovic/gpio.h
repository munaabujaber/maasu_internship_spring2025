#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>


// Enumerations for Port, Mode, Output Type, and Speed
enum GPIOPort {
    PORTA = 0x40020000,
    PORTB = 0x40020400,
    PORTC = 0x40020800,
    PORTD = 0x40020C00,
    PORTE = 0x40021000,
    PORTH = 0x40021C00
};

enum GPIOMode {
    INPUT   = 0b00,
    OUTPUT  = 0b01,
    ALT     = 0b10,
    ANALOG  = 0b11
};

enum GPIOOutputType {
    PUSH_PULL  = 0b0,
    OPEN_DRAIN = 0b1
};

enum OutputSpeed {
    LOW_SPEED       = 0b00,
    MEDIUM_SPEED    = 0b01,
    HIGH_SPEED      = 0b10,
    VERY_HIGH_SPEED = 0b11
};
enum PullType {
    NO_PULL   = 0b00,
    PULL_UP   = 0b01,
    PULL_DOWN = 0b10
};


void gpio_mode(GPIOPort selected_port, GPIOMode mode, uint8_t pin);
void gpio_output_type(GPIOPort selected_port, GPIOOutputType output_type, uint8_t pin);
void gpio_output_speed(GPIOPort selected_port, OutputSpeed speed, uint8_t pin);
void gpio_pull_type(GPIOPort selected_port, PullType pull, uint8_t pin);
uint8_t gpio_read_pin(GPIOPort selected_port, uint8_t pin);

void gpio_write_pin(GPIOPort selected_port, uint8_t pin, uint8_t value);
void gpio_set_alternate_function(GPIOPort selected_port, uint8_t pin, uint8_t af);
void gpio_set_pin(GPIOPort selected_port, uint8_t pin);
void gpio_reset_pin(GPIOPort selected_port, uint8_t pin);

void gpio_init(GPIOPort selected_port, uint8_t pin,
    GPIOMode mode,
    GPIOOutputType output_type,
    OutputSpeed speed,
    PullType pull,
    uint8_t alternate_function);

#endif // GPIO_H