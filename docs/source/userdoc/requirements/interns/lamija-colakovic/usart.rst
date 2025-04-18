Requirements for USART
======================
.. req:: USART peripheral clock 
   :id: REQ_INT3_1744926457
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to USART
   :verification-and-validation: 

   The system must enable the USART peripheral clock by setting the appropriate bit in the RCC register.

.. req:: TX and RX GPIO pins
   :id: REQ_INT3_1744927122
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to USART
   :verification-and-validation: 

   The system must configure the TX and RX GPIO pins for USART operation using the Alternate Function mode.
  
.. req:: Baud Rate Register.
   :id: REQ_INT3_1744927347
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to USART
   :verification-and-validation:

   The system shall set the baud rate by writing the calculated value to the Baud Rate Register.

.. req:: Asynchronous communication mode 
   :id: REQ_INT3_1744927529
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil:
   :references: STM32F411 Overview, Introduction to USART
   :verification-and-validation: 

   The system shall enable asynchronous communication mode by clearing the synchronous clock bit in the USART configuration registers.

.. req:: CR1 control register.
   :id: REQ_INT3_1744927730
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to USART
   :verification-and-validation: 

   The system shall enable transmission and reception by setting the TE and RE bits in the CR1 control register.

.. req:: Data Register
   :id: REQ_INT3_1744927860
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to USART
   :verification-and-validation: 

   The system shall transmit data by writing a byte to the Data Register when the TXE flag is set in the Status Register.







  
