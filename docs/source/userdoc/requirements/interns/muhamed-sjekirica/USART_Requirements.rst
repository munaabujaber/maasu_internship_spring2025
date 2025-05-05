==================
USART Requirements
==================

.. req:: USART clock enable
   :id: REQ_INT3_1744887104
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 9.3.5
   :verification-and-validation: Code inspection

   The USART clock must be enabled using the RCC register.

.. req:: USART baud rate setup
   :id: REQ_INT3_1744888427
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 30.6.3
   :verification-and-validation: Code inspection

   The BRR register must be set with the correct value to match the required baud rate for communication.

.. req:: USART mode and enable
   :id: REQ_INT3_1744888517
   :status: Draft
   :date-released: 17.4.2025
   :priority: Medium
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 30.6.4
   :verification-and-validation: Code inspection

   The USART must be enabled by setting the UE bit in the CR1 register,and both the TE (Transmitter Enable) and RE (Receiver Enable) bits must be set in the CR1 register to enable transmission and reception functionalities.

.. req:: USART data transmission
   :id: REQ_INT3_1744888604
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Muhamed Sjekirica
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 RM0383, section 30.6.5
   :verification-and-validation: Code inspection

   Data must be written to the DR (Data Register) when the TXE (Transmit Data Register Empty) flag is set in the SR (Status Register).



