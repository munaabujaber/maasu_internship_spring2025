=============================
USART Requirement
=============================
.. req:: Initialize USART
   :id: REQ_INT3_1744892183
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, USART, Section 19
   :verification-and-validation: Serial loopback test

   The system shall initialize USART with specified baud rate, and data bits.

.. req:: Enable TX and RX pins
   :id: REQ_INT3_1744892500
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, USART, Section 19
   :verification-and-validation: Communication test with PC via USB-to-Serial

   The system shall enable both the transmission functionality referred to as TX and the Reception functionality referred to as RX of the USART peripheral.

.. req:: Set USART baud rate
   :id: REQ_INT3_1744892676
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Cehaja
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411xCE Reference Manual, USART, Section 19
   :verification-and-validation: Code review

   The system shall configure the USART baud rate by calculating and setting the division factor in the USART_BRR register, ensuring accurate communication speed according to the selected baud rate.
