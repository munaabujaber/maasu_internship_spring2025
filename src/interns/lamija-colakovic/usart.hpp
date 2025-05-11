#ifndef USART_HPP
#define USART_HPP

#include "stm32f4xx.h"
#include <cstdint>


enum class WordLength { Bits8, Bits9 };
enum class Parity { None, Even, Odd };

class USARTDriver {
public:
    USARTDriver(USART_TypeDef* usart, GPIO_TypeDef* txPort, uint8_t txPin,
                GPIO_TypeDef* rxPort, uint8_t rxPin);

    void usart2_init(uint32_t baudRate,
              WordLength wl = WordLength::Bits8,
              Parity parity = Parity::None,
              bool halfDuplex = false);

    void send_char(char c);
    void usart2_send_string(const char* str);
    char receive_char();

private:
    USART_TypeDef* usart_;
    GPIO_TypeDef* txPort_;
    uint8_t txPin_;
    GPIO_TypeDef* rxPort_;
    uint8_t rxPin_;
};

#endif
