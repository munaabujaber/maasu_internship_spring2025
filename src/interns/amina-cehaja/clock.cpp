// clock.cpp

#include "stm32f4xx.h"

// Initialize system clock using HSE and PLL configuration
void clock_init()
{
    // Enable HSE and wait until ready
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Enable power interface clock and set regulator voltage
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    // Set flash latency to 3 wait states
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // Configure PLL (HSE = 25 MHz, PLLN = 200, PLLP = 2)
    RCC->PLLCFGR = (25 << RCC_PLLCFGR_PLLM_Pos) |
                   (200 << RCC_PLLCFGR_PLLN_Pos) |
                   (0 << RCC_PLLCFGR_PLLP_Pos) |
                   RCC_PLLCFGR_PLLSRC_HSE;

    // Set APB1 prescaler to divide by 2
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    // Enable PLL and wait until ready
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL as system clock
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
