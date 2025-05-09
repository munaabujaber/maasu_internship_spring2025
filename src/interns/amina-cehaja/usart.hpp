#pragma once
#include "stm32f4xx.h"

class USART {
public:
    static void init(USART_TypeDef* USARTx, uint32_t baudrate, uint8_t oversampling = 16);
    static void write(USART_TypeDef* USARTx, char c);
    static void writeString(USART_TypeDef* USARTx, const char* str);
};
