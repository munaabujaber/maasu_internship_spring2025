#include "stm32f4xx.h"
#include <stdint.h>

 //Enables the High-Speed External (HSE) clock (e.g., external crystal oscillator).
void enable_hse_clock() {
    RCC->CR |= RCC_CR_HSEON;                       // Enable HSE oscillator
    while (!(RCC->CR & RCC_CR_HSERDY));            // Wait until HSE is ready (stable)
}

//Configures Flash memory latency (wait states) for higher clock speeds.
//Required when SYSCLK > 30 MHz.
void configure_flash_latency() {
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;           // Set 3 wait states (for 100 MHz < SYSCLK <= 120 MHz)
    // Note: 3WS is needed for 100 MHz+ (refer to STM32F4 datasheet for exact values)
}
 //Configures the PLL (Phase Locked Loop) to multiply the HSE clock.
 //Here, HSE = 8 MHz → PLLM = 25, PLLN = 200, PLLP = 2
 //SYSCLK = (HSE / PLLM) * PLLN / PLLP = (8 / 25) * 200 / 2 = 64 MHz

void configure_pll() {
    RCC->PLLCFGR = (25 << RCC_PLLCFGR_PLLM_Pos) |  // PLLM = 25
                   (200 << RCC_PLLCFGR_PLLN_Pos) | // PLLN = 200
                   (0 << RCC_PLLCFGR_PLLP_Pos)  |  // PLLP = 00 → division factor = 2
                   RCC_PLLCFGR_PLLSRC_HSE;         // Use HSE as PLL source

    RCC->CR |= RCC_CR_PLLON;                       // Enable the PLL
    while (!(RCC->CR & RCC_CR_PLLRDY));            // Wait until PLL is locked
}

//Switches the system clock source to the PLL output.
void switch_to_pll() {
    RCC->CFGR |= RCC_CFGR_SW_PLL;                  // Select PLL as system clock
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); // Wait for switch to complete
}

 //Main clock initialization sequence:
 //enable power interface clock, configure voltage scaling, configure Flash latency, configure and enable PLL, switch system clock source to PLL

void clock_init() {
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;             // Enable power interface clock
    PWR->CR |= PWR_CR_VOS;                         // Set voltage regulator to scale 1 (for high performance)

    enable_hse_clock();                            // Turn on HSE oscillator
    configure_flash_latency();                     // Set wait states for Flash
    configure_pll();                               // Set PLL configuration
    switch_to_pll();                               // Use PLL as system clock
}


