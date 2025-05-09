#include "stm32f4xx.h"
#include <stdint.h>
void gpio_input_pa5() { // Function to configure PA5 as input with pull-up resistor
    // 1. Enable the clock for GPIOA peripheral
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // 2. Set PA5 mode to Input
    // Each GPIO pin has 2 bits in the MODER register
    GPIOA->MODER &= ~(0x3 << (5 * 2)); // 0b00: Input mode
    // 3. Configure pull-up/pull-down resistor
    GPIOA->PUPDR &= ~(0x3 << (5 * 2));
    // Set bit 10 = 1, bit 11 = 0 => 0b01: Pull-up enabled
    GPIOA->PUPDR |=  (0x1 << (5 * 2)); 
}
void gpio_output_pa5() {// Function to configure PA5 as general-purpose output
    // 1. Enable the clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // 2. Set PA5 to Output mode (0b01)
    GPIOA->MODER &= ~(0x3 << (5 * 2)); // Clear bits
    GPIOA->MODER |=  (0x1 << (5 * 2)); // Set to output mode
    // 3. Set output type to Push-pull (default)
    GPIOA->OTYPER &= ~(1 << 5); // Clear bit 5 (push-pull)
    // 4. Configure output speed to "Fast"
    // OSPEEDR: 2 bits per pin
    GPIOA->OSPEEDR &= ~(0x3 << (5 * 2)); // Clear speed bits
    GPIOA->OSPEEDR |=  (0x2 << (5 * 2)); // 0b10: Fast speed
    // 5. Disable pull-up/pull-down resistors (floating)
    GPIOA->PUPDR &= ~(0x3 << (5 * 2)); // 0b00: No pull
}
void gpio_af_pa5() {// Function to configure PA5 for alternate function (e.g. SPI1_SCK)
    // 1. Enable the clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    // 2. Set mode to Alternate Function (0b10)
    GPIOA->MODER &= ~(0x3 << (5 * 2)); // Clear mode bits
    GPIOA->MODER |=  (0x2 << (5 * 2)); // Alternate function
    // 3. Select the alternate function number in AFRL (PA5 is in AFR[0])
    GPIOA->AFR[0] &= ~(0xF << (5 * 4)); // Clear AF bits
    GPIOA->AFR[0] |=  (0x5 << (5 * 4)); // Set AF5
    // 4. Configure as Push-pull output
    GPIOA->OTYPER &= ~(1 << 5); // 0 = Push-pull
    // 5. Set speed to Fast
    GPIOA->OSPEEDR &= ~(0x3 << (5 * 2)); // Clear
    GPIOA->OSPEEDR |=  (0x2 << (5 * 2)); // Fast
    // 6. Disable pull-up/pull-down resistors
    GPIOA->PUPDR &= ~(0x3 << (5 * 2)); // No pull
}
void gpio_analog_pa5() {// Function to configure PA5 in analog mode
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |=  (0x3 << (5 * 2)); // Set bits to analog mode
    GPIOA->PUPDR &= ~(0x3 << (5 * 2)); 
}
