Clock Initialization
====================

**Keywords:**  

RCC, HSI, HSE, LSI, LSE, CR, APB1ENR, PLL, VOS, FLASH_ACR_LATENCY, PLLCFGR

Summary
******

This lesson explained how clock initialization works in STM32 microcontrollers and why it's such an important part of system setup.  
It covered the different clock sources like HSI, HSE, LSI, and LSE, and explained how the RCC (Reset and Clock Control) module is used to manage and switch between them.  

The lesson also introduced the PLL (Phase-Locked Loop) and showed how it can be configured using dividers and multipliers to get the desired system frequency.  
It covered related topics like voltage scaling through the PWR module, flash latency configuration, and how these affect performance and power usage.  

Registers like CR, APB1ENR, and PLLCFGR were mentioned, along with specific bits used to enable or configure features such as HSE, VOS, and FLASH_ACR_LATENCY.  

Learning how all these settings connect gave a clearer picture of how the microcontroller starts up and runs at the correct speed.  
This helped build a better understanding of what actually happens behind the scenes when the system is initialized and prepared to run code.

