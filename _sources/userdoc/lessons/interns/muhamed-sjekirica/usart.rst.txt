=====
USART 
=====

USART (Universal Synchronous/Asynchronous Receiver/Transmitter) is a vital hardware component in microcontrollers, facilitating serial communication between devices.

Asynchronous Serial Communication: Data is transmitted sequentially, one bit at a time, over a single data line without requiring a clock line.
Synchronous Serial Communication: Involves both data and clock lines, where the microcontroller sends a clock signal to synchronize communication.

Sample and Sample Rate: A sample refers to a single piece of data being transmitted. The sample rate is the number of samples taken per second.
Oversampling: Involves sampling at a higher rate than the minimum required to improve accuracy and simplify filtering. The default oversampling rate is 16.
Baud Rate: Determines the speed at which data bits are transmitted. Correct baud rate configuration is essential for smooth communication.

DATA transmission
-Transmitting Data: 1. Wait for the Transmit Data Register Empty (TXE) flag by checking the status register (SR). 2. Write data to the Data Register (DR) for transmission.
-Transmitting a Buffer: Write each byte to the data register one by one, ensuring the transmit data register is empty before writing the next byte.

REGISTER DEFINITIONS
RCC: Reset and Clock Control, used to enable the clock for USART.
CR1: Control Register 1, used to configure USART settings like enabling USART, transmitter, and receiver.
BRR: Baud Rate Register, used to set the baud rate for communication.
DR: Data Register, used to hold data to be transmitted.
SR: Status Register, used to check the status of the USART, including the TXE (Transmit Data Register Empty) flag.

Transmitter
The transmitter can send data words of either 8 or 9 bits depending on the M bit status.
When the transmit enable bit (TE) is set, the data in the transmit shift register is output on the TX pin and the corresponding clock pulses are output on the CK pin.

Basic configuration steps:
1. Enable Clocks:
Activate the clock for the GPIO ports used for USART pins (e.g., GPIOA for PA9 and PA10)
Enable the USART peripheral clock

2. Configure GPIO Pins:
Set the mode of the USART pins to alternate function
Assign the appropriate alternate function to the pins (e.g., AF7 for USART1)
Set the output type to push-pull and configure the speed and pull-up/pull-down resistors as needed

3. Initialize USART:
Set the desired baud rate by configuring the USART_BRR register
Define the word length (e.g., 8 bits) and parity settings in the USART_CR1 register
Select the number of stop bits in the USART_CR2 register
Enable the transmitter and receiver by setting the TE and RE bits in the USART_CR1 register
Activate the USART by setting the UE bit in the USART_CR1 register
