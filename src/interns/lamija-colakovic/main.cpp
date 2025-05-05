#include "stm32f4xx.h"
#include <stdint.h>

volatile uint32_t ticks = 0;
// SysTick handler (called every 1 ms)
void sysTick_handler() {
    ++ticks;
}
void delay(uint32_t ms) {
    uint32_t start = ticks;
    while ((ticks - start) < ms);
}
// ---------- Clock Init ----------
void clock_init() {
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}
// ---------- GPIOA pin 5 init (LED) ----------
void gpio_init() {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER &= ~(3 << (5 * 2));
    GPIOA->MODER |= (1 << (5 * 2)); // Output mode
}
// ---------- USART2 init ----------
void usart2_init(uint32_t baudRate) {
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // PA2 (TX), PA3 (RX)
    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (3 * 2)));
    GPIOA->MODER |= (2 << (2 * 2)) | (2 << (3 * 2));

    GPIOA->AFR[0] &= ~((0xF << (2 * 4)) | (0xF << (3 * 4)));
    GPIOA->AFR[0] |= (7 << (2 * 4)) | (7 << (3 * 4)); // AF7

    USART2->CR1 &= ~USART_CR1_UE;

    USART2->BRR = 16000000 / baudRate; // Assuming HSI = 16 MHz

    USART2->CR1 &= ~USART_CR1_M; // 8-bit
    USART2->CR1 &= ~USART_CR1_PCE; // no parity

    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable TX & RX
    USART2->CR1 |= USART_CR1_UE;
}

void usart2_send_char(char c) {
    while (!(USART2->SR & USART_SR_TXE));
    USART2->DR = c;
}

void usart2_send_string(const char* str) {
    while (*str) usart2_send_char(*str++);
}

// ---------- MAIN ----------
int main() {
    clock_init();
    

    gpio_init();
    usart2_init(9600);

    usart2_send_string("USART Initialized\r\n");

    while (1) {
        GPIOA->ODR ^= (1 << 5); // Toggle LED
        usart2_send_string("LED toggled\r\n");
        delay(1000); // 1 second delay
    }

    return 0;
}



