#include "usart.hpp"
#include "gpio.hpp"
#include "stm32f4xx.h"
void USART::init(uint32_t baudRate,
                       WordLength wl,
                       Parity parity,
                       bool halfDuplex) {
    
    if (usart == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (usart == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (usart == USART6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    
    if (txPort == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (txPort == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (txPort == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    if (rxPort != txPort) {
        if (rxPort == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
        else if (rxPort == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
        else if (rxPort == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    }

    
    gpio_init(txPort, txPin, GPIOMode::AltFunc, GPIOOutputType::PushPull, GPIOPull::NoPull, GPIOSpeed::High);
    gpio_set_alt_func(txPort, txPin, 7); // AF7 = USART1/2/3

    if (!halfDuplex) {
        gpio_init(rxPort, rxPin, GPIOMode::AltFunc, GPIOOutputType::PushPull, GPIOPull::NoPull, GPIOSpeed::High);
        gpio_set_alt_func(rxPort, rxPin, 7);
    }


    usart->CR1 &= ~USART_CR1_UE;


    constexpr uint32_t pclk = 100'000'000;
    usart->BRR = (pclk + baudRate / 2) / baudRate;

    
    if (wl == WordLength::Bits9) usart->CR1 |= USART_CR1_M;
    else usart->CR1 &= ~USART_CR1_M;

    
    if (parity == Parity::None) {
        usart->CR1 &= ~USART_CR1_PCE;
    } else {
        usart->CR1 |= USART_CR1_PCE;
        if (parity == Parity::Odd) usart->CR1 |= USART_CR1_PS;
        else usart->CR1 &= ~USART_CR1_PS;
    }


    if (halfDuplex) usart->CR3 |= USART_CR3_HDSEL;
    else usart->CR3 &= ~USART_CR3_HDSEL;

    
    usart->CR1 |= USART_CR1_TE | USART_CR1_RE;


    usart->CR1 |= USART_CR1_UE;
}

void USART::send_char(char c) {
    while (!(usart->SR & USART_SR_TXE));
    usart->DR = c;
}

void USART::send_string(const char* str) {
    while (*str) send_char(*str++);
}

char USART::receive_char() {
    while (!(usart->SR & USART_SR_RXNE));
    return usart->DR;
}





