=================
GPIO Requirements
=================

.. req:: MODER Register
   :id: REQ_INT3_1745491590
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
  
   description: **MODER** (Mode register) uses two bits per pin to configure each pin of a particular port in one of the following modes

   - Input mode (00)
   - Output mode (01)
   - Alternate function mode (10)
   - Analog mode (11)

.. req:: GPIO Pin Mode Configuration
   :id: REQ_INT3_1745491125
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745491590 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall configure GPIO pins as input, output, alternate function, or analog.



.. req:: PUPDR Register
   :id: REQ_INT3_1745491991
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil:
   :references: RM0383 Reference manual
   :verification-and-validation: 
 
    description: PUPDR (Pull-Up/Pull-Down Register) uses two bits per pin to define whether the GPIO input pin is internally connected to pull-up or pull-down resistor or neither (floating).
   
.. req:: Input State Selection
    :id: REQ_INT3_1745491673
    :status: Draft
    :date-released: 24.04.2025.
    :priority: Low
    :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
    :modified-by:
    :category: Functional
    :safety-asil: 
    :references: REQ_INT3_1745491991 and RM0383 Reference manual
    :verification-and-validation: 
    
    description: The system shall configure each input internal state.
    


.. req:: OTYPER Register
   :id: REQ_INT3_1745492769
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
     
   description: OTYPER (Output Type Register) is used to configure each GPIO output pin as push-pull or open-drain. Push-pull can drive both low and high logic levels, while open-drain can only drive low logic level and needs external pull-up resistor to drive high logic level.

.. req:: Output Type Selection
    :id: REQ_INT3_1745492102
    :status: Draft
    :date-released: 24.04.2025.
    :priority: Low
    :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
    :modified-by:
    :category: Functional
    :safety-asil: 
    :references: REQ_INT3_1745492769 and RM0383 Reference manual
    :verification-and-validation: 
   
    description: The system shall configure each GPIO output pin as either push-pull or open-drain.



.. req:: OSPEEDR Register
   :id: REQ_INT3_1745493934
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
   
   description: OSPEEDR (Output Speed Register) is used to configure output speed of each GPIO output pin as low, medium, fast or high. The speed affects the strength of output signals. Lower speeds are clearer but some applications need higher speed to operate in real-time. Higher speed can cause electromagnetic interference and consume more power.

.. req:: Output Speed Configuration
    :id: REQ_INT3_1745493127
    :status: Draft
    :date-released: 24.04.2025.
    :priority: Low
    :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
    :modified-by:
    :category: Functional
    :safety-asil: 
    :references: REQ_INT3_1745493934 and RM0383 Reference manual
    :verification-and-validation: 
       
    description: The system shall configure the output speed of each GPIO output pin as low, medium, fast, or high.
       


.. req:: IDR Register
   :id: REQ_INT3_1745494645
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
  
   description: IDR (Input Data Register) is used to read logic levels from each GPIO input pin.

.. req:: Input Reading
   :id: REQ_INT3_1745494168
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745494645 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to read the logic level (high or low) of each input pin.


.. req:: ODR Register
   :id: REQ_INT3_1745495671
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
  
   description: ODR (Output Data Register) is used to set the logic level of each GPIO pin as low or high.
  
.. req:: Output Control
   :id: REQ_INT3_1745494722
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745495671 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to set the logic level of each GPIO output pin to low or high.


.. req:: BSRR Register
   :id: REQ_INT3_1745496130
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
  
   description: BSRR (Bit Set/Reset Register) is used to set or reset GPIO output pins individually, without affecting other pins of the same port.
  
.. req:: Atomic Bit Set/Reset
   :id: REQ_INT3_1745495729
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745496130 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to set or reset individual GPIO pins without affecting the other pins on the same port.


.. req:: AFR Register
   :id: REQ_INT3_1745497957
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 
  
   description: AFR (Alternate Function Register) is used to select which alternate function a pin will use when configured in alternate function mode.

.. req:: Alternate Function  Selection
   :id: REQ_INT3_1745496175
   :status: Draft
   :date-released: 24.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745497957 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to configure the GPIO pin to use alternate function.
   