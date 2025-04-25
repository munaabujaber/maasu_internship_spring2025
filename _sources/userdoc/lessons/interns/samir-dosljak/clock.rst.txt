===============
Lesson 2: Clock
===============

Clocks are periodic signals (usually square periodic signals) essential for the proper functioning of microcontrollers, and they determine how fast the microcontroller operates (the speed of execution of the microcontroller). One of the key terms related to the clock is RCC (Reset and Clock Control).

The RCC (Reset and Clock Control) is a peripheral that manages reset and control of the clock signals. Some of the registers within RCC are:

- **CR** (Control Register)
- **APB1ENR** (APB1 Peripheral Clock Enable Register)
- **PLLCFGR** (PLL Configuration Register)

CR (Control Register)
---------------------

The **CR** (Control Register) controls clock sources and oscillators. The following are the possible clock sources:

- **HSI** (High-Speed Internal): Internal RC oscillator, 16 MHz
- **HSE** (High-Speed External): External crystal oscillator, 4–26 MHz
- **LSI** (Low-Speed Internal): Internal 32 kHz RC oscillator
- **LSE** (Low-Speed External): External 32 kHz crystal used for RTC (Real-Time Clock)

Some of the important bits in the CR register are:

- **HSEBYP**: bit that enables bypassing the HSE crystal oscillator with an external clock
- **HSEON**: bit that enables the HSE clock
- **HSERDY**: status bit that indicates whether the HSE clock is ready

APB1ENR (APB1 Peripheral Clock Enable Register)
-----------------------------------------------

This register enables or disables the clock for peripherals connected to the APB1 bus.

**PWREN** is a bit in APB1ENR that enables or disables the clock of the power control module (power interface).

PLL (Phase-Locked Loop)
-----------------------

**PLL** (Phase-Locked Loop) is a system that increases the frequency of the input clock signal.  
**PLLCFGR** (PLL Configuration Register) configures the PLL by adjusting dividers and multipliers. A typical frequency of the output clock signal is 100 MHz.  
**VCO** (Voltage-Controlled Oscillator) is part of the PLL system.  
**PLLM** is the main divider of the input clock.  
**PLLN** is the multiplier for the VCO output.  
**PLLP** is the divider for the PLL output.  
**PLLQ** and **PLLI2S** are dividers used for USB and I2S configurations, respectively.

- **RCC_PLLCFGR_PLLM** is a bit mask for PLLM.
- **RCC_PLLCFGR_PLLM_Pos** is the bit position for PLLM within the **RCC_PLLCFGR** register.

- VCO clock = PLL input clock × (PLLN / PLLM)
- PLL output clock = VCO clock / PLLP

PWR (Power Control)
-------------------

**PWR** (Power Control) is a peripheral that manages the power consumption of the microcontroller.  
Within PWR, there is the **PWR_CR** register (Power Control Register), and within it, there is the **VOS** (Voltage Scaling) field, which regulates power consumption and performance through voltage control.

FLASH_ACR
---------

- **FLASH_ACR** is a register within the STM32 microcontroller responsible for managing flash memory.  
- **FLASH_ACR_LATENCY** is a field in `FLASH_ACR` (bits 0 to 3) that configures flash memory wait states.

Importance of Clock Initialization
----------------------------------

- Accuracy  
- Optimal performance  
- Power efficiency