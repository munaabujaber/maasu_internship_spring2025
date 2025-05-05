=================
GPIO Requirements
=================


.. req:: GPIO pin mode setup
   :id: REQ_INT3_1744800725
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383,section 8.4.1
   :verification-and-validation: Code inspection

   Each GPIO pin must be configured as input, output, alternate function, or analog using the MODER register.
    
.. req:: GPIO output type 
   :id: REQ_INT3_1744801714
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, Sections 8.4.3
   :verification-and-validation: Code inspection

   The output type must be set to push-pull or open-drain using the OTYPER register.

.. req:: GPIO output speed
   :id: REQ_INT3_1746429836
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM083, Section 8.4.4
   :verification-and-validation: Code inspection

   The output speed must be selected using the OSPEEDR register.

.. req:: GPIO output speed 
   :id: REQ_INT3_1745320115
   :status: Draft
   :date-released: 22.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: STM32F411 RM0383, Section 8.4.4
   :verification-and-validation: Code inspection

   The GPIO output speed determines the rate at which the output signal transitions between low and high states. This setting is crucial for controlling the rise and fall times of the signal,which in turn affects the signal integrity and electromagnetic interference (EMI)
  

.. req:: GPIO input resistor configuration
   :id: REQ_INT3_1744885581
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 8.4.3
   :verification-and-validation: Code inspection

   Pull-up or pull-down resistors must be configured using the PUPDR register, when pin is in input mode.

.. req:: GPIO alternate function setup
   :id: REQ_INT3_1744885731
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 8.4.9
   :verification-and-validation: Code inspection

   Alternate functions must be set using AFRL or AFRH.

.. req:: GPIO interrupt configuration
   :id: REQ_INT3_1744885844
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 12.3
   :verification-and-validation: Code inspection

   GPIO pins must be configured to trigger interrupts on rising, falling, or both edges using EXTI settings.

.. req:: GPIO analog mode configuration
   :id: REQ_INT3_1744886042
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 8.4.1
   :verification-and-validation: Code inspection

   GPIO pins must be set to analog mode using the MODER register when used with ADC or DAC.
