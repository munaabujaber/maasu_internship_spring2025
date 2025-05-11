#include "usart.hpp"
#include "stm32f4xx.h"

USARTDriver::USARTDriver(USART_TypeDef* usart, GPIO_TypeDef* txPort, uint8_t txPin,
                         GPIO_TypeDef* rxPort, uint8_t rxPin)
    : usart_(usart), txPort_(txPort), txPin_(txPin), rxPort_(rxPort), rxPin_(rxPin) {}

void USARTDriver::usart2_init(uint32_t baudRate, WordLength wl, Parity parity, bool halfDuplex) {
    if (usart_ == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (usart_ == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (usart_ == USART6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    if (txPort_ == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (txPort_ == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (txPort_ == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    txPort_->MODER &= ~(3 << (txPin_ * 2));
    txPort_->MODER |= (2 << (txPin_ * 2));
    txPort_->AFR[txPin_ / 8] |= (7 << ((txPin_ % 8) * 4));

    rxPort_->MODER &= ~(3 << (rxPin_ * 2));
    rxPort_->MODER |= (2 << (rxPin_ * 2));
    rxPort_->AFR[rxPin_ / 8] |= (7 << ((rxPin_ % 8) * 4));

    usart_->CR1 &= ~USART_CR1_UE;

    uint32_t uartdiv = 16000000 / baudRate;  
    usart_->BRR = uartdiv;

    if (wl == WordLength::Bits9) usart_->CR1 |= USART_CR1_M;
    else usart_->CR1 &= ~USART_CR1_M;

    if (parity == Parity::None) {
        usart_->CR1 &= ~USART_CR1_PCE;
    } else {
        usart_->CR1 |= USART_CR1_PCE;
        if (parity == Parity::Odd) usart_->CR1 |= USART_CR1_PS;
        else usart_->CR1 &= ~USART_CR1_PS;
    }

    if (halfDuplex) usart_->CR3 |= USART_CR3_HDSEL;
    else usart_->CR3 &= ~USART_CR3_HDSEL;

    usart_->CR1 |= USART_CR1_TE | USART_CR1_RE;
    usart_->CR1 |= USART_CR1_UE;
}

void USARTDriver::send_char(char c) {
    while (!(usart_->SR & USART_SR_TXE));
    usart_->DR = c;
}

void USARTDriver::usart2_send_string(const char* str) {
    while (*str) send_char(*str++);
}

char USARTDriver::receive_char() {
    while (!(usart_->SR & USART_SR_RXNE));
    return usart_->DR;
}
