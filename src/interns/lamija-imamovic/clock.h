#ifndef CLOCK_CONFIG_H
#define CLOCK_CONFIG_H

#include <cstdint>

// Prescaler options for AHB bus
enum class AHBPrescaler : uint8_t {
    DIV_1   = 0b0000,
    DIV_2   = 0b1000,
    DIV_4   = 0b1001,
    DIV_8   = 0b1010,
    DIV_16  = 0b1011,
    DIV_64  = 0b1100,
    DIV_128 = 0b1101,
    DIV_256 = 0b1110,
    DIV_512 = 0b1111
};

// Prescaler options for APB1 and APB2 buses
enum class APBPrescaler : uint8_t {
    DIV_1  = 0b000,
    DIV_2  = 0b100,
    DIV_4  = 0b101,
    DIV_8  = 0b110,
    DIV_16 = 0b111
};

// Retrieves the computed APB1 clock frequency
uint32_t getAPB1Clock();

// Retrieves the computed APB2 clock frequency
uint32_t getAPB2Clock();

// Initializes the system clock with specified PLL and prescaler settings
void initializeClock(uint8_t pllm, uint16_t plln, uint8_t pllp,
                     AHBPrescaler ahb, APBPrescaler apb1,
                     APBPrescaler apb2, uint32_t flashLatency);

#endif // CLOCK_CONFIG_H
