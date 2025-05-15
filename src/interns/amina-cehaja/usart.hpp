#pragma once
#include "stm32f4xx.h"

class USART {
public:
    // Initialize USART with given clock frequency, baud rate, and oversampling
    static void init(USART_TypeDef* USARTx, uint32_t baudrate, uint32_t clkHz, uint8_t oversampling = 16);

    // Send a single character
    static void write(USART_TypeDef* USARTx, char c);

    // Send a string
    static void writeString(USART_TypeDef* USARTx, const char* str);

    // Read a single character
    static char read(USART_TypeDef* USARTx);
};

