#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>
#include "stm32f4xx.h"

// Enumi za GPIO pin mode, output tip, speed i pull-up/pull-down konfiguraciju
enum class GPIOMode {
    Input = 0b00,
    Output = 0b01,
    AltFunc = 0b10,   // Alternate function (npr. UART, SPI, itd.)
    Analog = 0b11
};

enum class GPIOOType {
    PushPull = 0,     // Standard output mode
    OpenDrain = 1     // Omogućava spoljne pull-up otpornike
};

enum class GPIOSpeed {
    Low = 0b00,
    Medium = 0b01,
    High = 0b10,
    VeryHigh = 0b11
};

enum class GPIOPUPD {
    None = 0b00,       // Bez pull-up ili pull-down otpornika
    PullUp = 0b01,     // Omogući interni pull-up otpornik
    PullDown = 0b10    // Omogući interni pull-down otpornik
};

// Struktura za konfiguraciju GPIO pina
struct GPIOConfig {
    GPIO_TypeDef* port;      // GPIO port (GPIOA, GPIOB, itd.)
    uint8_t pin;             // Pin broj (0 do 15)
    GPIOMode mode;           // Pin mode (input, output, alt func, analog)
    GPIOOType otype;         // Output tip (push-pull ili open-drain)
    GPIOSpeed speed;         // Output speed
    GPIOPUPD pupd;           // Pull-up / pull-down konfiguracija
    uint8_t alt_func;        // Alternate function broj (0 do 15), koristi se samo ako je mode AltFunc
};

// Funkcija za inicijalizaciju GPIO pina na osnovu konfiguracione strukture
void gpio_init(const GPIOConfig& cfg);

#endif // GPIO_HPP
