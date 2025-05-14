#ifndef USART_H
#define USART_H

#include <stdint.h>
#include "stm32f4xx.h"

// USART oversampling modes
typedef enum {
    OVER8_16 = 0, // 16x oversampling (standard)
    OVER8_8  = 1  // 8x oversampling (higher baud rates)
} OversamplingMode;

/**
 * @brief Initializes the specified USART peripheral.
 * 
 * @param usart         Pointer to USART peripheral (e.g., USART2)
 * @param baud_rate     Desired baud rate (e.g., 9600)
 * @param bus_clock     Frequency of the USART's APB clock in Hz
 * @param over8         Oversampling mode (16x or 8x)
 */
void usart_init(
    USART_TypeDef* usart,
    uint32_t baud_rate,
    uint32_t bus_clock,
    OversamplingMode over8
);

/**
 * @brief Transmits a single character via USART.
 * 
 * @param usart Pointer to USART peripheral
 * @param data  Character to send
 */
void usart_write(USART_TypeDef* usart, char data);

/**
 * @brief Receives a single character via USART (blocking).
 * 
 * @param usart Pointer to USART peripheral
 * @return char Received character
 */
char usart_read(USART_TypeDef* usart);

#endif // USART_H
