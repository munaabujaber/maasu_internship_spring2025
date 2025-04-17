=============================
Clock Requirement
=============================
.. req:: Configure system clock source
   :id: REQ_INT3_1744890947
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, Clock, Section 6
   :verification-and-validation: Oscilloscope check

   The system shall allow selection of the main system clock source (HSI, HSE, LSI, LSE). 

.. req:: Configure PLL for system clock
   :id: REQ_INT3_1744891199
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, PLL configuration, Section 6
   :verification-and-validation: Code review, PLL frequency verification 

   The system shall configure the PLL settings to generate the ddesired system clock frequency.

.. req:: Configure clock dividers
   :id: REQ_INT3_1744891864
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, RCC registers, Section 6
   :verification-and-validation: Code review, system timing tests

   The system shall configure the AHB and APB bus clock dividers appropriately.


