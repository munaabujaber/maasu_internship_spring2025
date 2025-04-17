=============================
GPIO Requirement
=============================
.. req:: Configure GPIO Mode 
   :id: REQ_INT3_1744888554
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, Section 8
   :verification-and-validation: Hardware test

   The system shall configure GPIO pins as input, output, analog, or alternate function according to the task requirements.

.. req:: Configure GPIO through registers
   :id: REQ_INT3_1744889474
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, Section 8; STM32F411xCE Data Sheet
   :verification-and-validation: Code review, Register-level debugging

   The system shall cofigure GPIO functionality by accessing the appropriate GPIO registers based on the intended pin behavior.

.. req:: Set GPIO pull-up or pull/down resistors
   :id: REQ_INT3_1744889831
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Data Sheet
   :verification-and-validation: Measurement with oscilloscope

   The GPIO configuration shall include setting needed pull-up or pull-down resistors.

.. req:: Enable GPIO clock via RCC
   :id: REQ_INT3_1744890313
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32 Reference Manual, RCC Section 6; GPIO Section 8
   :verification-and-validation: Code review, signal tracing

   The system shall enable the clock for the corresponding GPIO port by setting the appropriate bit in the RCC register.


