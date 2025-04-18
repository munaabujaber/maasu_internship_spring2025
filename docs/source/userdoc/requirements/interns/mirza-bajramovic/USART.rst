USART  Requirements
===================

.. req:: Enable USART Clock
   :id: REQ_INT3_1744991784
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.5.3. Configuring USART on STM32
   :verification-and-validation: 

   The system shall enable the clock for the selected USART peripheral.

.. req:: Configure TX and RX Pins
   :id: REQ_INT3_1744992485
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.5.3. Configuring USART on STM32
   :verification-and-validation: 

   The system shall configure the TX and RX pins for USART in alternate function mode.

.. req:: Set Baud Rate
   :id: REQ_INT3_1744992499
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.5.4. Setting USART Configuration
   :verification-and-validation: 

   The system shall set the baud rate to control the speed of data transmission.

.. req:: Enable Transmission and Reception
   :id: REQ_INT3_1744992527
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.5.4. Setting USART Configuration
   :verification-and-validation: 

   The system shall enable both transmission and reception for USART communication.

.. req:: Configure Oversampling
   :id: REQ_INT3_1744992616
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.5.2. Key Concepts
   :verification-and-validation: 

   The system shall configure the oversampling rate for USART communication.

.. req:: Enable USART Module
   :id: REQ_INT3_1744992657
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 2.2.5.4. Setting USART Configuration
   :verification-and-validation: 

   Before transmitting or receiving data, the system shall enable the USART module.

.. req:: USART Configuration Time
   :id: REQ_INT3_1744992561
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Mirza Bajramovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 2.2.5.6. Practical Application
   :verification-and-validation: 

   After startup, the system shall complete USART configuration within 10 milliseconds.





