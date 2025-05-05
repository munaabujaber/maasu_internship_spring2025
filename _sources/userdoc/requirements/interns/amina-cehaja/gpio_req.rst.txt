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

   The system shall configure GPIO functionality by accessing the MODER, IDR, ODR, PUPDR, and AFR registers depending on whether the pin is set for input mode, output mode, pull-up or pull-down configuration, or alternate function usage.

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

.. req:: Set GPIO pull-up or pull-down configuration
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

   The system shall configure internal pull-up or pull-down resistors for GPIO pins by setting the corresponding bits in the PUPDR register.
   

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


