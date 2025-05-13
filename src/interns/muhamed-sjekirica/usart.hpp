#ifndef USART_HPP
#define USART_HPP

#include <cstdint>

// Enum za USART portove
enum class Oversampling {
    By16 = 0,
    By8 = 1
};

enum class USARTPort {
    Usart1,
    Usart2,
    Usart6
};

// Struktura za konfiguraciju USART-a
struct USARTConfig {
    USARTPort usart;      // Odabrani USART port (Usart1, Usart2, Usart6)
    uint32_t baud_rate;   // Baud rate
    Oversampling oversampling; // Odabir oversampling načina (By16 ili By8)
};

// Funkcija za inicijalizaciju USART-a
void usart_init(const USARTConfig& cfg);

// Funkcija za slanje jednog bajta preko USART-a
void usart_write_byte(USARTPort port, uint8_t data);

// Funkcija za čitanje jednog bajta sa USART-a
uint8_t usart_read_byte(USARTPort port);

#endif // USART_HPP
