===============
Lesson 3: USART
===============

**USART** (Universal Synchronous/Asynchronous Receiver/Transmitter) is a peripheral that manages serial communication between devices.

Communication Modes
-------------------

- **Asynchronous serial communication** is serial communication that doesn't use a clock signal and requires a bit that indicates the beginning, a bit that indicates the end of transmission, and optionally a parity bit used for error detection.
- **Synchronous serial communication**, in addition to the data line, also uses a clock line, so start, stop, and parity bits aren't necessary.

Key Concepts
------------

- **TX**: GPIO pin for transmission.  
- **RX**: GPIO pin for reception.  
- **Sample**: a single piece of data that is being transmitted. Each bit is considered a sample.  
- **Sample Rate**: the number of samples taken per second.  
- **Oversampling**: taking more samples per bit than needed. The default oversampling rate is 16.  
- **Baud Rate**: the number of bits transmitted per second.

USART Configuration
-------------------

To configure USART, follow these steps:

1. Set specific bits in the **RCC** (Reset and Clock Control) register to enable the clock for the USART peripheral.  
2. Configure the appropriate **GPIO pins** (TX and RX) to be in **Alternate Function mode**.  
3. Set the appropriate bits in the **AFR** register to select the USART peripheral.  
4. Set the **UE** bit in **CR1** (Control Register 1) to enable USART.  
5. Set the **TE** bit in CR1 to enable the transmitter.  
6. Set the **RE** bit in CR1 to enable the receiver.  
7. Define the **baud rate** by configuring the **BRR** (Baud Rate Register).