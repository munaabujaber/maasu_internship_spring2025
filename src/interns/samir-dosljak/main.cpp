#include <stdint.h>
#include <stdio.h>

#include "stm32f4xx.h"
#include "gpio.h"
#include "clock.h"
#include "usart.h"

uint32_t ticks{};

void systick_handler()
{
    ticks++;
}

void delay_ms(const uint32_t &ms)
{
    uint32_t start = ticks;
    uint32_t end = start + ms;

    // Check overflow
    if (end < start)
        while (ticks > start);

    // Wait for ticks to wrap around to zero
    while (ticks < end);
}

int main()
{
    // Enable interupts
    __enable_irq();

    clock_init(false, PLL_SRC_HSE, SYSCLK_SRC_PLL, APB_PRE_DIV2, APB_PRE_DIV1, AHB_PRE_DIV1, LATENCY_3WS, VOS_SCALE_1, 25, 400, PLLP_DIV4);
    // Config systick at 1khz = 1ms, our HSI (high speed internal oscillator = 100mhz/100khz = 1khz)
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000);
    gpio_init(GPIOC, 13, GPIO_MODE_OUTPUT, GPIO_OTYPE_PP, GPIO_OSPEED_LOW, GPIO_NO_PULL, GPIO_AF_0);
    gpio_init(GPIOA, 2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_LOW, GPIO_NO_PULL, GPIO_AF_7);
    gpio_init(GPIOA, 3, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_LOW, GPIO_NO_PULL, GPIO_AF_7);
    usart_init(USART2, 50000000, 9600, OVER16, USART_WORD_LENGTH_8, USART_PARITY_DIS, true, true);


    while(1)
    {
        // Write to pin
        gpio_toggle(GPIOC, 13);
        usart_write_char(USART2, 'a');
        delay_ms(1000);
    }

    return 0;
}