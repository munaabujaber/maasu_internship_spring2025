#ifndef USART_HPP
#define USART_HPP

#include <cstdint>
#include "stm32f4xx.h"

namespace USART {

void enableClock(USART_TypeDef* USARTx);
void configure(USART_TypeDef* USARTx, uint32_t baudRate, bool tx_enable = true, bool rx_enable = true);
void sendChar(USART_TypeDef* USARTx, char c);
void sendString(USART_TypeDef* USARTx, const char* str);
char receiveChar(USART_TypeDef* USARTx);
bool isTransmitEmpty(USART_TypeDef* USARTx);
bool isReceiveNotEmpty(USART_TypeDef* USARTx);

} // namespace USART

#endif // USART_HPP
