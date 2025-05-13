#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>
#include "stm32f4xx.h"

// Enumeracije za način rada pina, tip izlaza, brzinu i pull-up/pull-down konfiguraciju
enum class GPIOMode {
    Input = 0b00,      // Ulazni pin
    Output = 0b01,     // Izlazni pin
    AltFunc = 0b10,    // Alternativna funkcija (npr. UART, SPI, itd.)
    Analog = 0b11      // Analogni mod
};

enum class GPIOOType {
    PushPull = 0,      // Standardni izlaz (push-pull)
    OpenDrain = 1      // Open-drain izlaz (za vanjske pull-up otpornike)
};

enum class GPIOSpeed {
    Low = 0b00,        // Niska brzina
    Medium = 0b01,     // Srednja brzina
    High = 0b10,       // Visoka brzina
    VeryHigh = 0b11    // Vrlo visoka brzina
};

enum class GPIOPUPD {
    None = 0b00,       // Bez pull-up ili pull-down otpornika
    PullUp = 0b01,     // Interni pull-up otpornik
    PullDown = 0b10    // Interni pull-down otpornik
};

// Struktura za konfiguraciju jednog GPIO pina
struct GPIOConfig {
    GPIO_TypeDef* port;      // GPIO port (GPIOA, GPIOB, itd.)
    uint8_t pin;             // Broj pina (0 do 15)
    GPIOMode mode;           // Način rada pina
    GPIOOType otype;         // Tip izlaza (push-pull ili open-drain)
    GPIOSpeed speed;         // Brzina signala na pinu
    GPIOPUPD pupd;           // Pull-up / pull-down konfiguracija
    uint8_t alt_func;        // Broj alternativne funkcije (0 do 15)
};

// Funkcija za inicijalizaciju GPIO pina
void gpio_init(const GPIOConfig& cfg);

// Funkcija za upis logičke vrijednosti (true = 1, false = 0) na pin
void gpio_write(GPIO_TypeDef* port, uint8_t pin, bool value);

// Funkcija za čitanje trenutne logičke vrijednosti sa pina
bool gpio_read(GPIO_TypeDef* port, uint8_t pin);

#endif // GPIO_HPP
