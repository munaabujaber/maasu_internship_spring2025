#ifndef USART_H
#define USART_H

#include <stdint.h>

#define STM32F411xE
#include "stm32f4xx.h"

typedef enum {
    OVER8_16 = 0, // 16x oversampling
    OVER8_8  = 1  // 8x oversampling
    
} OversamplingMode;

void usart_init(
    USART_TypeDef* usart,
    uint32_t baud_rate,
    OversamplingMode over8
);

void usart_write(USART_TypeDef* usart, char data);
char usart_read(USART_TypeDef* usart);


#endif // USART_H
