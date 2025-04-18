Requirements for Clock initialization
=====================================
.. req:: HSE oscillator enabling
   :id: REQ_INT3_1744923506
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to clock initialization
   :verification-and-validation:

   The system must set the High-Speed External oscillator bit in the register control to enable the HSE oscillator.

.. req:: System clock frequency
   :id: REQ_INT3_1744923779
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to clock initialization
   :verification-and-validation: Code review of FLASH_ACR settings, system runs stable at target frequency

   The system must configure the number of flash memory wait states based on the system clock frequency.


.. req:: FLASH_ACR register 
   :id: REQ_INT3_1744924630
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to clock initialization
   :verification-and-validation: 

   The system must set 3 wait states in the FLASH_ACR register when operating at clock frequencies between 90–100 MHz.


.. req:: PLL Configuration Register
   :id: REQ_INT3_1744924919
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to clock initialization
   :verification-and-validation: 

   The system shall use the RCC_PLLCFGR_PLLM (PLL Configuration Register) bit mask to access the PLLM field in the RCC_PLLCFGR register.


.. req:: RCC_PLLCFGR_PLLM_Pos definition
   :id: REQ_INT3_1744925998
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to clock initialization
   :verification-and-validation: 
   
   The system shall use the RCC_PLLCFGR_PLLM_Pos definition to correctly position the PLLM bits in the RCC_PLLCFGR register.




   


  
    
  

