=============================
GPIO SUMMARY
=============================

Introduction
------------
GPIO (General-Purpose Input/Output) plays a crucial role in embedded systems allowing microcontrollers to interact with external devices. Before working with GPIO, it is important to understand what tasks the microcontroller needs to perform (to read sensors, control LEDs, communicate with other devices, or process analog signal). Based on the task, the GPIO pins should be configured. 

GPIO Modes
-----------
Each GPIO pin can operate in one of four main modes: input, output, analog, or alternate function. In input mode, the pin reads digital signals from external components such as push buttons or motion detectors. Output mode allows the microcontroller to send digital signals to components like LEDs or buzzers. Analog mode is used when dealing with continuous signals, like those from temperature or light sensors, and is usually tied to the ADC (Analog to Digital Converter) peripheral. Alternate function mode assigns the GPIO pin to a peripheral function like UART, SPI, I2C, or PWM—enabling communication or advanced control features.

Configuration
-------------
The configuration of GPIO is done through ports and registers. GPIO pins are grouped into ports (e.g., Port A, Port B, etc.), and each port has a set of registers to manage its pins. Common GPIO registers include the MODER (mode register), IDR (input data register), ODR (output data register), AFR (alternate function register), and PUPDR (pull-up/pull-down register).

To decide which register to use, we consider what we want the pin to do. For example, if we want to set a pin to output mode, we use the MODER register; to send a high or low signal, we write to the ODR; to read a pin’s input, we read from the IDR. If the pin needs to use a peripheral function like UART, we configure the AFR.

Use Cases
----------
By correctly setting GPIO pins using these registers and modes, following applications can be done:
    Digital Control - to control LEDs, relays, small motors 
    Signal Monitoring - using IDR
    Communication - protocols
    PWM - motor control or LED dimming
    Interrupt Handling - to trigger interrupt