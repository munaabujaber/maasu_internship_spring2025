====================================
GPIO requirements by Lamija Imamovic
====================================

.. req:: GPIO Pin Initialization
   :id: REQ_INT3_1744802101
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.2 - L2 - GPIO
   :verification-and-validation: 

   The system shall allow the initialization of GPIO pins as either input or output with optional pull-up or pull-down resistors.

.. req:: GPIO Output Control
   :id: REQ_INT3_1744882662
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.2 - L2 - GPIO
   :verification-and-validation: 
   
   The system shall allow software to set a general-purpose output pin to a logical high level or a logical low level through the output data register.

.. req:: GPIO Input Read
   :id: REQ_INT3_1744882709
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.2 - L2 - GPIO
   :verification-and-validation: 
     
   The system shall allow reading the current logical level of a configured GPIO input pin.
     
.. req:: GPIO Interrupt Support
   :id: REQ_INT3_1744882852
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.2 - L2 - GPIO
   :verification-and-validation: 

   The system shall support enabling interrupts on GPIO input pins for rising, falling, or both edge triggers.

.. req:: GPIO Output Type and Speed Configuration
   :id: REQ_INT3_1744883423
   :status: Draft
   :date-released: 17.4.2025
   :priority: Low
   :submitted-by: `Lamija Imamovic'
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 4.1.6.2 - L2 - GPIO
   :verification-and-validation: 

   The system shall allow configuration of the general-purpose output type as either push-pull or open-drain. It shall also support setting the output speed to one of four levels: low speed, medium speed, high speed, or very high speed using dedicated control registers.

