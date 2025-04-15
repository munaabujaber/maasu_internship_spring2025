=================
Lesson 3 - USART
=================

Overview
--------

USART (Universal Synchronous/Asynchronous Receiver/Transmitter) is a critical hardware feature in the STM32F411 microcontroller, enabling efficient serial communication. Unlike the UART, which supports only asynchronous communication, USART supports both asynchronous and synchronous modes, making it more versatile for various communication needs. In this document, we will explore the key features, configuration, and usage of USART on the STM32F411.

 Key Features of USART in STM32F411:

- **Asynchronous Communication**: This mode is the most commonly used in serial communication (e.g., RS232, RS485). Data is transmitted sequentially one bit at a time, without the need for a clock signal. Start and stop bits indicate the beginning and end of data transmission.

- **Synchronous Communication**: In this mode, data and clock signals are transmitted simultaneously, providing a faster and more efficient method of communication, typically used for higher baud rates.

- **Interrupts and DMA Support**: USART supports both interrupts and DMA (Direct Memory Access) to handle data transmission and reception efficiently. These features offload the processor, improving performance and reducing CPU usage.

- **Multiple USART Modules**: The STM32F411 supports four USART/UART modules:
  - **USART1**
  - **USART2**
  - **USART3**
  - **UART4** (which can also be used as USART)

Baud Rate and Communication
----------------------------

The **baud rate** is the number of bits transmitted per second. It is essential that both devices communicating over USART have the same baud rate to ensure reliable data transmission. Mismatched baud rates can cause errors in communication.

### Important Considerations:
- **Baud Rate Matching**: For proper communication, both devices (e.g., microcontroller and PC) must have matching baud rates. If they differ, data corruption may occur, leading to errors in communication.
- **Oversampling**: The default oversampling rate is 16, but it can be adjusted to 8 for higher data rates or reduced accuracy.

DMA in USART Communication
---------------------------

Using **DMA (Direct Memory Access)** for data transfer between USART and memory is a powerful feature for improving performance. It allows data to be transferred without CPU intervention, reducing processing time and improving system efficiency.

### Benefits of Using DMA:
- **Increased Efficiency**: By offloading data transfer from the CPU, DMA reduces the processor’s workload, allowing it to perform other tasks simultaneously.
- **Reduced Latency**: DMA transfers data faster, especially for large data sets, as the CPU is not involved in each byte's transmission.
- **Fewer Errors and Higher Speed**: DMA ensures more reliable and faster communication by avoiding delays and errors caused by CPU interference.

Configuring USART on STM32F411
------------------------------

To configure USART communication on the STM32F411, several steps are involved, including enabling clocks, configuring GPIO pins, and setting the baud rate.

To begin using the USART peripheral, enable the USART clock in the **RCC (Reset and Clock Control)** register.

Each USART peripheral uses specific GPIO pins for data transmission (TX) and reception (RX). These pins must be configured for alternate function mode and mapped to the appropriate alternate function (AF).

- **USART1**:
  - TX: PA9 or PB6
  - RX: PA10 or PB7
  - Alternate Function: AF7

- **USART2**:
  - TX: PA2 or PD5
  - RX: PA3 or PD6
  - Alternate Function: AF7

- **USART3**:
  - TX: PB10 or PC10
  - RX: PB11 or PC11
  - Alternate Function: AF7


Configuring USART Mode:
- **RX, TX, or Both**: Select whether the USART will operate in **RX only**, **TX only**, or **both RX and TX** modes by setting the appropriate bits in the USART control register (CR1).
- **Enable USART**: Set the **UE** bit (USART Enable) in the CR1 register to enable the USART.
- **Enable Transmitter and Receiver**: Set the **TE** (Transmitter Enable) and **RE** (Receiver Enable) bits to enable data transmission and reception.

Data Transmission
-----------------

To transmit data via USART, follow these steps:

1. **Wait for TXE Flag**: Check the TXE (Transmit Data Register Empty) flag in the Status Register (SR) to ensure that the transmit data register is ready for new data.
2. **Write Data**: Write the data to the **DR (Data Register)** for transmission. Repeat this process for each byte of data.

### Transmitting Buffers:
When transmitting multiple bytes (e.g., a buffer), write each byte sequentially to the data register. Ensure that the TXE flag is checked before sending the next byte.


