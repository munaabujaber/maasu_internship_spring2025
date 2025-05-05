=======================
USART Requirements
=======================

.. req:: Enable USART Clock
   :id: REQ_INT3_1744372235
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow enabling the clock for USART via the RCC register.

   .. impl:: 
      :id: IMP_INT3_1744372235
      :description: Implement logic to enable USART clock using RCC register.
      :dependency: Clock Driver
      :status: Pending

.. req:: Configure GPIO for USART
   :id: REQ_INT3_1744372236
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow configuring GPIO pins for USART TX and RX in alternate function mode (AF7) via the GPIO register.

   .. impl:: 
      :id: IMP_INT3_1744372236
      :description: Implement logic to configure PA2 (TX) and PA4 (RX) pins in AF7 mode.
      :dependency: GPIO Driver
      :status: Pending

.. req:: Set Baud Rate
   :id: REQ_INT3_1744372237
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow setting the baud rate for USART communication via the BRR register.

   .. impl:: 
      :id: IMP_INT3_1744372237
      :description: Implement logic to configure baud rate in BRR register.
      :dependency: USART Driver
      :status: Pending

.. req:: Enable USART Transmitter and Receiver
   :id: REQ_INT3_1744372238
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow enabling the USART transmitter and receiver via the CR1 register by setting the **TE** and **RE** bits.

   .. impl:: 
      :id: IMP_INT3_1744372238
      :description: Implement logic to enable the transmitter and receiver in the CR1 register.
      :dependency: USART Driver
      :status: Pending

.. req:: Send Data via USART
   :id: REQ_INT3_1744372239
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Ibro Rebronja <https://github.com/IbroRebronja>_
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow sending data via USART by writing to the DR register and checking the TXE flag.

   .. impl:: 
      :id: IMP_INT3_1744372239
      :description: Implement logic to send data over USART by checking TXE flag and writing to DR register.
      :dependency: USART Driver
      :status: Pending