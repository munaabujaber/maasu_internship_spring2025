#include "stm32f4xx.h"

enum class FlashLatency {
    _0ws = 0,
    _1ws = 1,
    _2ws = 2,
    _3ws = 3,
    _4ws = 4,
    _5ws = 5,
    _6ws = 6,
    _7ws = 7
};

enum class VoltageScale {
    Scale3 = 0b00,
    Scale2 = 0b01,
    Scale1 = 0b11
};

struct ClockConfig {
    uint32_t pll_n;           // PLL multiplier
    uint32_t pll_p;           // PLL divider
    FlashLatency flash_latency;
    VoltageScale voltage_scale;
};

void clock_init(const ClockConfig& config) {
    // Validate PLL N value
    if (config.pll_n < 192 || config.pll_n > 432) {
        while (1); // Invalid PLL N value, enter infinite loop
    }

    // Validate PLL P value
    if (config.pll_p != 2 && config.pll_p != 4 && config.pll_p != 6 && config.pll_p != 8) {
        while (1); // Invalid PLL P value, enter infinite loop
    }

    // Enable power interface clock
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    // Set voltage scaling
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= (static_cast<uint32_t>(config.voltage_scale) << PWR_CR_VOS_Pos);

    // Configure flash latency
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR |= static_cast<uint32_t>(config.flash_latency);

    // Enable HSE
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Configure PLL
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    RCC->PLLCFGR |= ((25 << RCC_PLLCFGR_PLLM_Pos) |
                     (config.pll_n << RCC_PLLCFGR_PLLN_Pos) |
                     (config.pll_p << RCC_PLLCFGR_PLLP_Pos));

    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL as system clock source
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while (!(RCC->CFGR & RCC_CFGR_SW_PLL));

    // Configure AHB and APB prescalers
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
}



void clock_init_100MHz(void){//default clock initialization at 100MHz.
    //enable power interface clock
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    //set voltage scalling
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= 0b11 << PWR_CR_VOS_Pos;

    //configure flash latency
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    //enable HSE
    RCC->CR |= RCC_CR_HSEON;
    while(!(RCC->CR & RCC_CR_HSERDY));

    //configure PLL
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    RCC->PLLCFGR |= ((25 << RCC_PLLCFGR_PLLM_Pos) | (200 << RCC_PLLCFGR_PLLN_Pos));

    //enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY));

    //select PLL as sysclck source
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while(!(RCC->CFGR & RCC_CFGR_SW_PLL));

    //configure AHB prescaler
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
}



