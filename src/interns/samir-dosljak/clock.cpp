#include "stm32f4xx.h"
#include "clock.h"
#include <stdint.h>
#include <stdbool.h>

void pll_source(PLL_Source pll_src)
{
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLSRC);
    RCC->PLLCFGR |= (pll_src << RCC_PLLCFGR_PLLSRC_Pos);
}

void clock_source(SysClkSrc sys_clk_src)
{
    RCC->CFGR &= ~(RCC_CFGR_SW);
    RCC->CFGR |= (sys_clk_src << RCC_CFGR_SW_Pos);
    if (sys_clk_src == SYSCLK_SRC_HSI)
        while (!(RCC->CFGR & RCC_CFGR_SWS_HSI));
    else if (sys_clk_src == SYSCLK_SRC_HSE)
        while (!(RCC->CFGR & RCC_CFGR_SWS_HSE));
    else if (sys_clk_src == SYSCLK_SRC_PLL)
        while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));
}

void apb1_prescaler(APB_Prescaler apb1_pre)
{
    RCC->CFGR &= ~(RCC_CFGR_PPRE1);
    RCC->CFGR &= ~(apb1_pre << RCC_CFGR_PPRE1_Pos);
}

void apb2_prescaler(APB_Prescaler apb2_pre)
{
    RCC->CFGR &= ~(RCC_CFGR_PPRE2);
    RCC->CFGR &= ~(apb2_pre << RCC_CFGR_PPRE2_Pos);
}

void ahb_prescaler(AHB_Prescaler ahb_pre)
{
    RCC->CFGR &= ~(RCC_CFGR_HPRE);
    RCC->CFGR &= ~(ahb_pre << RCC_CFGR_HPRE_Pos);
}

void set_flash_latency(FlashLatency flash_latency)
{
    FLASH->ACR &= ~(FLASH_ACR_LATENCY);
    FLASH->ACR |= (flash_latency << FLASH_ACR_LATENCY_Pos);
}

// PLLM: 2 - 63
// PLLN: 50 - 432
void pll_config(uint32_t pllm, uint32_t plln, PLLP_Divider pllp) 
{
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    RCC->PLLCFGR |= ((pllm << RCC_PLLCFGR_PLLM_Pos) | (plln << RCC_PLLCFGR_PLLN_Pos) | (pllp << RCC_PLLCFGR_PLLP_Pos));

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));
}

void set_voltage_scale(VoltageScale voltage_scale)
{
    PWR->CR &= ~(PWR_CR_VOS);
    PWR->CR |= (voltage_scale << PWR_CR_VOS_Pos);
}


void clock_init(bool hse_bypass, PLL_Source pll_src, SysClkSrc sys_clk_src, APB_Prescaler apb1_pre, APB_Prescaler apb2_pre, AHB_Prescaler ahb_pre, FlashLatency flash_latency, VoltageScale voltage_scale, uint32_t pllm, uint32_t plln, PLLP_Divider pllp)
{

    RCC->CR |= RCC_CR_HSEON;
    RCC->CR &= ~(RCC_CR_HSEBYP);
    if (hse_bypass)
        RCC->CR |= (1U << RCC_CR_HSEBYP_Pos);
    while (!(RCC->CR & RCC_CR_HSERDY));
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    set_voltage_scale(voltage_scale);
    set_flash_latency(flash_latency);
    pll_config(pllm, plln, pllp);
    apb1_prescaler(apb1_pre);
    apb2_prescaler(apb2_pre);
    ahb_prescaler(ahb_pre);
    pll_source(pll_src);
    clock_source(sys_clk_src);
}