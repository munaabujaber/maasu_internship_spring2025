====================================

Clock initialization

====================================

Clock initialization is a critical step in setting up an STM32 microcontroller to ensure accurate and efficient operation.
Key terms:

-RCC(Reset and Clock Control)-RCC manages reset and clock control,configuring system clocks and overseeing the reset circutry within the microcontroller.
-Registers:
        CR (Control Register): Contains bits that control the clock sources and oscillators.
        APB1ENR (APB1 Peripheral Clock Enable Register): Enables or disables clocks for peripherals connected to the APB1 bus.
-Clock Sources:
        HSI (High-Speed Internal): Internal clock, typically running at 8 MHz.
        HSE (High-Speed External): External clock source, often used for higher accuracy.
        LSI (Low-Speed Internal): Internal clock for low-power applications.
        LSE (Low-Speed External): External clock, frequently used for RTC (Real-Time Clock) applications.
-Bits and Configurations:
        HSEBYP: Bit in CR allowing HSE oscillator bypass with an external clock.
        HSEON: Bit in CR that enables the high-speed external oscillator.
        HSERDY: Status bit in CR indicating whether the HSE oscillator is stable and ready.
-Power Control:
        PWREN: Bit in APB1ENR enabling the power control module’s clock.
        VOS (Voltage Scaling): Configured in the Power Control Register (PWR_CR) to adjust voltage levels and performance. 
-Flash Configuration:
        FLASH_ACR_LATENCY: Configures flash memory wait states; higher wait states support higher clock speeds (90-100 MHz with 3WS).
-PLL (Phase-Locked Loop) Configuration:

        PLLCFGR (PLL Configuration Register): Adjusts multipliers and dividers for the PLL to achieve a desired frequency. - PLLM: Main clock (HCLK) multiplier. - PLLN: Multiplier for the PLL output. - PLLP: Divider for the main clock output; also includes PLLQ and PLLI2S for USB and I2S configurations.


Clock initialization serves several essential purposes:
    Accuracy: Ensures precise frequency, which is vital for timing-sensitive tasks.
    Performance: Allows the microcontroller to achieve optimal performance by properly configuring clock sources and the PLL.
    Power Efficiency: Effective clock configuration can reduce power usage, especially in low-power modes.

Proper clock initialization establishes a reliable foundation for effective microcontroller operation.

====================================

Reset and Clock Control(RCC)
-3 types of reset:system reset,power reset and backup domain reset.

A system reset sets all registers to their reset values except the reset flags in the clock
controller CSR register and the registers in the Backup domain.
A power reset sets all registers to their reset values except the Backup domain.
The backup domain reset sets all RTC registers and the RCC_BDCR register to their reset
values.

Three different clock sources can be used to drive the system clock (SYSCLK):
  HSI oscillator clock
  HSE oscillator clock
  Main PLL (PLL) clock
The devices have the two following secondary clock sources:
  -32 kHz low-speed internal RC (LSI RC) which drives the independent watchdog and,
   optionally, the RTC used for Auto-wakeup from the Stop/Standby mode.
  -32.768 kHz low-speed external crystal (LSE crystal) which optionally drives the RTC
   clock (RTCCLK)
Each clock source can be switched on or off independently when it is not used, to optimize
power consumption.


HSE
The high speed external clock signal (HSE) can be generated from two possible clock
sources:
• HSE external crystal/ceramic resonator
• HSE external user clock

HSI
The HSI clock signal is generated from an internal 16 MHz RC oscillator and can be used
directly as a system clock, or used as PLL input.
The HSI RC oscillator has the advantage of providing a clock source at low cost (no external
components).


SYSCLK(System clock selection)
After a system reset, the HSI oscillator is selected as the system clock. When a clock source
is used directly or through PLL as the system clock, it is not possible to stop it.
A switch from one clock source to another occurs only if the target clock source is ready.

CSS(Clock security system)
The clock security system can be activated by software. In this case, the clock detector is
enabled after the HSE oscillator startup delay, and disabled when this oscillator is stopped.

Watchdog clock
If the independent watchdog (IWDG) is started by either hardware option or software
access, the LSI oscillator is forced ON and cannot be disabled. After the LSI oscillator
temporization, the clock is provided to the IWDG.


Clock-Out capability
Two microcontroller clock output(MCO) pins are available:
    MCO1-You can output four different clock sources onto the MCO1 pin (PA8) using the
    configurable prescaler:HSI,LSE,HSE,PLL
    MCO2-You can output four different clock sources onto the MCO2 pin (PC9) using the
    configurable prescaler:HSE,PLL,SYSCLK,PLLI2S clock
    