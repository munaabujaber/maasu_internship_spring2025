#include "usart.h"
#include "stm32f4xx.h"

// Enable peripheral clock for specified USART instance
static void enable_usart_clock(USART_TypeDef* usart) {
    if (usart == USART1) {
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    } else if (usart == USART2) {
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    } else if (usart == USART6) {
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    }
}

// Initialize USART with given parameters
void usart_init(
    USART_TypeDef* usart,
    uint32_t baud_rate,
    uint32_t bus_clock,
    OversamplingMode over8
) {
    // Enable USART peripheral clock
    enable_usart_clock(usart);

    // Disable USART before making configuration changes
    usart->CR1 &= ~USART_CR1_UE;

    // Set oversampling mode (8 or 16)
    if (over8 == OVER8_8) {
        usart->CR1 |= USART_CR1_OVER8;
    } else {
        usart->CR1 &= ~USART_CR1_OVER8;
    }

    // Compute USARTDIV
    double divisor = (over8 == OVER8_8) ?
        ((double)bus_clock / (8 * baud_rate)) :
        ((double)bus_clock / (16 * baud_rate));

    uint32_t mantissa = (uint32_t)divisor;
    uint32_t fraction = (uint32_t)((divisor - mantissa) * ((over8 == OVER8_8) ? 8 : 16));

    // Set baud rate register (BRR)
    usart->BRR = (mantissa << 4) | (fraction & 0xF);

    // Enable transmitter and receiver
    usart->CR1 |= USART_CR1_TE | USART_CR1_RE;

    // Enable USART module
    usart->CR1 |= USART_CR1_UE;
}

// Send a single character over USART
void usart_write(USART_TypeDef* usart, char data) {
    while (!(usart->SR & USART_SR_TXE));  // Wait for transmit buffer to be empty
    usart->DR = (data & 0xFF);            // Send lower 8 bits
}

// Receive a single character from USART
char usart_read(USART_TypeDef* usart) {
    while (!(usart->SR & USART_SR_RXNE)); // Wait for data to be received
    return (char)(usart->DR & 0xFF);      // Return received data
}
