USART
=====

USART (Universal Synchronous/Asynchronous Receiver/Transmitter) enables serial communication, 
supporting both synchronous and asynchronous modes—unlike UART, which is asynchronous only.

Asynchronous Communication: No clock line, uses start/stop bits.

Synchronous Communication: Uses a clock line; faster and more efficient.

Sample & Oversampling: Higher sampling rate (default is 16) improves reliability.

Baud Rate: Speed of data transfer; needs correct configuration for reliable communication.

USART Configuration Steps

    Enable USART Clock: Through the RCC register.

    Configure GPIO Pins:

        Set TX/RX pins to Alternate Function mode.

        Examples (AF7 unless noted):

            USART1: TX → PA9/PB6, RX → PA10/PB7

            USART2: TX → PA2/PD5, RX → PA3/PD6

            USART6: TX → PC6/PG14, RX → PC7/PG9 (AF8)

    Set Baud Rate:

        Formula (for oversampling by 16): USARTDIV = Fck / Baudrate

        Example for 115200 baud & 50 MHz:
        USARTDIV = 50,000,000 / 115200 ≈ 434

    USART Mode Configuration:

        Set CR1 register bits:

            UE (USART Enable), TE (Transmitter), RE (Receiver)

Data Transmission

    Single Byte: Wait for TXE flag, write data to DR.

    Buffer: Send byte-by-byte after checking TXE each time.

Example Application (USART2)

    Use PA2 (TX) and PA4 (RX).

    Set baud rate to 115200, oversampling = 16.

    In main function:

        Initialize USART

        Enable USART

        Transmit data

Important Registers

    RCC: Enables USART clock

    CR1: Controls USART settings (UE, TE, RE)

    BRR: Baud Rate Register

    DR: Data Register (for sending data)

    SR: Status Register (check TXE flag)




