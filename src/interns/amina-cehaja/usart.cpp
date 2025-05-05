// usart.cpp

#include "stm32f4xx.h"

// Initialize USART with specified baud rate and oversampling
void usart_init(USART_TypeDef* USARTx, uint32_t baudrate, uint8_t oversampling)
{
    // Enable USART clock depending on instance
    if (USARTx == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (USARTx == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (USARTx == USART6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    // Disable USART during configuration
    USARTx->CR1 = 0;

    // Configure oversampling
    if (oversampling == 8)
        USARTx->CR1 |= USART_CR1_OVER8;
    else
        USARTx->CR1 &= ~USART_CR1_OVER8;

    // Determine USART clock based on bus
    uint32_t clk = (USARTx == USART2) ? 42000000 : 84000000;

    // Compute USARTDIV value
    uint32_t usartdiv = (oversampling == 8) ? (2 * clk + baudrate / 2) / baudrate : (clk + baudrate / 2) / baudrate;

    // Apply BRR formula based on oversampling
    if (oversampling == 8)
        USARTx->BRR = ((usartdiv & 0xFFF0) | ((usartdiv & 0x000F) >> 1));
    else
        USARTx->BRR = usartdiv;

    // Enable USART, transmitter and receiver
    USARTx->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}

// Sends a character over USART
void usart_write(USART_TypeDef* USARTx, char data)
{
    // Wait until transmit data register is empty
    while (!(USARTx->SR & USART_SR_TXE));
    USARTx->DR = data;
}

// Sends a string over USART
void usart_write_string(USART_TypeDef* USARTx, const char* str)
{
    while (*str)
    {
        usart_write(USARTx, *str++);
    }
}
