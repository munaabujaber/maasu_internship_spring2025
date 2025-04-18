Clock  Requirements
===================

.. req:: Enable Power Control Clock
   :id: REQ_INT3_1744905696
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.4.2. Key Terms and Abbreviations
   :verification-and-validation: 
   
   The system shall enable the power control module clock using the PWREN bit in the APB1ENR register.

   
.. req:: Configure Voltage Scaling
   :id: REQ_INT3_1744905816
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.4.2. Key Terms and Abbreviations
   :verification-and-validation: 

   The system shall configure the VOS bits in the PWR_CR register to adjust voltage scaling.

.. req:: Enable HSE Oscillator
   :id: REQ_INT3_1744990070
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.4.2. Key Terms and Abbreviations
   :verification-and-validation: 

   The system shall enable the High-Speed External HSE oscillator by setting the HSEON bit in the RCC_CR register.

.. req:: Check HSE Ready
   :id: REQ_INT3_1744990029
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.4.2. Key Terms and Abbreviations
   :verification-and-validation: 

   After enabling HSE, the system shall check the HSERDY bit to confirm oscillator stability.

.. req:: Configure Flash Wait States
   :id: REQ_INT3_1744990085
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.4.2. Key Terms and Abbreviations
   :verification-and-validation: 

   The system shall set the FLASH_ACR_LATENCY register to configure three wait states for operation at 100 MHz.

.. req:: Configure PLL
   :id: REQ_INT3_1744990124
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.4.3. Example PLL Configuration
   :verification-and-validation: 

   The system shall configure the PLL to use the 8 MHz High-Speed External oscillator as its input to generate a 100 MHz system clock.

.. req:: Ensure Clock Stability
   :id: REQ_INT3_1744990800
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 2.2.4.4. Importance of Clock Initialization
   :verification-and-validation: 

   After startup, the system shall complete clock initialization within 10 milliseconds.



