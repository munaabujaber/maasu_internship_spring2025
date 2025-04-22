=======================
Clock Requirements
=======================

.. req:: Configure Clock Source
   :id: REQ_INT3_1744372230
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow configuring the clock source (HSI, HSE, LSI, LSE) via the RCC_CR register.

   .. impl:: 
      :id: IMP_INT3_1744372230
      :description: Implement logic to configure the clock source using the RCC_CR register.
      :dependency: Clock Driver
      :status: Pending

.. req:: Enable PLL
   :id: REQ_INT3_1744372231
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow enabling the PLL (Phase-Locked Loop) for clock multiplication via the PLLCFGR register.

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
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
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
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
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
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
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