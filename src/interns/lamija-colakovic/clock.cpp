#include "clock.hpp"
#include "stm32f4xx.h"

void configure_clocks(const ClockConfig& config) {
    
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS; 

    if (config.useHSE) {
        RCC->CR |= RCC_CR_HSEON;
        if (config.bypassHSE) {
            RCC->CR |= RCC_CR_HSEBYP;
        }
        while (!(RCC->CR & RCC_CR_HSERDY));
    } else {
        RCC->CR |= RCC_CR_HSION;
        while (!(RCC->CR & RCC_CR_HSIRDY));
    }

    if (config.sysclkFreq <= 30000000)      FLASH->ACR = FLASH_ACR_LATENCY_0WS;
    else if (config.sysclkFreq <= 60000000) FLASH->ACR = FLASH_ACR_LATENCY_1WS;
    else if (config.sysclkFreq <= 90000000) FLASH->ACR = FLASH_ACR_LATENCY_2WS;
    else                                    FLASH->ACR = FLASH_ACR_LATENCY_3WS;

    RCC->PLLCFGR = 0;
    RCC->CR &= ~RCC_CR_PLLON;

    uint32_t pllm = config.useHSE ? (config.hseFreq / 1000000) : 16;
    uint32_t plln = (config.sysclkFreq / 1000000) * 2;
    uint32_t pllp = 0; 

    RCC->PLLCFGR |= (pllm & 0x3F)
                  | (plln << 6)
                  | (pllp << 16)
                  | (config.useHSE ? RCC_PLLCFGR_PLLSRC_HSE : 0);

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    RCC->CFGR = 0;
    if (config.apb1Freq < config.sysclkFreq)
        RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; 
    if (config.apb2Freq < config.sysclkFreq)
        RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; 

    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}



