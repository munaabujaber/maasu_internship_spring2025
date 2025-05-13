#include "clock.hpp"
#include "stm32f4xx.h"

// Funkcija za inicijalizaciju takta sa parametrima konfiguracije
void clock_init(const ClockConfig& config) {
    // Provjera da li je PLL_N unutar dozvoljenih granica
    if (config.pll_n < 192 || config.pll_n > 432) {
        // Ako nije, blokiraj dalji rad sistema (beskonačna petlja)
        while (1);
    }

    // Provjera da li je PLL_P validan (mora biti 2, 4, 6, ili 8)
    if (config.pll_p != 2 && config.pll_p != 4 && config.pll_p != 6 && config.pll_p != 8) {
        // Ako nije, blokiraj dalji rad sistema (beskonačna petlja)
        while (1);
    }

    // Omogućavanje takta za PWR (Power Control) periferiju, potrebnu za kontrolu napona
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    // Postavljanje naponske skale za procesor
    // Prvo brišemo prethodnu postavku naponske skale
    PWR->CR &= ~PWR_CR_VOS;
    // Zatim postavljamo novu naponsku skalu, na osnovu konfiguracije (Scale1, Scale2, Scale3)
    PWR->CR |= (static_cast<uint32_t>(config.voltage_scale) << PWR_CR_VOS_Pos);

    // Podešavanje Flash latencije
    // Brišemo prethodne vrednosti latencije u Flash registru
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    // Postavljamo novu latenciju prema vrijednosti u konfiguraciji (0WS, 1WS, 2WS, itd.)
    FLASH->ACR |= static_cast<uint32_t>(config.flash_latency);

    // Aktivacija HSE (High Speed External) oscilatora, koji se koristi za PLL
    // Ako je odabran bypass mod, omogućavamo bypass
    if (config.hse_bypass) {
        RCC->CR |= RCC_CR_HSEBYP;  // Omogućava HSE bypass mod 
    }
    RCC->CR |= RCC_CR_HSEON;
    // Čekanje da HSE oscilator postane stabilan
    while (!(RCC->CR & RCC_CR_HSERDY));
    
    // Podesavanje PLL sa novim vrednostima (PLL M, PLL N, PLL P)
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    // Postavljamo PLLM na 25, PLLN na vrednost iz konfiguracije, i PLLP na vrednost iz konfiguracije
    RCC->PLLCFGR |= ((25 << RCC_PLLCFGR_PLLM_Pos) |
                     (config.pll_n << RCC_PLLCFGR_PLLN_Pos) |
                     (config.pll_p << RCC_PLLCFGR_PLLP_Pos));

    // Aktivacija PLL
    RCC->CR |= RCC_CR_PLLON;
    // Čekanje da PLL postane stabilan
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Prebacivanje sistema na PLL kao izvor takta
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    // Čekanje da PLL postane aktivan izvor takta
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    // Postavljanje preddijelitelja za APB1 magistralu (div2 znači dijeljenje sa 2)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    // Postavljanje preddijelitelja za APB2 magistralu (div1 znači bez dijeljenja)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
}

// Funkcija za inicijalizaciju takta za 100 MHz (fiksni slučaj)
void clock_init_100MHz(void) {
    // Omogućavanje takta za PWR (Power Control) periferiju, potrebnu za kontrolu napona
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    // Postavljanje naponske skale na Scale1 (najviši nivo napona)
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= 0b11 << PWR_CR_VOS_Pos;

    // Podešavanje Flash latencije na 3WS (3 čekanja)
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // Aktivacija HSE oscilatora u bypass modu (fiksirano za ovaj slučaj)
    RCC->CR |= RCC_CR_HSEBYP;
    RCC->CR |= RCC_CR_HSEON;
    // Čekanje da HSE oscilator postane stabilan
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Podesavanje PLL sa vrednostima koje daju takt od 100 MHz
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    // Postavljamo PLLM na 25, PLLN na 200 (100 MHz izlaz), i PLLP na 2
    RCC->PLLCFGR |= ((25 << RCC_PLLCFGR_PLLM_Pos) | (200 << RCC_PLLCFGR_PLLN_Pos));
    RCC->PLLCFGR |= (0 << RCC_PLLCFGR_PLLP_Pos); // PLLP = 2

    // Aktivacija PLL
    RCC->CR |= RCC_CR_PLLON;
    // Čekanje da PLL postane stabilan
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Prebacivanje sistema na PLL kao izvor takta
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    // Čekanje da PLL postane aktivan izvor takta
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    // Postavljanje preddijelitelja za APB1 magistralu (div2 znači deljenje sa 2)
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    // Postavljanje preddijelitelja za APB2 magistralu (div1 znači bez dijeljenja)
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
}
