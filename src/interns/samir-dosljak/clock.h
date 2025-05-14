#ifndef CLOCK_H
#define CLOCK_H

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    PLL_SRC_HSI = 0b0,
    PLL_SRC_HSE = 0b1
}PLL_Source;

typedef enum
{
    SYSCLK_SRC_HSI = 0b00,
    SYSCLK_SRC_HSE = 0b01,
    SYSCLK_SRC_PLL = 0b10
} SysClkSrc;

typedef enum
{
    APB_PRE_DIV1 = 0b000,
    APB_PRE_DIV2 = 0b100,
    APB_PRE_DIV4 = 0b101,
    APB_PRE_DIV8 = 0b110,
    APB_PRE_DIV16 = 0b111
} APB_Prescaler;

typedef enum
{
    AHB_PRE_DIV1 = 0b0000,
    AHB_PRE_DIV2 = 0b1000,
    AHB_PRE_DIV4 = 0b1001,
    AHB_PRE_DIV8 = 0b1010,
    AHB_PRE_DIV16 = 0b1011,
    AHB_PRE_DIV64 = 0b1100,
    AHB_PRE_DIV128 = 0b1101,
    AHB_PRE_DIV256 = 0b1110,
    AHB_PRE_DIV512 = 0b1111
} AHB_Prescaler;

typedef enum
{
    LATENCY_0WS = 0b0000,
    LATENCY_1WS = 0b0001,
    LATENCY_2WS = 0b0010,
    LATENCY_3WS = 0b0011,
    LATENCY_4WS = 0b0100,
    LATENCY_5WS = 0b0101,
    LATENCY_6WS = 0b0110,
    LATENCY_7WS = 0b0111,
    LATENCY_8WS = 0b1000,
    LATENCY_9WS = 0b1001,
    LATENCY_10WS = 0b1010,
    LATENCY_11WS = 0b1011,
    LATENCY_12WS = 0b1100,
    LATENCY_13WS = 0b1101,
    LATENCY_14WS = 0b1110,
    LATENCY_15WS = 0b1111
} FlashLatency;

typedef enum
{
    VOS_SCALE_3 = 0b01, // <= 64 MHz
    VOS_SCALE_2 = 0b10, // <= 84 MHz
    VOS_SCALE_1 = 0b11 // <= 100 MHz
} VoltageScale;

typedef enum
{
    PLLP_DIV2 = 0b00, // 2
    PLLP_DIV4 = 0b01, // 4
    PLLP_DIV6 = 0b10, // 6
    PLLP_DIV8 = 0b11  // 8
} PLLP_Divider;


void clock_init(bool hse_bypass, PLL_Source pll_src, SysClkSrc sys_clk_src, APB_Prescaler apb1_pre, APB_Prescaler apb2_pre, AHB_Prescaler ahb_pre, FlashLatency flash_latency, VoltageScale voltage_scale, uint32_t pllm, uint32_t plln, PLLP_Divider pllp);
void pll_source(PLL_Source pll_src);
void clock_source(SysClkSrc sys_clk_src);
void apb1_prescaler(APB_Prescaler apb1_pre);
void apb2_prescaler(APB_Prescaler apb2_pre);
void ahb_prescaler(AHB_Prescaler ahb_pre);
void set_flas_latency(FlashLatency flash_latency);
void pll_config(uint32_t pllm, uint32_t plln, PLLP_Divider pllp);
void set_voltage_scale(VoltageScale voltage_scale);

#endif