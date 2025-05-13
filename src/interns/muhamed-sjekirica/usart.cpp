#include "usart.hpp"
#include "stm32f4xx.h"

// Funkcija koja vraća pokazivač na odgovarajući USART registar na osnovu enumeracije porta
static USART_TypeDef* get_usart_instance(USARTPort port) {
    switch (port) {
        case USARTPort::Usart1: return USART1;
        case USARTPort::Usart2: return USART2;
        case USARTPort::Usart6: return USART6;
        default: return nullptr;
    }
}

// Funkcija za računanje frekvencije sabirnice (PCLK) za dati USART
static uint32_t calculate_pclk(USARTPort port) {
    uint32_t pclk = SystemCoreClock;  // Početno uzimamo sistemski takt

    // Ako je USART2, koristi se APB1 sabirnica
    if (port == USARTPort::Usart2) {
        uint32_t prescaler = ((RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos);
        prescaler = (prescaler < 4) ? 1 : (1 << (prescaler - 3));  // Prema tabeli iz reference (RM0383)
        pclk = SystemCoreClock / prescaler;
    } 
    // Za USART1 i USART6 koristi se APB2 sabirnica
    else {
        uint32_t prescaler = ((RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos);
        prescaler = (prescaler < 4) ? 1 : (1 << (prescaler - 3));
        pclk = SystemCoreClock / prescaler;
    }

    return pclk;
}

// Glavna funkcija za inicijalizaciju USART periferije
void usart_init(const USARTConfig& cfg) {
    USART_TypeDef* usart = get_usart_instance(cfg.usart);  // Dobij pokazivač na odgovarajući USART registar
    if (!usart) while (1);  // Ako je neuspešno, zaustavi se (fail-safe)

    // Uključi takovanje za odgovarajući USART 
    if (cfg.usart == USARTPort::Usart1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (cfg.usart == USARTPort::Usart2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (cfg.usart == USARTPort::Usart6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    usart->CR1 &= ~USART_CR1_UE;  // Isključi USART dok traje konfiguracija

    // Postavi oversampling metod (8x ili 16x)
    if (cfg.oversampling == Oversampling::By8) {
        usart->CR1 |= USART_CR1_OVER8;  // Postavi 8x oversampling
    } else {
        usart->CR1 &= ~USART_CR1_OVER8;  // Postavi 16x oversampling
    }

    // Izračunaj baudrate vrednost na osnovu PCLK i oversamplinga
    uint32_t pclk = calculate_pclk(cfg.usart);
    uint32_t usartdiv;
    if (cfg.oversampling == Oversampling::By8) {
        usartdiv = ((pclk * 2) + (cfg.baud_rate / 2)) / cfg.baud_rate;
    } else {
        usartdiv = (pclk + (cfg.baud_rate / 2)) / cfg.baud_rate;
    }
    usart->BRR = usartdiv;  // Postavi BRR registar (baudrate)

    usart->CR1 |= USART_CR1_TE;  // Uključi predajnik (transmit enable)
    usart->CR1 |= USART_CR1_UE;  // Uključi USART modul

    // Sačekaj dok se ne završi eventualni prethodni prenos (TC = Transmission Complete)
    while (!(usart->SR & USART_SR_TC));
}

// Funkcija za slanje jednog bajta preko odabranog USART porta
void usart_write_byte(USARTPort port, uint8_t data) {
    USART_TypeDef* usart = get_usart_instance(port);
    if (!usart) return;

    // Čekaj dok TXE (transmit data register empty) ne postane 1
    while (!(usart->SR & USART_SR_TXE));
    
    usart->DR = data;  // Upisivanje bajta u data register (pokreće slanje)

    // Čekaj dok se prenos u potpunosti ne završi (TC = transmission complete)
    while (!(usart->SR & USART_SR_TC));
}

// Funkcija za čitanje jednog bajta sa odabranog USART porta
uint8_t usart_read_byte(USARTPort port) {
    USART_TypeDef* usart = get_usart_instance(port);
    if (!usart) return 0;  // Ako port nije validan, vraća 0

    // Čekaj dok RXNE (receive data register not empty) ne postane 1
    while (!(usart->SR & USART_SR_RXNE));

    return static_cast<uint8_t>(usart->DR);  // Čitaj podatak sa data registera
}
