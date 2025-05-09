#include "stm32f4xx.h"

enum class Oversampling {
    By16 = 0,
    By8 = 1
};

enum class USARTPort {
    Usart1,
    Usart2,
    Usart6
};

struct USARTConfig {
    USARTPort usart;
    uint32_t baud_rate;
    Oversampling oversampling;
};

static USART_TypeDef* get_usart_instance(USARTPort port) {
    switch (port) {
        case USARTPort::Usart1: return USART1;
        case USARTPort::Usart2: return USART2;
        case USARTPort::Usart6: return USART6;
        default: return nullptr;
    }
}

static uint32_t calculate_pclk(USARTPort port) {
    uint32_t pclk = SystemCoreClock;

    if (port == USARTPort::Usart2) {
        uint32_t prescaler = ((RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos);
        prescaler = (prescaler < 4) ? 1 : (1 << (prescaler - 3)); // See RM0383 Table 16
        pclk = SystemCoreClock / prescaler;
    } else {
        uint32_t prescaler = ((RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos);
        prescaler = (prescaler < 4) ? 1 : (1 << (prescaler - 3));
        pclk = SystemCoreClock / prescaler;
    }

    return pclk;
}

void usart_init(const USARTConfig& cfg) {
    USART_TypeDef* usart = get_usart_instance(cfg.usart);
    if (!usart) while (1);

    if (cfg.usart == USARTPort::Usart1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (cfg.usart == USARTPort::Usart2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (cfg.usart == USARTPort::Usart6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    usart->CR1 &= ~USART_CR1_UE;

    if (cfg.oversampling == Oversampling::By8) {
        usart->CR1 |= USART_CR1_OVER8;
    } else {
        usart->CR1 &= ~USART_CR1_OVER8;
    }

    uint32_t pclk = calculate_pclk(cfg.usart);
    uint32_t usartdiv;
    if (cfg.oversampling == Oversampling::By8) {
        usartdiv = ((pclk * 2) + (cfg.baud_rate / 2)) / cfg.baud_rate;
    } else {
        usartdiv = (pclk + (cfg.baud_rate / 2)) / cfg.baud_rate;
    }
    usart->BRR = usartdiv;

    usart->CR1 |= USART_CR1_TE;
    usart->CR1 |= USART_CR1_UE;

    while (!(usart->SR & USART_SR_TC));
}

void usart_write_byte(USARTPort port, uint8_t data) {
    USART_TypeDef* usart = get_usart_instance(port);
    if (!usart) return;

    while (!(usart->SR & USART_SR_TXE));
    usart->DR = data;
    while (!(usart->SR & USART_SR_TC));
}
