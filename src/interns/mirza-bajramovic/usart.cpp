#include "usart.h"
#include "stm32f4xx.h"


static void enable_usart_clock(USART_TypeDef* usart) {
    if (usart == USART1) {
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    } else if (usart == USART2) {
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    } else if (usart == USART6) {
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    }
}

void usart_init(
    USART_TypeDef* usart,
    uint32_t baud_rate,
    uint32_t bus_clock,
    OversamplingMode over8
) {
    enable_usart_clock(usart);

    // Disable USART before configuring
    usart->CR1 &= ~USART_CR1_UE;

    // Set oversampling
    if (over8 == OVER8_8) {
        usart->CR1 |= USART_CR1_OVER8;
    } else {
        usart->CR1 &= ~USART_CR1_OVER8;
    }

    // Calculate USARTDIV and set baud rate
    double usartdiv;

    if (over8 == OVER8_8) {
        usartdiv = (double)bus_clock / (8 * baud_rate);
    } else {
        usartdiv = (double)bus_clock / (16 * baud_rate);
    }

    uint32_t mantissa = (uint32_t)usartdiv;
    //Multypling decimal part with 8 or 16
    uint32_t fraction = (uint32_t)((usartdiv - mantissa) * ((over8 == OVER8_8) ? 8 : 16));

    usart->BRR = (mantissa << 4) | (fraction & 0xF); //0xF to make sure we take lowest 4 bits

    // Enable transmitter and receiver
    usart->CR1 |= USART_CR1_TE | USART_CR1_RE;

    // Enable USART
    usart->CR1 |= USART_CR1_UE;
}

void usart_write(USART_TypeDef* usart, char data) {
    while (!(usart->SR & USART_SR_TXE)); // status registar, TXE empty
    usart->DR = (data & 0xFF); 
}

char usart_read(USART_TypeDef* usart) {
    while (!(usart->SR & USART_SR_RXNE));  // Wait until data is received

    return (char)(usart->DR & 0xFF);       // Read and return the data
}
