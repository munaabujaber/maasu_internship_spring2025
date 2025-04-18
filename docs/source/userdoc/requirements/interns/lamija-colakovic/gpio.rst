Requirements for GPIO
=====================
.. req:: GPIO configuration
   :id: REQ_INT3_1744883345
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation:
   
   The system shall allow configuration of a GPIO pin using the Mode register.


.. req:: GPIO setting
   :id: REQ_INT3_1744891747
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by: 
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation:
   
   The system shall support setting the GPIO pin to input mode via the Mode register.

.. req:: GPIO pin in input mode
   :id: REQ_INT3_1744900145
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation: 
   
   The system must allow the GPIO pin in input mode to receive external digital signals.


.. req:: Configuration of the output type register
   :id: REQ_INT3_1744904727
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation: 
   
   The system shall allow configuration of the output type register for GPIO pins.


.. req:: Support of the output type register
   :id: REQ_INT3_1744911658
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation: 
   
   The output type register must support configuring GPIO pins as push-pull outputs.


.. req:: GPIO pin in push-pull mode
   :id: REQ_INT3_1744921532
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation: 
   
   In push-pull mode, the GPIO pin must be capable of actively driving both high and low logic levels.


.. req:: GPIO-controlled driver circuits.
   :id: REQ_INT3_1744922037
   :status: Draft
   :date-released: 17/04/2025
   :priority: Low
   :submitted-by: Lamija Colakovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: STM32F411 Overview, Introduction to GPIO
   :verification-and-validation: 
   
   The system must support driving small DC motors via GPIO-controlled driver circuits.











