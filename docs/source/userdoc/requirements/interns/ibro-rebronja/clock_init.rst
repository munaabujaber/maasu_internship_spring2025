=======================
Clock Requirements
=======================

.. req:: Configure Clock Source
   :id: REQ_INT3_1744372230
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow configuring the clock source HSI, HSE, LSI, LSE via the RCC_CR register.

   .. impl:: 
      :id: IMP_INT3_1744372230
      :description: Implement logic to configure the clock source using the RCC_CR register.
      :dependency: Clock Driver
      :status: Pending

.. req:: High-Speed Internal HSI Clock Description
   :id: REQ_INT3_1744373001
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The HSI is an internal RC oscillator that provides an 8 MHz clock source. It is available immediately after reset and is used as the default system clock source.

.. req:: High-Speed External HSE Clock Description
   :id: REQ_INT3_1744373002
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The HSE is an external clock source, typically a crystal oscillator. It provides a more accurate and stable frequency compared to HSI and is suitable for applications like USB and real-time clocks.

.. req:: Low-Speed Internal LSI Clock Description
   :id: REQ_INT3_1744373003
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The LSI is an internal low-frequency clock around 32 kHz used for low-power applications and internal watchdogs. It is not very accurate but is always available without external components.

.. req:: Low-Speed External LSE Clock Description
   :id: REQ_INT3_1744373004
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The LSE is an external 32.768 kHz crystal used for applications that require precise timekeeping, such as real-time clocks (RTC).

.. req:: Enable PLL
   :id: REQ_INT3_1744372231
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow enabling the PLL Phase-Locked Loop for clock multiplication via the PLLCFGR register.

   .. impl:: 
      :id: IMP_INT3_1744372231
      :description: Implement logic to enable PLL and configure multiplication factors using PLLCFGR.
      :dependency: Clock Driver
      :status: Pending

.. req:: Set Flash Latency
   :id: REQ_INT3_1744372232
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow configuring the flash memory latency for higher clock speeds via the FLASH_ACR register.

   .. impl:: 
      :id: IMP_INT3_1744372232
      :description: Implement logic to configure flash memory latency based on system clock speed using FLASH_ACR.
      :dependency: Clock Driver
      :status: Pending

.. req:: Enable Peripheral Clocks
   :id: REQ_INT3_1744372233
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow enabling peripheral clocks via the APB1ENR register for communication modules and other peripherals.

   .. impl:: 
      :id: IMP_INT3_1744372233
      :description: Implement logic to enable peripheral clocks using APB1ENR.
      :dependency: Clock Driver
      :status: Pending

.. req:: Set Power Mode
   :id: REQ_INT3_1744372234
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: `Ibro Rebronja <https://github.com/IbroRebronja>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow setting the power mode and voltage scaling via the PWR_CR register to optimize performance and power consumption.

   .. impl:: 
      :id: IMP_INT3_1744372234
      :description: Implement logic to configure power settings and voltage scaling using PWR_CR.
      :dependency: Power Management Driver
      :status: Pending
