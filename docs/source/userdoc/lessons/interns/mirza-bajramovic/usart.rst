USART
=====

**Keywords:**  
USART, UART, RCC, CR1, BRR, TX, RX, Oversampling, Baud Rate, Alternate Function, USARTDIV, Fck

**Summary**


In this lesson, I learned what USART is and how it is used for serial communication in STM32 microcontrollers.  
I now understand the difference between asynchronous and synchronous communication, and why USART is more flexible than UART since it supports both modes.  

I learned how asynchronous communication works using start and stop bits, and how the baud rate determines the speed of data transfer. 
Also, got familiar with oversampling and how it improves accuracy.  
Went through how to configure USART on the STM32F411, including enabling the clock, setting up the TX and RX pins with the correct alternate function, and calculating the correct value for the baud rate register.  
Finally, I understood how to enable transmission and reception by setting the correct control bits in the CR1 register.  

I also learned the basics of using the `toctree` directive in reStructuredText to properly organize and link lessons in the documentation.
