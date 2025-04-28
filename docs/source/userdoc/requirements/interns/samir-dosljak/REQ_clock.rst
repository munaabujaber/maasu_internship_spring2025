==================
Clock Requirements
==================

.. req:: RCC_CR Register
   :id: REQ_INT3_1745498138
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: Thr RCC (Reset and Clock Control) is a peripheral within the STM32 that manages reset and clock control. CR(Control Register) is register within RCC that configures the clock sources and oscilators. The following are the possible clock sources

- **HSI** (High-Speed Internal): Internal RC oscillator, 16 MHz
- **HSE** (High-Speed External): External crystal oscillator, 4–26 MHz
- **LSI** (Low-Speed Internal): Internal 32 kHz RC oscillator
- **LSE** (Low-Speed External): External 32 kHz crystal used for RTC (Real-Time Clock)

.. req:: Clock Source Selection
   :id: REQ_INT3_1745672967
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745498138 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall configure the clock source as HSI, HSE, LSI, or LSE.



.. req:: APB1ENR Register
   :id: REQ_INT3_1745684260
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: APB1ENR (APB1 Peripheral Clock Enable Register) enables or disables the clock for peripherals connected to the APB1 bus.

.. req:: Peripheral Clock Control (APB1)
   :id: REQ_INT3_1745684367
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745684260 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to enable or disable clock peripherals connected to the APB1 bus.



.. req:: **HSEBYP**
   :id: REQ_INT3_1745684547
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: HSEBYP is bit within CR register that enables bypassing the HSE crystal with an external clock.

.. req:: HSE Oscillator Bypass
   :id: REQ_INT3_1745684635
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745684547 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall allow bypassing the HSE crystal oscillator with an external clock.



.. req:: **HSERDY**
   :id: REQ_INT3_1745684798
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
  
   description: HSERDY is status bit within CR register that indicates whether the HSE clock is ready.

.. req:: HSE Readiness Status
   :id: REQ_INT3_1745685203
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745684798 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall allow reading the HSE oscillator ready status.



.. req:: **PWREN**
   :id: REQ_INT3_1745685327
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: PWREN is bit within APB1ENR that enables or disables the clock of the power control module.

.. req:: Power Control Clock Enable
   :id: REQ_INT3_1745685341
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745685327 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall enable the clock for the power control module.



.. req:: **FLASH_ACR**
   :id: REQ_INT3_1745702213
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description:
               - **FLASH_ACR** is a register within the STM32 microcontroller responsible for managing Flash memory.  
               - **FLASH_ACR_LATENCY** is a field in `FLASH_ACR` (bits 0 to 3) that configures the number of wait states in order to correctly read data from Flash memory.

.. req:: Flash Memory Configuration
   :id: REQ_INT3_1745702240
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745702213 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall configure the number of Flash memory wait states.



.. req:: **PLL** (Phase-Locked Loop)
   :id: REQ_INT3_1745702465
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: **PLL** (Phase-Locked Loop) is a system that increases the frequency of the input clock signal.  
   **PLLCFGR** (PLL Configuration Register) configures the PLL by adjusting dividers and multipliers. A typical frequency of the output clock signal is 100 MHz.  
   **VCO** (Voltage-Controlled Oscillator) is part of the PLL system.  
   **PLLM** is the main divider of the input clock.  
   **PLLN** is the multiplier for the VCO output.  
   **PLLP** is the divider for the PLL output.  
   **PLLQ** and **PLLI2S** are dividers used for USB and I2S configurations, respectively.

   - **RCC_PLLCFGR_PLLM** is a bit mask for PLLM.
   - **RCC_PLLCFGR_PLLM_Pos** is the bit position for PLLM within the **RCC_PLLCFGR** register.

.. req:: PLL Configuration
   :id: REQ_INT3_1745702487
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745702465 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall allow configuring the PLL to achieve higher system clock frequencies when required.
   