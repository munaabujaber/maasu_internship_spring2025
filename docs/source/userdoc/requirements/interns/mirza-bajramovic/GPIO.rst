GPIO  Requirements
===================
.. req:: GPIO Mode Overview
   :id: REQ_INT3_1744880333
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: REQ_INT3_1744792622
   :verification-and-validation: 

   Each GPIO pin on the STM32 microcontroller can operate in one of four modes defined in the MODER register:

   - **Input mode (00)**: Configures the pin to receive signals from external devices.
   - **General-purpose output mode (01)**: Allows the pin to drive logic levels to connected components.
   - **Alternate function mode (10)**: Connects the pin to internal peripherals such as USART, SPI, or I2C.
   - **Analog mode (11)**: Enables analog signal input/output, often used with ADCs and DACs.



.. req:: GPIO Mode Configuration
   :id: REQ_INT3_1744792622
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support configuring each GPIO pin to input, output, analog, or alternate function mode.

.. req:: Output Types
   :id: REQ_INT3_1744888229
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: REQ_INT3_1744883435
   :verification-and-validation: 

   GPIO output pins can operate in two output types: push-pull and open-drain.

   - In **push-pull mode**, the pin actively drives both high and low levels.  
   - In **open-drain mode**, the pin can only drive low, and an external pull-up resistor is required to achieve a high level.


.. req:: Output Type Selection
   :id: REQ_INT3_1744883435
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow setting the output type of GPIO pins to either push-pull or open-drain mode.

.. req:: GPIO Input States
   :id: REQ_INT3_1744888541
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: REQ_INT3_1744884046
   :verification-and-validation: 

   GPIO input pins can be configured with three internal states:

   - **Pull-up**: Connects the pin to a high logic level through an internal resistor.
   - **Pull-down**: Connects the pin to a low logic level through an internal resistor.
   - **Floating**: Leaves the pin unconnected internally, allowing the input state to be determined entirely by external circuitry.


.. req:: GPIO Input State Configuration
   :id: REQ_INT3_1744884046
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support configuring internal pull-up, pull-down, or floating states for GPIO pins configured as input using the PUPDR register.

.. req:: Output Speed Configuration
   :id: REQ_INT3_1744885915
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support configuring the output speed of GPIO pins to low, medium, fast, or high using the OSPEEDR register.

.. req:: Input State Reading
   :id: REQ_INT3_1744885930
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow reading the logical state (high or low) of each GPIO pin configured as input using the IDR register.

.. req:: GPIO Output State Control
   :id: REQ_INT3_1744886064
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support setting the logical state of each GPIO pin configured as output.

.. req:: label
   :id: REQ_INT3_1744887451
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow the user to select alternate functions for GPIO pins used by peripherals such as USART, SPI, or I2C.


.. req:: BSRR Description
   :id: REQ_INT3_1744889286
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: REQ_INT3_1744888053
   :verification-and-validation: 

   The BSRR (Bit Set/Reset Register) is used to set or reset GPIO output pins atomically.

   - Writing to bits 0–15 sets the corresponding pin.
   - Writing to bits 16–31 resets the corresponding pin.
   This prevents conflicts caused by read-modify-write operations and ensures interrupt-safe behavior.


.. req:: Atomic Pin Reset Using BSRR
   :id: REQ_INT3_1744888053
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall perform GPIO pin set and reset operations using the BSRR register to ensure atomic access without affecting other pins.



.. req:: GPIO Performance Requirement
   :id: REQ_INT3_1744905253
   :status: Draft
   :date-released: 17.04.2025
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall ensure that GPIO pin state changes are completed within 10 milliseconds.