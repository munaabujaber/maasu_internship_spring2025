#include "usart.hpp"

void USART::init(USART_TypeDef* USARTx, uint32_t baudrate, uint8_t oversampling) {
    if (USARTx == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (USARTx == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (USARTx == USART6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    USARTx->CR1 = 0;  // Reset control register

    if (oversampling == 8)
        USARTx->CR1 |= USART_CR1_OVER8;
    else
        USARTx->CR1 &= ~USART_CR1_OVER8;

    uint32_t clk = (USARTx == USART2) ? 42000000 : 84000000;
    uint32_t usartdiv = (oversampling == 8)
        ? (2 * clk + baudrate / 2) / baudrate
        : (clk + baudrate / 2) / baudrate;

    USARTx->BRR = (oversampling == 8)
        ? ((usartdiv & 0xFFF0) | ((usartdiv & 0x000F) >> 1))
        : usartdiv;

    USARTx->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}

void USART::write(USART_TypeDef* USARTx, char c) {
    while (!(USARTx->SR & USART_SR_TXE));
    USARTx->DR = c;
}

void USART::writeString(USART_TypeDef* USARTx, const char* str) {
    while (*str) {
        write(USARTx, *str++);
    }
}
