#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

enum AHBPrescaler {
    AHB_DIV_1   = 0b0000,
    AHB_DIV_2   = 0b1000,
    AHB_DIV_4   = 0b1001,
    AHB_DIV_8   = 0b1010,
    AHB_DIV_16  = 0b1011,
    AHB_DIV_64  = 0b1100,
    AHB_DIV_128 = 0b1101,
    AHB_DIV_256 = 0b1110,
    AHB_DIV_512 = 0b1111
};

enum APBPrescaler {
    APB_DIV_1  = 0b000,
    APB_DIV_2  = 0b100,
    APB_DIV_4  = 0b101,
    APB_DIV_8  = 0b110,
    APB_DIV_16 = 0b111
};
enum VoltageScale {
    SCALE_3 = 0b01,  
    SCALE_2 = 0b10,
    SCALE_1 = 0b11   // highest performance (up to 100 MHz)
};

enum PLLPFactor {
    PLLP_DIV_2 = 0b00,  // actual division factor = 2
    PLLP_DIV_4 = 0b01,  // actual division factor = 4
    PLLP_DIV_6 = 0b10,  // actual division factor = 6
    PLLP_DIV_8 = 0b11   // actual division factor = 8
};


uint32_t get_apb1_clock();
uint32_t get_apb2_clock();
uint32_t get_core_clock();

void clock_init(uint8_t pllm, uint16_t plln, uint8_t pllp,
                AHBPrescaler ahb_prescaler, APBPrescaler apb1_prescaler,
                APBPrescaler apb2_prescaler, uint32_t flash_latency,VoltageScale scale);



#endif // CLOCK_H
