#include "gpio.hpp"
#include "stm32f4xx.h"

void gpio_init(const GPIOConfig& cfg) {
    // Omogući clock za odgovarajući GPIO port
    if (cfg.port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (cfg.port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (cfg.port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (cfg.port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (cfg.port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (cfg.port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    else while (1); // Nevalidan port, zaustavi CPU

    // Postavi pin mode (Input, Output, Alternate Function, Analog)
    cfg.port->MODER &= ~(0b11 << (cfg.pin * 2));  // Očisti postojeće bitove
    cfg.port->MODER |= (static_cast<uint32_t>(cfg.mode) << (cfg.pin * 2));  // Postavi novi mode

    // Postavi output tip (Push-Pull ili Open-Drain)
    cfg.port->OTYPER &= ~(1 << cfg.pin);  // Očisti postojeći tip
    cfg.port->OTYPER |= (static_cast<uint32_t>(cfg.otype) << cfg.pin);  // Postavi novi tip

    // Postavi output speed
    cfg.port->OSPEEDR &= ~(0b11 << (cfg.pin * 2));  // Očisti postojeće postavke
    cfg.port->OSPEEDR |= (static_cast<uint32_t>(cfg.speed) << (cfg.pin * 2));  // Postavi brzinu

    // Postavi pull-up / pull-down otpornik
    cfg.port->PUPDR &= ~(0b11 << (cfg.pin * 2));  // Očisti postojeće postavke
    cfg.port->PUPDR |= (static_cast<uint32_t>(cfg.pupd) << (cfg.pin * 2));  // Postavi pull-up/pull-down

    // Ako je mode Alternate Function, konfiguriraj AFR (Alternate Function Register)
    if (cfg.mode == GPIOMode::AltFunc) {
        uint32_t afr_index = cfg.pin / 8;             // AFR[0] za pinove 0-7, AFR[1] za 8-15
        uint32_t afr_pos = (cfg.pin % 8) * 4;          // Svaki pin zauzima 4 bita
        cfg.port->AFR[afr_index] &= ~(0b1111 << afr_pos);           // Očisti postojeći AF
        cfg.port->AFR[afr_index] |= (cfg.alt_func << afr_pos);      // Postavi novi AF
    }
}
