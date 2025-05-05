==================
USART Requirements
==================

.. req:: Serial Communication Mode
   :id: REQ_INT3_1745778021
   :status: Draft
   :date-released: 25.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to support both asynchronous and synchronous serial communication.

.. req:: Synchronous Mode
   :id: REQ_INT3_1745778287
   :status: Draft
   :date-released: 25.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: If synchronous serial is required, the system shall use the clock line.

.. req:: Asynchronous Mode
   :id: REQ_INT3_1745778792
   :status: Draft
   :date-released: 25.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: If asynchronous serial communication is required system shall use start and stop bits.



.. req:: USART Clock
   :id: REQ_INT3_1745777724
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: Set specific bits in the **RCC** (Reset and Clock Control) register to enable the clock for the USART peripheral.

.. req:: USART Clock Enable
   :id: REQ_INT3_1745777880
   :status: Draft
   :date-released: 25.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745777724 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall enable clock for the specific USART peripheral.



.. req:: USART GPIO Pins AF Configuration
   :id: REQ_INT3_1745779025
   :status: Draft
   :date-released: 25.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall configure proper GPIO pins (TX and RX) in alternate function mode.

.. req:: Appropriate AF Mapping
   :id: REQ_INT3_1745786610
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall map proper/specific GPIO pins to the appropriate alternate function.



.. req:: CR1 Register
   :id: REQ_INT3_1745803985
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: In order to configure USART to operate in RX only, TX only, or both RX and TX modes set specific bits within CR1 (USART Control Register).
   Set the UE (USART Enable) bit in the CR1 register to enable the USART.
   Set TE (Transmitter Enable) bit in the CR1 register to enable transmission.
   Set RE (Receiver Enable) bit in the CR1 register to enable reception.


.. req:: USART Mode Configuration
   :id: REQ_INT3_1745799802
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745803985 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall be able to configure USART to operate in RX only, TX only, or both RX and TX modes.

.. req:: USART Enable
   :id: REQ_INT3_1745787901
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745803985 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall enable the USART.

.. req:: Transmitter Enable
   :id: REQ_INT3_1745788895
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745803985 and RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall enable transmission.

.. req:: Receiver Enable
   :id: REQ_INT3_1745789392
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745803985 and RM0383 Reference manual
   :verification-and-validation: 
  
   description: The system shall enable reception.



.. req:: BRR Register
   :id: REQ_INT3_1745804072
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: The BRR (Baud Rate Register) is used to set baud rate for communication.


.. req:: Baud Rate Configuration
   :id: REQ_INT3_1745800268
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: REQ_INT3_1745804072 and RM0383 Reference manual
   :verification-and-validation: 
  
   description: The system shall allow setting the baud rate for communication.

.. req:: Oversampling Configuration
   :id: REQ_INT3_1745800314
   :status: Draft
   :date-released: 27.04.2025.
   :priority: Low
   :submitted-by: `Samir Dosljak <https://github.com/sdosljak1>`_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: RM0383 Reference manual
   :verification-and-validation: 

   description: The system shall allow configuring oversampling.
   