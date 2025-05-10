#include "clock.h"
#include "stm32f4xx.h"

//clock variables
static uint32_t APB1Clock = 25000000;
static uint32_t APB2Clock = 25000000;

static void enable_hse() {
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));
}

static void configure_voltage() {
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= (0b11 << PWR_CR_VOS_Pos);
}

static void set_flash_latency(uint32_t latency) {
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR |= latency;
}

static void configure_pll(uint8_t pllm, uint16_t plln, uint8_t pllp) {
    RCC->PLLCFGR = 0;
    RCC->PLLCFGR |= (pllm << RCC_PLLCFGR_PLLM_Pos);
    RCC->PLLCFGR |= (plln << RCC_PLLCFGR_PLLN_Pos);
    RCC->PLLCFGR |= (pllp << RCC_PLLCFGR_PLLP_Pos);
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
}

static void set_prescalers(AHBPrescaler ahb, APBPrescaler apb1, APBPrescaler apb2) {
    RCC->CFGR &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2);
    
    RCC->CFGR |= (ahb << RCC_CFGR_HPRE_Pos);
    RCC->CFGR |= (apb1 << RCC_CFGR_PPRE1_Pos);
    RCC->CFGR |= (apb2 << RCC_CFGR_PPRE2_Pos);
}

static void switch_sysclk_to_pll() {
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}

void clock_init(uint8_t pllm, uint16_t plln, uint8_t pllp,
                AHBPrescaler ahb_prescaler, APBPrescaler apb1_prescaler,
                APBPrescaler apb2_prescaler, uint32_t flash_latency) {

    enable_hse();
    configure_voltage();
    set_flash_latency(flash_latency);
    configure_pll(pllm, plln, pllp);
    set_prescalers(ahb_prescaler, apb1_prescaler, apb2_prescaler);
    switch_sysclk_to_pll();

    // Update system frequencies
    uint32_t hse_value = 25000000;  // External crystal = 25 MHz
    uint32_t vco = (hse_value / pllm) * plln;
    uint32_t pllp_div_factor = 2 * (pllp + 1);  // value which we will be dividing with (2,4,6,8)
    SystemCoreClock = vco / pllp_div_factor;
    
    // we shift it if needed (if not 1)
    uint32_t apb1_div = (apb1_prescaler == APB_DIV_1) ? 1 : (1 << ((apb1_prescaler & 0b111) - 3)); 
    uint32_t apb2_div = (apb2_prescaler == APB_DIV_1) ? 1 : (1 << ((apb2_prescaler & 0b111) - 3));
    

    APB1Clock = SystemCoreClock / apb1_div;
    APB2Clock = SystemCoreClock / apb2_div;
}

uint32_t get_apb1_clock() {
    return APB1Clock;
}

uint32_t get_apb2_clock() {
    return APB2Clock;
}
