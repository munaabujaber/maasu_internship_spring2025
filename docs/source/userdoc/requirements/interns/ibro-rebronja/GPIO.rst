=======================
GPIO Requirements
=======================

.. req:: Configure GPIO Pin Mode
   :id: REQ_INT3_1744372222
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow the configuration of each GPIO pin to operate in one of the following modes:
   input, output, alternate function, or analog.

   .. impl:: 
      :id: IMP_INT3_1744372222
      :description: Implement GPIO pin mode configuration logic using the GPIO registers.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Set Pull-Up/Pull-Down Resistors
   :id: REQ_INT3_1744372223
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support enabling internal pull-up, pull-down, or no resistors on GPIO input pins via the PUPDR register.

   .. impl:: 
      :id: IMP_INT3_1744372223
      :description: Implement logic to configure pull-up/pull-down resistors using the PUPDR register.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Define Output Type
   :id: REQ_INT3_1744372224
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow each GPIO output pin to be configured as either push-pull or open-drain using the OTYPER register.

   .. impl:: 
      :id: IMP_INT3_1744372224
      :description: Implement logic to configure GPIO output type using the OTYPER register.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Set Output Speed
   :id: REQ_INT3_1744372225
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow output speed configuration for GPIO pins (low, medium, fast, high) via the OSPEEDR register.

   .. impl:: 
      :id: IMP_INT3_1744372225
      :description: Implement logic to configure GPIO output speed using the OSPEEDR register.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Assign Alternate Functions
   :id: REQ_INT3_1744372226
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support assigning alternate functions (such as UART, SPI, or I2C) to GPIO pins via AFRL or AFRH registers.

   .. impl:: 
      :id: IMP_INT3_1744372226
      :description: Implement logic to assign alternate functions to GPIO pins using the AFRL or AFRH registers.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Read Input Pin State
   :id: REQ_INT3_1744372227
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow reading the logic level of input GPIO pins via the IDR register.

   .. impl:: 
      :id: IMP_INT3_1744372227
      :description: Implement logic to read GPIO input pin state using the IDR register.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Set and Reset Output Pin States
   :id: REQ_INT3_1744372228
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow setting or resetting individual GPIO pins using the ODR and BSRR registers.

   .. impl:: 
      :id: IMP_INT3_1744372228
      :description: Implement logic to set and reset GPIO output pin states using the ODR and BSRR registers.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Enable GPIO Pin Interrupts
   :id: REQ_INT3_1744372229
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support triggering interrupts from GPIO pins based on edge detection to enable event-driven behavior.

   .. impl:: 
      :id: IMP_INT3_1744372229
      :description: Implement logic to enable interrupts for GPIO pins based on edge detection.
      :dependency: GPIO Interrupt Driver
      :status: Pending
