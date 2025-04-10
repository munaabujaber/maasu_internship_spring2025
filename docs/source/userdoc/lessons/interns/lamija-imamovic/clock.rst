================
Lesson 1 - CLOCK
================

**My Personal Key Takeaways:**
Clock initialization is basically setting up the brain of the microcontroller. If it’s not configured properly, nothing else will run as expected. It controls the frequency, voltage, and how fast or slow the internal operations happen.

The first concept I got familiar with is the RCC (Reset and Clock Control) – this is the module responsible for managing all clock-related settings. It allows us to select the clock source, enable or disable peripheral clocks, and set up the PLL (Phase-Locked Loop) for adjusting frequency.



**I also learned the difference between internal and external clocks. For example:**

- HSI (High-Speed Internal) – default 8 MHz internal oscillator.

- HSE (High-Speed External) – uses an external crystal, more accurate.

- LSI / LSE – slower versions, useful for low-power or RTC applications.



**Understanding registers - These are the ones that stood out to me:**

- CR (Control Register) – handles enabling clock sources and checking if they’re stable (e.g., HSEON, HSERDY).

- APB1ENR – enables clocks for different peripherals.

- PWR_CR – manages power scaling using VOS bits.

- FLASH_ACR_LATENCY – sets wait states for flash memory, especially needed at higher frequencies.

- PLLCFGR – it defines how the PLL multiplies/divides the frequency.



The PLL part was a bit tricky at first. I now understand how we use it to increase the clock speed. For example, starting from an 8 MHz external source, we can reach 100 MHz through:

- dividing the input (PLLM),

- multiplying (PLLN),

- and dividing again for output (PLLP).


**What I Found Most Important:**
- If you want performance, you need to properly configure both the clock and the flash memory wait states.

- Power management is tightly linked to clock config – enabling only what you need saves power.

- Using external clocks (like HSE) gives better stability for things like USB or real-time tasks.

- Properly using register bits (like HSEBYP or VOS_0) is essential for safe and effective setup.

- Clock initialization should always be done before configuring other peripherals.


**Usual Bullet Points (for Revision):**
- RCC = controls clocks + resets

- Clock sources: HSI (internal), HSE (external), LSI, LSE

- CR Register: enables oscillators, checks stability

- APB1ENR: enables peripheral clocks

- VOS (PWR_CR): scales voltage → affects performance

- FLASH_ACR_LATENCY: sets flash wait states for higher frequencies

- PLLCFGR: sets PLLM, PLLN, PLLP to reach target clock

- PLL formula: VCO = (Input × PLLN / PLLM), System clock = VCO / PLLP

- External 8 MHz → PLL → 100 MHz system clock

- Power efficiency = only enable what’s needed

- Must set clock before using timers, communication, etc.
