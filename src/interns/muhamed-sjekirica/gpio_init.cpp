#include "stm32f4xx.h"

// Enum for GPIO pin modes
enum class GPIOMode {
    Input = 0b00,
    Output = 0b01,
    AltFunc = 0b10,   // Alternate function (e.g. UART, SPI, etc.)
    Analog = 0b11
};

// Enum for output type
enum class GPIOOType {
    PushPull = 0,     // Standard output mode
    OpenDrain = 1     // Allows external pull-up
};

// Enum for output speed
enum class GPIOSpeed {
    Low = 0b00,
    Medium = 0b01,
    High = 0b10,
    VeryHigh = 0b11
};

// Enum for pull-up / pull-down resistor config
enum class GPIOPUPD {
    None = 0b00,       // No pull-up or pull-down
    PullUp = 0b01,     // Enable internal pull-up resistor
    PullDown = 0b10    // Enable internal pull-down resistor
};

// Configuration structure for initializing a GPIO pin
struct GPIOConfig {
    GPIO_TypeDef* port;      // GPIO port base address (GPIOA, GPIOB, etc.)
    uint8_t pin;             // Pin number (0 to 15)
    GPIOMode mode;           // Pin mode (input, output, alt func, analog)
    GPIOOType otype;         // Output type (push-pull or open-drain)
    GPIOSpeed speed;         // Output speed
    GPIOPUPD pupd;           // Pull-up / pull-down configuration
    uint8_t alt_func;        // Alternate function number (0 to 15), only used if mode is AltFunc
};

// Function to initialize a GPIO pin based on the configuration structure
void gpio_init(const GPIOConfig& cfg) {
    // Enable the clock for the GPIO port
    if (cfg.port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (cfg.port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (cfg.port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (cfg.port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (cfg.port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (cfg.port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    else while (1); // Invalid port passed, trap CPU here

    // Set the pin mode (Input, Output, Alternate Function, or Analog)
    cfg.port->MODER &= ~(0b11 << (cfg.pin * 2));  // Clear existing mode bits
    cfg.port->MODER |= (static_cast<uint32_t>(cfg.mode) << (cfg.pin * 2));  // Set new mode

    // Set the output type (Push-Pull or Open-Drain)
    cfg.port->OTYPER &= ~(1 << cfg.pin);  // Clear existing type
    cfg.port->OTYPER |= (static_cast<uint32_t>(cfg.otype) << cfg.pin);  // Set new type

    // Set the output speed
    cfg.port->OSPEEDR &= ~(0b11 << (cfg.pin * 2));  // Clear existing speed
    cfg.port->OSPEEDR |= (static_cast<uint32_t>(cfg.speed) << (cfg.pin * 2));  // Set speed

    // Set pull-up / pull-down resistor configuration
    cfg.port->PUPDR &= ~(0b11 << (cfg.pin * 2));  // Clear existing setting
    cfg.port->PUPDR |= (static_cast<uint32_t>(cfg.pupd) << (cfg.pin * 2));  // Set pull-up/down

    // If the mode is Alternate Function, configure AFR (Alternate Function Register)
    if (cfg.mode == GPIOMode::AltFunc) {
        uint32_t afr_index = cfg.pin / 8;             // AFR[0] for pins 0-7, AFR[1] for 8-15
        uint32_t afr_pos = (cfg.pin % 8) * 4;          // Each pin takes 4 bits
        cfg.port->AFR[afr_index] &= ~(0b1111 << afr_pos);           // Clear existing AF
        cfg.port->AFR[afr_index] |= (cfg.alt_func << afr_pos);      // Set new AF
    }
}
