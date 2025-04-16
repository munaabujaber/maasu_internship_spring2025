================
Lesson 3 - USART
================

**What I’ve Learned – USART on STM32**

This week I focused on understanding USART (Universal Synchronous/Asynchronous Receiver/Transmitter), and how it works on STM32 microcontrollers—especially the STM32F411 series we’re using. USART plays a key role in serial communication, letting the microcontroller talk to other devices like sensors, computers, or other microcontrollers.

A major difference I learned is that unlike UART, which is asynchronous only, USART supports both synchronous and asynchronous modes. In our case, we’re focusing on the asynchronous part, which is more commonly used.

**My Personal Key Takeaways:**
Serial Communication is simpler than I expected. In asynchronous mode (the one we mostly use), data is sent bit by bit over a single line, and it uses start and stop bits to know when transmission begins and ends. This makes things more flexible because we don’t need a clock line. In contrast, synchronous mode does need a clock line but sends data faster since it skips the start/stop bits.

I also got a clearer picture of how sampling and oversampling work. USART typically oversamples incoming signals (default is 16x), which helps with noise reduction and reliability. I now understand why baud rate configuration is so important—both sides of communication need to “speak” at the same speed or nothing will work properly.

**How I’d Configure USART:**
To get USART working, first I need to enable the USART clock via the RCC register. Then, I configure the GPIO pins used for TX and RX. Each USART (1, 2, 6, etc.) can be mapped to specific pins and alternate functions. For example:

- USART1 TX: PA9 or PB6
- USART1 RX: PA10 or PB7
- They both use AF7 (Alternate Function 7)

Then I’d move on to the actual USART settings:

- Baud rate is calculated based on the system clock. Using oversampling by 16, the formula is USARTDIV = Fck / Baudrate. I learned to also add 0.5f for rounding before writing the value to the BRR (Baud Rate Register).
- In CR1 (Control Register 1), I enable USART by setting the UE bit, and then activate TE and RE to allow transmission and reception.

**Sending Data with USART:**
To send data, the microcontroller first checks if the TXE (Transmit Data Register Empty) flag is set. Once it's ready, I can write a byte to the DR (Data Register). If I’m sending a string or buffer, I’d loop through it and send each byte individually, checking TXE each time.

**A Simple Practical Example:**
Let’s say I want to use USART2 with pins PA2 (TX) and PA4 (RX). I’d configure them for alternate function mode (AF7), set the baud rate to 115200, choose oversampling by 16, and enable TX and RX in CR1. Then I can write a simple function in my main() to initialize everything and send some data—like a status message or sensor reading.

**Registers I Need to Know:**
- RCC – Enables clock for USART
- CR1 – Main control register for USART config:
- UE – Enables USART
- TE – Transmitter enable
- RE – Receiver enable
- BRR – Sets baud rate
- DR – Holds the byte of data to send
- SR – Status register (check TXE to see if it's ready to send)


