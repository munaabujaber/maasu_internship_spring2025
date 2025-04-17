=====================================
CLOCK requirements by Lamija Imamovic
=====================================

.. req:: System Clock Configuration
   :id: REQ_INT3_1744802224
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.1 - L1 - Clock
   :verification-and-validation: 

   The system shall allow configuring the system clock source and frequency, supporting internal and external clock sources.

.. req:: Peripheral Clock Enable
   :id: REQ_INT3_1744883997
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.1 - L1 - Clock
   :verification-and-validation: 

   The system shall allow enabling or disabling the clock for specific peripherals via a control register.

.. req:: Clock Frequency Scaling
   :id: REQ_INT3_1744884031
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.1 - L1 - Clock
   :verification-and-validation: 

   The system shall support frequency scaling of the main clock to allow power optimization based on performance needs.

.. req:: Real-Time Clock Support
   :id: REQ_INT3_1744884048
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.1 - L1 - Clock
   :verification-and-validation: 

   The system shall provide configuration and support for a real-time clock (RTC) for timekeeping functions independent of system power state.


.. req:: Flash Wait State Configuration
   :id: REQ_INT3_1744884080
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.1 - L1 - Clock
   :verification-and-validation: 

   The system shall configure the number of flash memory wait states (via FLASH_ACR) based on the system clock frequency to ensure reliable memory access at higher speeds.




