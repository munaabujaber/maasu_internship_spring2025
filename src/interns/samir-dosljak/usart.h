#ifndef USART_H
#define USART_H

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    OVER16 = 0,
    OVER8 = 1
}USART_Oversampling;

typedef enum
{
    USART_WORD_LENGTH_8 = 0,
    USART_WORD_LENGTH_9 = 1
}USART_WordLength;

typedef enum
{
    USART_PARITY_DIS = 0,
    USART_PARITY_EVEN,
    USART_PARITY_ODD
}USART_Parity;

void usart_init(USART_TypeDef *USARTx, uint32_t pclk, uint32_t baudrate, USART_Oversampling oversampling, USART_WordLength word_length, USART_Parity parity, bool tx_enable, bool rx_enable);
void usart_write_char(USART_TypeDef *USARTx, char c);
char usart_read_char(USART_TypeDef *USARTx);
void usart_write_string(USART_TypeDef *USARTx, const char *str);

#endif