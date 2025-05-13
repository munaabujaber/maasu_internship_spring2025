#ifndef USART_HPP
#define USART_HPP

#include "stm32f4xx.h"
#include <stdint.h>
#include "gpio.hpp"

enum class WordLength { Bits8, Bits9 };
enum class Parity { None, Even, Odd };

struct USART {
    USART_TypeDef* usart;
    GPIO_TypeDef* txPort;
    uint8_t txPin;
    GPIO_TypeDef* rxPort;
    uint8_t rxPin;

    void init(uint32_t baudRate,
              WordLength wl = WordLength::Bits8,
              Parity parity = Parity::None,
              bool halfDuplex = false);

    void send_char(char c);
    void send_string(const char* str);
    char receive_char();
};

#endif



