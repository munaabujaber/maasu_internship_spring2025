#include "gpio.hpp"

void GPIO::enableClock(GPIO_TypeDef* GPIOx) {
    if (GPIOx == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (GPIOx == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (GPIOx == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (GPIOx == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (GPIOx == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (GPIOx == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
}

void GPIO::configurePin(GPIO_TypeDef* GPIOx, uint32_t pin, Mode mode,
                        OutputType outputType, Pull pull, Speed speed, uint8_t altFunc) {
    // Set mode
    GPIOx->MODER &= ~(3U << (pin * 2));
    GPIOx->MODER |= (static_cast<uint32_t>(mode) << (pin * 2));

    // Set output type
    GPIOx->OTYPER &= ~(1U << pin);
    GPIOx->OTYPER |= (static_cast<uint32_t>(outputType) << pin);

    // Set pull-up/pull-down
    GPIOx->PUPDR &= ~(3U << (pin * 2));
    GPIOx->PUPDR |= (static_cast<uint32_t>(pull) << (pin * 2));

    // Set speed
    GPIOx->OSPEEDR &= ~(3U << (pin * 2));
    GPIOx->OSPEEDR |= (static_cast<uint32_t>(speed) << (pin * 2));

    // Set alternate function if needed
    if (mode == Mode::AltFunc) {
        uint32_t afr_index = pin / 8;
        uint32_t afr_offset = (pin % 8) * 4;
        GPIOx->AFR[afr_index] &= ~(0xF << afr_offset);
        GPIOx->AFR[afr_index] |= (altFunc << afr_offset);
    }
}

void GPIO::writePin(GPIO_TypeDef* GPIOx, uint32_t pin, bool state) {
    if (state)
        GPIOx->BSRR = (1U << pin);
    else
        GPIOx->BSRR = (1U << (pin + 16));
}