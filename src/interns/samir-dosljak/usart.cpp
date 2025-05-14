#include "stm32f4xx.h"
#include "usart.h"
#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>

void usart_init(USART_TypeDef *USARTx, uint32_t pclk, uint32_t baudrate, USART_Oversampling oversampling, USART_WordLength word_length, USART_Parity parity, bool tx_enable, bool rx_enable)
{
    // Disable USART
    USARTx->CR1 &= ~(USART_CR1_UE);
    
    // Enable peripheral clock
    if (USARTx == USART2)
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (USARTx == USART1)
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (USARTx == USART6)
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    //Oversampling

    float usartdiv;
    uint32_t mantissa;
    uint32_t fraction;

    USARTx->CR1 &= ~(USART_CR1_OVER8);
    if (oversampling == OVER8)
    {
        USARTx->CR1 |= USART_CR1_OVER8;
        usartdiv = (float)pclk / (8 * baudrate);
        mantissa = (uint32_t)usartdiv;
        fraction = (uint32_t)((usartdiv - mantissa) * 8 + 0.5f);
        if (fraction > 7)
        {
            mantissa += 1;
            fraction = 0;
        }
    }
    else
    {
        USARTx->CR1 &= ~(USART_CR1_OVER8);
        usartdiv = (float)pclk / (16 * baudrate);
        mantissa = (uint32_t)usartdiv;
        fraction = (uint32_t)((usartdiv - mantissa) * 16 + 0.5f);
        if (fraction > 15)
        {
            mantissa += 1;
            fraction = 0;
        }
    }

    USARTx->BRR = (mantissa << USART_BRR_DIV_Mantissa_Pos) | ((fraction & 0b1111) << USART_BRR_DIV_Fraction_Pos);

    // Word length
    if (word_length == USART_WORD_LENGTH_8)
        USARTx->CR1 &= ~(USART_CR1_M);
    else
        USARTx->CR1 |= USART_CR1_M;

    // Parity
    if (parity == USART_PARITY_DIS)
        USARTx->CR1 &= ~(USART_CR1_PCE);
    else
    {
        USARTx->CR1 |= USART_CR1_PCE;
        if (parity == USART_PARITY_EVEN)
            USARTx->CR1 &= ~(USART_CR1_PS);
        else
            USARTx->CR1 |= USART_CR1_PS;
    }

    // Enable transmitter
    if (tx_enable)
        USARTx->CR1 |= USART_CR1_TE;

    // Enable receiver
    if (rx_enable)
        USARTx->CR1 |= USART_CR1_RE;
    
    // Enable USART
        USARTx->CR1 |= USART_CR1_UE;
}

void usart_write_char(USART_TypeDef *USARTx, char c)
{
    while (!(USARTx->SR & USART_SR_TXE));
    USARTx->DR = c;
}

char usart_read_char(USART_TypeDef *USARTx)
{
    while (!(USARTx->SR & USART_SR_RXNE));
    return USARTx->DR;
}
void usart_write_string(USART_TypeDef *USARTx, const char *str)
{
    while (*str)
    {
        usart_write_char(USARTx, *str);
        str++;
    }
}