#include <stdint.h>
#include <stdio.h>

#include "gpio.h"

#define STM32F411xE
#include "stm32f4xx.h"



void gpio_mode(GPIOPort selected_port, GPIOMode mode, uint8_t pin){

    //Creating a pointer named port 
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;

    //clearing, 2 bits
    port->MODER &= ~(0b11 << (pin*2));

    //seting the mode
    //2 bits per pin ( moder10 -> pin=10, bits: 20,21)
    port->MODER |=  (mode << (pin*2));

}

void gpio_output_type(GPIOPort selected_port, GPIOOutputType output_type, uint8_t pin) {
    
    //Kreiramo pokazivac port
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;

    //clearing, po 1 bit 
    port->OTYPER &= ~(1 << pin);

    //postavljanje output typea
    port->OTYPER |= (output_type << pin);

}

void gpio_output_speed(GPIOPort selected_port, OutputSpeed speed, uint8_t pin) {
        
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;
    port->OSPEEDR &= ~(0b11 << (pin * 2));
    port->OSPEEDR |= (speed << (pin * 2));
}

void gpio_pull_type(GPIOPort selected_port, PullType pull, uint8_t pin) {

    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;

    port->PUPDR &= ~(0b11 << (pin * 2));    
    
    port->PUPDR |=  (pull << (pin * 2));        
}

uint8_t gpio_read_pin(GPIOPort selected_port, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;

    // Read the IDR, check if the bit is set 
    return (port->IDR & (1 << pin)) ? 1 : 0; //1 for high, 0 for low
}

void gpio_write_pin(GPIOPort selected_port, uint8_t pin, uint8_t value) {

    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;

    if (value) {
        // Set the bit
        port->ODR |= (1 << pin);
    } else {
        // Clear the bit
        port->ODR &= ~(1 << pin);
    }
}
void gpio_set_alternate_function(GPIOPort selected_port, uint8_t pin, uint8_t af) {
   

    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;

    if (pin < 8) {
        // AFRL pins 0–7, 4 bits
        port->AFR[0] &= ~(0xF << (pin * 4));  // clear
        port->AFR[0] |= (af << (pin * 4)); // set
    } else {
        // Use AFRH pins 8–15, 4 bits
        port->AFR[1] &= ~(0xF << ((pin - 8) * 4));  // clear
        port->AFR[1] |= (af << ((pin - 8) * 4)); // set
    }
}

void gpio_set_pin(GPIOPort selected_port, uint8_t pin) {
    
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;
    port->BSRR = (1 << pin); // set pin atomically
}

void gpio_reset_pin(GPIOPort selected_port, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;
    port->BSRR = (1 << (pin + 16)); // plus 16 bc of upper half, reset pin atomically
}

void gpio_init(GPIOPort selected_port, uint8_t pin,
    GPIOMode mode,
    GPIOOutputType output_type,
    OutputSpeed speed,
    PullType pull,
    uint8_t alternate_function) {

    gpio_mode(selected_port, mode, pin);
    gpio_output_type(selected_port, output_type, pin);
    gpio_output_speed(selected_port, speed, pin);
    gpio_pull_type(selected_port, pull, pin);

    if (mode == ALT)    gpio_set_alternate_function(selected_port, pin, alternate_function);

}
void gpio_toggle_pin(GPIOPort selected_port, uint8_t pin) {
    GPIO_TypeDef* port = (GPIO_TypeDef*) selected_port;
    port->ODR ^= (1 << pin);
}







