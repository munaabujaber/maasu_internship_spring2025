====================
Lesson 1 - CLOCK
====================

Key Takeaways
-------------
If I would work with a microcontroller, I noticed that getting the clock right is super important—it's like the heartbeat of the system. If the clock isn’t set up properly, nothing will work the way it's supposed to.


The clock controls the speed of everything inside the chip and also how much power it uses. 

The **RCC (Reset and Clock Control)** module is what I use to manage the clock settings. 

This is where I would choose the clock source, turn peripheral clocks on or off, and tweak the system’s frequency using the PLL (Phase-Locked Loop).

Internal vs. External Clocks
----------------------------
There are a few different clock options I can use, which are:

* The **HSI** (High-Speed Internal) clock is the default one built into the microcontroller, running at 8 MHz. 
* If I want something more precise, I can use an **HSE** (High-Speed External) crystal oscillator.
* There are also **LSI** and **LSE** clocks, which are slower and perfect for low-power tasks like running a real-time clock (RTC).

Key Registers
--------------
I would probably use a few registers to control the clocks. 

The **CR** (Control Register) is where I would enable the clock sources and check if they’re stable. 

**APB1ENR** is used to turn on the clocks for peripherals like communication modules, which I would need to talk to other devices. 

The **PWR_CR** register controls how much power the system uses, which affects performance. 

I could adjust the voltage and power settings there. 

Then, **FLASH_ACR_LATENCY** is where I would set how long the microcontroller has to wait for the flash memory when running at higher speeds. 

Finally, **PLLCFGR** is the register I would use to set up the PLL to adjust the system’s clock speed.

The PLL Setup
-------------
-- Setting up the **PLL** (Phase-Locked Loop) would probably be confusing at first but theoretically:

The PLL is used to boost the clock speed. 

I could start with a low frequency, like 8 MHz, and then use the PLL to multiply it up to something higher, like 100 MHz. 

To do this, I would probably divide the input frequency (PLLM), multiply it (PLLN), and then divide it again to get the system’s final clock speed (PLLP).

Most Important Insights
------------------------
To get the best performance, I probably would need to make sure both the clock and flash memory wait states are set correctly. 

If I want to save power, I should only turn on the clocks I really need. 

If stability is important, like for USB or real-time tasks, I should probably go with external clocks like **HSE**. 

I would have to be careful with the register bits (like **HSEBYP** or **VOS_0**) to make sure I don’t mess things up.

And, clock initialization is always the first thing I would probably do before setting up anything else.

Revision Points
---------------
The **RCC** controls both the clock and reset functions. For clock sources, there’s **HSI** (internal), **HSE** (external), **LSI**, and **LSE**. 

The **CR Register** turns clocks on and checks if they’re stable. 

**APB1ENR** powers the peripherals, and **VOS** in **PWR_CR** manages the power and performance settings. 

**FLASH_ACR_LATENCY** adjusts the wait states for the flash memory at higher speeds. 

The **PLLCFGR** configures the PLL settings (PLLM, PLLN, PLLP). 

The PLL formula is: VCO = (Input × PLLN / PLLM), and the system clock = VCO / PLLP. 

So, if I start with an external 8 MHz clock, I can use the PLL to reach a 100 MHz system clock. 

To save power, I should only enable the clocks I need. And I should always remember—setting up the clock is the first step before anything else.
