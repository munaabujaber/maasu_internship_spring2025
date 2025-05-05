=============================
CLOCK SUMMARY
=============================

Introduction
------------
The clock is crucial to ensure an accurate and efficient operation. It is like a heartbeat-determines how fast the system runs. With proper configuration, the following is achieved: accuracy (precise frequency), optimal performance, and power efficiency.

Clock Initialization
--------------------
The needs are met by selecting the clock sources, voltage scaling, flash memory wait states, and adjusting the PLL parameters.

Configuration
-------------
The STM32 gives registers that let us control every detail of the clock system. Specific bits are set or cleared in these registers to choose the clock source, and frequency. 
RCC register manages reset and clock control.

Clock Source Selection
----------------------
There are multiple options: HSI, HSE, LSI, LSE, and we choose one depending on whether we need accuracy or simplicity.

Voltage Scaling
---------------
Higher frequencies need higher core voltage. STM32 allows voltage scaling to save power at lower frequencies and to safely run at higher speeds when needed.

Flash memory wait states
------------------------
The flash memory (where the program is stored) is slower, so the wait states are needed. By setting those delays, flash memory has enough time to keep up. 
The faster the clock, the more wait states are needed.

PLL
----
PLL (Phase-Locked Loop) configuration is like a gear system, the input and output "gears" are set to get the wanted clock speed. PLL helps take a slower, steady clock and turn it into a faster one that the microcontroller can use.
