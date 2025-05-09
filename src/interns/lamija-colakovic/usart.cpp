#include "stm32f4xx.h"
#include <stdint.h>
// ---------- USART2 Configuration and Communication ----------
enum class WordLength { Bits8, Bits9 };
enum class Parity { None, Even, Odd };
/**
Initializes USART2 peripheral.
 @param baudRate   //Desired baud rate (e.g., 9600, 115200)
 @param wl         //Word length: 8 bits (default) or 9 bits
 @param parity     //Parity setting: None (default), Even, or Odd
 @param halfDuplex //If true, enables half-duplex communication mode
 */
void usart2_init(uint32_t baudRate, WordLength wl = WordLength::Bits8, Parity parity = Parity::None, bool halfDuplex = false) {
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;     // Enable clock for USART2 on APB1 bus
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;     // Enable GPIOA peripheral clock for PA2 and PA3
    // Configure PA2 and PA3 for alternate function mode (USART2 TX/RX)
    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (3 * 2)));  // Clear mode bits for PA2 and PA3
    GPIOA->MODER |= (2 << (2 * 2)) | (2 << (3 * 2));     // Set mode to '10' (Alternate function)
    GPIOA->AFR[0] |= (7 << (2 * 4)) | (7 << (3 * 4));     // Select AF7 (USART2) for PA2 and PA3
    USART2->CR1 &= ~USART_CR1_UE;    // Disable USART2 before configuring
    uint32_t uartdiv = 16000000 / baudRate;    // Peripheral clock is 16 MHz: USARTDIV = Fck / BaudRate
    USART2->BRR = uartdiv;
    // Configure word length
    if (wl == WordLength::Bits9)
        USART2->CR1 |= USART_CR1_M;          
    else
        USART2->CR1 &= ~USART_CR1_M;         
    // Configure parity
    if (parity == Parity::None) {
        USART2->CR1 &= ~USART_CR1_PCE;       // Disable parity
    } else {
        USART2->CR1 |= USART_CR1_PCE;        // Enable parity
        if (parity == Parity::Odd)
            USART2->CR1 |= USART_CR1_PS;     // Odd parity
        else
            USART2->CR1 &= ~USART_CR1_PS;    // Even parity
    }
    // Configure half-duplex mode
    if (halfDuplex)
        USART2->CR3 |= USART_CR3_HDSEL;      // Enable half-duplex
    else
        USART2->CR3 &= ~USART_CR3_HDSEL;     // Full duplex (default)


    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;   // Enable transmitter and receiver
    USART2->CR1 |= USART_CR1_UE;     // Enable USART2
}
//Send a single character via USART2.
void usart2_send_char(char c) {
    while (!(USART2->SR & USART_SR_TXE));    // Wait until transmit data register is empty
    USART2->DR = c;                          // Load data into transmit register
}
//Sends a null-terminated string via USART2.
void usart2_send_string(const char* str) {
    while (*str) usart2_send_char(*str++);   // Send characters one by one
}
//Receive a single character via USART2.
//Waits until a character is received.
char usart2_receive_char() {
    while (!(USART2->SR & USART_SR_RXNE));   // Wait until data is received
    return USART2->DR;                       // Read received data
}



