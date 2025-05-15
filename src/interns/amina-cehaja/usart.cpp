#include "usart.hpp"

void USART::init(USART_TypeDef* USARTx, uint32_t baudrate, uint32_t clkHz, uint8_t oversampling) {
    // Enable clock for the selected USART peripheral
    if (USARTx == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (USARTx == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (USARTx == USART6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    USARTx->CR1 = 0; // Reset USART control register

    // Configure oversampling
    if (oversampling == 8)
        USARTx->CR1 |= USART_CR1_OVER8;
    else
        USARTx->CR1 &= ~USART_CR1_OVER8;

    // Calculate USARTDIV for baud rate generation
    uint32_t usartdiv = (oversampling == 8)
        ? (2 * clkHz + baudrate / 2) / baudrate
        : (clkHz + baudrate / 2) / baudrate;

    // Set baud rate register (BRR)
    USARTx->BRR = (oversampling == 8)
        ? ((usartdiv & 0xFFF0) | ((usartdiv & 0x000F) >> 1))
        : usartdiv;

    // Enable USART, Transmit, Receive
    USARTx->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}

void USART::write(USART_TypeDef* USARTx, char c) {
    while (!(USARTx->SR & USART_SR_TXE)); // Wait until transmit data register is empty
    USARTx->DR = c; // Write data
}

void USART::writeString(USART_TypeDef* USARTx, const char* str) {
    while (*str) {
        write(USARTx, *str++); // Send character-by-character
    }
}

char USART::read(USART_TypeDef* USARTx) {
    while (!(USARTx->SR & USART_SR_RXNE)); // Wait until data is received
    return USARTx->DR; // Return received character
}
