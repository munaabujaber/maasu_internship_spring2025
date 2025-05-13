#include "gpio.hpp"
#include "stm32f4xx.h"

// Funkcija za inicijalizaciju GPIO pina na osnovu konfiguracije
void gpio_init(const GPIOConfig& cfg) {
    // Omogući takt za odgovarajući GPIO port
    if (cfg.port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (cfg.port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (cfg.port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (cfg.port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (cfg.port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (cfg.port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    else while (1); // Nevažeći port – zaustavi CPU

    // Postavi način rada pina (Input, Output, Alternate Function, Analog)
    cfg.port->MODER &= ~(0b11 << (cfg.pin * 2));  // Očisti prethodne vrijednosti
    cfg.port->MODER |= (static_cast<uint32_t>(cfg.mode) << (cfg.pin * 2));  // Postavi novi mod

    // Postavi tip izlaza (Push-Pull ili Open-Drain)
    cfg.port->OTYPER &= ~(1 << cfg.pin);  // Očisti prethodni tip
    cfg.port->OTYPER |= (static_cast<uint32_t>(cfg.otype) << cfg.pin);  // Postavi novi tip

    // Postavi brzinu signala na pinu
    cfg.port->OSPEEDR &= ~(0b11 << (cfg.pin * 2));  // Očisti prethodnu postavku
    cfg.port->OSPEEDR |= (static_cast<uint32_t>(cfg.speed) << (cfg.pin * 2));  // Postavi novu brzinu

    // Postavi pull-up ili pull-down otpornik
    cfg.port->PUPDR &= ~(0b11 << (cfg.pin * 2));  // Očisti prethodnu postavku
    cfg.port->PUPDR |= (static_cast<uint32_t>(cfg.pupd) << (cfg.pin * 2));  // Postavi novu

    // Ako je odabrana alternativna funkcija, postavi AFR registre
    if (cfg.mode == GPIOMode::AltFunc) {
        uint32_t afr_index = cfg.pin / 8;        // AFR[0] za pinove 0-7, AFR[1] za 8-15
        uint32_t afr_pos = (cfg.pin % 8) * 4;     // Svaki pin koristi 4 bita
        cfg.port->AFR[afr_index] &= ~(0b1111 << afr_pos);           // Očisti prethodni AF
        cfg.port->AFR[afr_index] |= (cfg.alt_func << afr_pos);      // Postavi novi AF
    }
}

// Funkcija za upis logičke vrijednosti (0 ili 1) na dati pin
void gpio_write(GPIO_TypeDef* port, uint8_t pin, bool value) {
    if (value) {
        port->BSRR = (1 << pin);  // Postavi pin na visoki nivo (1)
    } else {
        port->BSRR = (1 << (pin + 16));  // Postavi pin na niski nivo (0)
    }
}

// Funkcija za čitanje trenutne logičke vrijednosti sa pina
bool gpio_read(GPIO_TypeDef* port, uint8_t pin) {
    return (port->IDR & (1 << pin)) != 0;  // Vrati true ako je nivo visok, false ako je nizak
}
