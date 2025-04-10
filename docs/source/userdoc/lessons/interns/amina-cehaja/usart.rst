=============================
USART SUMMARY
=============================

Introduction
-------------
USART is a hardware component in microcontroller that allows the communication between devices. It allows both synchronous and asynchronous serial communication. 
In asynchronous serial communication devices do not share a common clock signal, but they agree on the speed (boud rate), and structure of a message.

Before using the USART, it is important to enable the clock.

Configuration
-------------
USART uses two pins TX (Transmit) and RX (Receive) on the STM32. They must be set to Alternate Function Mode and mapped to corret AF number.

Baud rate
----------
The baud rate must be set. 
If using oversampling by 16, baud rate can be calculated as:
USARTDIV = Fck/BaudRate.

If using oversampling by 8, it can be calculated as:
USARTDIV = Fck/(BaudRate x 2).

Configure Mode
--------------
In the CR1 (Control Register 1) the following have to be set:
UE bit to enable USART, TE to enable Transmitter, RE to enable Receiver.
Both can be enabled, or TX only, or RX only.

