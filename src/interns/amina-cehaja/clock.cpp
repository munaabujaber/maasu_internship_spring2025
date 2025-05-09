#include "clock.hpp"

void Clock::init() {
    // Enable HSE and wait until it's ready
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Enable power interface clock and set voltage regulator scale
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    // Configure Flash latency
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // Configure PLL (25 MHz HSE -> 100 MHz SYSCLK)
    RCC->PLLCFGR = (25 << RCC_PLLCFGR_PLLM_Pos) |
                   (200 << RCC_PLLCFGR_PLLN_Pos) |
                   (0 << RCC_PLLCFGR_PLLP_Pos) |  // PLLP = 2
                   RCC_PLLCFGR_PLLSRC_HSE;

    // Set APB1 prescaler to divide by 2 (max 50 MHz)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    // Enable PLL and wait until ready
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL as system clock
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
