==================
Clock Requirements
==================

.. req:: Clock source selection
   :id: REQ_INT3_1744886290
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.1
   :verification-and-validation: Code inspection

   Description:
   The system clock source must be selected from HSI, HSE, LSI, or LSE using RCC control registers.

.. req:: RCC Clock Control Register(RCC_CR)
   :id: REQ_INT3_1745319087
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.1
   :verification-and-validation: 

   Description:
   Manages the activation and status of oscillators (HSI, HSE, LSI, LSE) and the PLL.

.. req:: RCC Clock Configuration Register(RCC_CFGR)
   :id: REQ_INT3_1745319351
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.1
   :verification-and-validation: 

   Description:
   Configures the system clock source and prescalers.

.. req:: RCC PLL Configuration Register (RCC_PLLCFGR)
   :id: REQ_INT3_1745319467
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.1
   :verification-and-validation: 

   Description: 
   Configures the PLL source and multipliers.

  .. req:: RCC Backup Domain Control Register (RCC_BDCR)
     :id: REQ_INT3_1745319543
     :status: Draft
     :date-released: 22.4.2025
     :priority: Low
     :submitted-by: `Muhamed Sjekirica
     :modified-by:
     :category: Informational
     :safety-asil: 
     :references: STM32F411 RM0383, section 6.2.1
     :verification-and-validation: 
  
     Description: 
     Manages the LSE oscillator for RTC and other low-power functions.
  
.. req:: RCC Clock Interrupt Register (RCC_CIR)
   :id: REQ_INT3_1745319615
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.1
   :verification-and-validation: 

   Description: 
   Manages interrupt flags and enables for clock-related events.


.. req:: External clock enable
   :id: REQ_INT3_1744886344
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.2
   :verification-and-validation: Code inspection

   Description:
   The HSE clock must be enabled by setting the HSEON bit in the RCC_CR register.

.. req:: HSE ready check
   :id: REQ_INT3_1744886474
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.2
   :verification-and-validation: Code inspection

   Description:
   The HSERDY bit must be checked to confirm the HSE oscillator is stable and ready.

.. req:: PLL configuration
   :id: REQ_INT3_1744886537
   :status: Draft
   :date-released: 17.4.2025
   :priority: High
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.3
   :verification-and-validation: Code inspection

   Description:
   The PLL must be configured using the PLLCFGR register by setting values for PLLM, PLLN, and PLLP to achieve the required system frequency.

.. req:: Flash latency setup
   :id: REQ_INT3_1744886656
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 3.3.1
   :verification-and-validation: Code inspection

   Description:
   The FLASH_ACR_LATENCY must be set according to the system clock speed to ensure proper flash access timing.

.. req:: APB1ENR Register
   :id: REQ_INT3_1745319856
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.13
   :verification-and-validation: Code inspection

   Description: 
   The APB1ENR register controls the clock enabling for peripherals connected to the APB1 bus, including the power control (PWR) interface.


.. req:: Power control clock enable
   :id: REQ_INT3_1744886714
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 6.2.13
   :verification-and-validation: Code inspection

   Description:
   The PWREN bit in the APB1ENR register must be set to enable the power control interface clock.





