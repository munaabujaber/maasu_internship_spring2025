=====================================
USART requirements by Lamija Imamovic
=====================================

.. req:: USART Initialization
   :id: REQ_INT3_1744802183
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support configuration and initialization of USART peripherals with parameters such as baud rate, parity, stop bits, and data bits.

.. req:: USART Transmission
   :id: REQ_INT3_1744883522
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.3 - L3 - USART
   :verification-and-validation: 

   The system shall support transmission of data over USART in both blocking and non-blocking modes.

.. req:: USART Reception
   :id: REQ_INT3_1744883576
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.3 - L3 - USART
   :verification-and-validation: 
  
   The system shall support reception of data via USART, including buffer handling for incoming bytes.

.. req:: USART Interrupt Handling
   :id: REQ_INT3_1744883606
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.3 - L3 - USART
   :verification-and-validation: 

   The system shall support USART interrupts for transmission complete, data received, and error detection.

.. req:: USART GPIO Pin Mapping
   :id: REQ_INT3_1744883815
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.3 - L3 - USART
   :verification-and-validation: 

   The system shall allow assigning GPIO pins to USART transmit and receive functions using alternate function mode (e.g., AF7), depending on the selected USART peripheral.
  
