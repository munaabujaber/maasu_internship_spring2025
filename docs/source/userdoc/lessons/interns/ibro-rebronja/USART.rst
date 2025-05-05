====================
Lesson 3 - USART
====================

Overview of USART on STM32
---------------------------
- This week, I dove into **USART** (Universal Synchronous/Asynchronous Receiver/Transmitter) on the **STM32F411 microcontroller**. 


The thing about USART is that, unlike UART, it supports both synchronous and asynchronous communication.


For most of the time, I would be using it in asynchronous mode because it’s more flexible.
In this mode, data is sent bit by bit, with start and stop bits marking the beginning and end of the data, and you don’t need a clock line—making everything simpler.

Key Takeaways
-------------
* In asynchronous mode, you don’t need a clock line to send data, which makes it a great option for serial communication. 


-- To get USART working, I need to enable the clock first using the RCC register. 

Then, I configure the right GPIO pins for transmitting (TX) and receiving (RX) data, like PA9 for TX and PA10 for RX. 
The baud rate (how fast the data is sent) is set in the BRR register. 

The USART itself is turned on and configured through the CR1 register by enabling the **UE** bit (USART Enable), and the **TE** (Transmitter Enable) and **RE** (Receiver Enable) bits for sending and receiving data.

USART Configuration Steps
-------------------------
-- To get USART up and running on STM32, the first thing is to enable the clock through the RCC register. 

Then, I pick the right pins for TX and RX, like PA2 for TX and PA4 for RX, and set them to alternate function mode (AF7). 

After that, I calculate the baud rate based on the system clock and put it in the BRR register. 

The final step is to enable the USART and configure the transmitter and receiver by setting the right bits in the CR1 register.

Sending Data with USART
-------------------------
-- When I want to send data over USART, I first check if the **TXE** flag is set, which means the transmit buffer is ready.

Once it’s ready, I can write my byte to the **DR** register. 

If I’m sending a whole string or a buffer, I’ll loop through each byte, checking the **TXE** flag to make sure it’s ready before sending the next byte.

Example: Using USART2
-----------------------
-- If I want to use **USART2**, I’ll start by configuring the pins PA2 (TX) and PA4 (RX) in alternate function mode (AF7). 

Then, I set the baud rate to 115200 and turn on 16x oversampling to make things more accurate. 

Next, I enable both TX and RX in the CR1 register. 

In my main program, I can then send data by writing to the USART data register.

Important Registers
-------------------
The **RCC** register is the one that enables the clock for USART. 

The **CR1** register is where all the configuration happens for USART—like turning it on with the **UE** bit, and enabling the transmitter with **TE** and the receiver with **RE**. 

The **BRR** register is where I set the baud rate. 

The **DR** register holds the data I want to send. 

The **SR** register lets me know what’s happening, and the **TXE** flag tells me when the transmit buffer is ready to send more data.