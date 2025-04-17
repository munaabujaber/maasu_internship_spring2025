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

    Description:
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

   Description:
   The output type must be set to push-pull or open-drain using the OTYPER register.

.. req:: GPIO output speed
   :id: REQ_INT3_1744801948
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, Section 8.4.4
   :verification-and-validation: Code inspection

   Description:
   The output speed must be selected using the OSPEEDR register.
   The speed can be low,medium,fast or high(see glossary).

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

   Description:
   When pin is input mode, pull-up or pull-down resistors must be configured using the PUPDR register.

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

   Description:
   Alternate functions must be set using AFRL (pins 0-7) or AFRH (pins 8-15).

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

   Description:
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

   Description:
   GPIO pins must be set to analog mode using the MODER register when used with ADC or DAC.
