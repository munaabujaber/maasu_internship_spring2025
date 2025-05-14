#include "clock.h"
#include "stm32f4xx.h"

// Internal variables for storing clock speeds
static uint32_t APB1Clock = 25000000;
static uint32_t APB2Clock = 25000000;

namespace {

void activateHSE() {
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));
}

void setupPowerControl() {
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= (0b11 << PWR_CR_VOS_Pos);
}

void configureFlash(uint32_t latency) {
    FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY) | latency;
}

void setupPLL(uint8_t pllm, uint16_t plln, uint8_t pllp) {
    RCC->PLLCFGR = 0;
    RCC->PLLCFGR |= (pllm << RCC_PLLCFGR_PLLM_Pos)
                 |  (plln << RCC_PLLCFGR_PLLN_Pos)
                 |  (pllp << RCC_PLLCFGR_PLLP_Pos)
                 |  RCC_PLLCFGR_PLLSRC_HSE;
}

void setBusPrescalers(AHBPrescaler ahb, APBPrescaler apb1, APBPrescaler apb2) {
    RCC->CFGR &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2);
    RCC->CFGR |= (ahb << RCC_CFGR_HPRE_Pos)
              |  (apb1 << RCC_CFGR_PPRE1_Pos)
              |  (apb2 << RCC_CFGR_PPRE2_Pos);
}

void switchToPLL() {
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}

} // anonymous namespace

void clock_init(uint8_t pllm, uint16_t plln, uint8_t pllp,
                AHBPrescaler ahb_prescaler, APBPrescaler apb1_prescaler,
                APBPrescaler apb2_prescaler, uint32_t flash_latency) {

    activateHSE();
    setupPowerControl();
    configureFlash(flash_latency);
    setupPLL(pllm, plln, pllp);
    setBusPrescalers(ahb_prescaler, apb1_prescaler, apb2_prescaler);
    switchToPLL();

    // Calculate frequencies
    constexpr uint32_t HSE_FREQ = 25000000;
    uint32_t vco = (HSE_FREQ / pllm) * plln;
    uint32_t pll_output_div = 2 * (pllp + 1);

    SystemCoreClock = vco / pll_output_div;

    uint32_t apb1_div = (apb1_prescaler == APB_DIV_1) ? 1 : (1U << ((apb1_prescaler & 0b111) - 3));
    uint32_t apb2_div = (apb2_prescaler == APB_DIV_1) ? 1 : (1U << ((apb2_prescaler & 0b111) - 3));

    APB1Clock = SystemCoreClock / apb1_div;
    APB2Clock = SystemCoreClock / apb2_div;
}

uint32_t get_apb1_clock() {
    return APB1Clock;
}

uint32_t get_apb2_clock() {
    return APB2Clock;
}
