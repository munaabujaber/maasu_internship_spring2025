====================
Clock Initialization
====================
Clock initialization is a critical step in setting up an STM32 microcontroller to ensure accurate and efficient operation. 


RCC (Reset and Clock Control):

Manages reset and clock control, configuring system clocks and overseeing the reset circuitry within the STM32 microcontroller.

Registers:

CR (Control Register): Contains bits that control the clock sources and oscillators.

APB1ENR (APB1 Peripheral Clock Enable Register): Enables or disables clocks for peripherals connected to the APB1 bus.

Clock Sources:

HSI (High-Speed Internal): Internal clock, typically running at 8 MHz.

HSE (High-Speed External): External clock source, often used for higher accuracy.

LSI (Low-Speed Internal): Internal clock for low-power applications.

LSE (Low-Speed External): External clock, frequently used for RTC (Real-Time Clock) applications.

Bits and Configurations:

HSEBYP: Bit in CR allowing HSE oscillator bypass with an external clock.

HSEON: Bit in CR that enables the high-speed external oscillator.

HSERDY: Status bit in CR indicating whether the HSE oscillator is stable and ready.

Power Control:

PWREN: Bit in APB1ENR enabling the power control module’s clock.

VOS (Voltage Scaling): Configured in the Power Control Register (PWR_CR) to adjust voltage levels and performance. - Bit 14 (VOS_0): Highest performance, highest voltage. - Bit 15 (VOS_1): Medium performance, medium voltage.

Flash Configuration:

FLASH_ACR_LATENCY: Configures flash memory wait states; higher wait states support higher clock speeds (90-100 MHz with 3WS).

PLL (Phase-Locked Loop) Configuration:

PLLCFGR (PLL Configuration Register): Adjusts multipliers and dividers for the PLL to achieve a desired frequency. - PLLM: Main clock (HCLK) multiplier. - PLLN: Multiplier for the PLL output. - PLLP: Divider for the main clock output; also includes PLLQ and PLLI2S for USB and I2S configurations.

Example PLL Configuration

To configure the PLL, the following key bits in the RCC_PLLCFGR register are used:

    RCC_PLLCFGR_PLLM: Bit mask for PLLM.

    RCC_PLLCFGR_PLLM_Pos: Position of the PLLM bits within the register.

The clock calculation formula is:

        VCO clock = PLL input clock × (PLLN / PLLM)

        PLL general clock output = VCO clock / PLLP

2.2.4.4. Importance of Clock Initialization

Clock initialization serves several essential purposes:

    Accuracy: Ensures precise frequency, which is vital for timing-sensitive tasks.

    Performance: Allows the microcontroller to achieve optimal performance by properly configuring clock sources and the PLL.

    Power Efficiency: Effective clock configuration can reduce power usage, especially in low-power modes.