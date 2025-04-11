=================
Lesson 2 - GPIO
=================

General-Purpose Input/Output (GPIO) pins are essential in embedded systems, serving as the interface between the microcontroller and external components such as sensors, LEDs, motors and more. Each GPIO pin can function as either an input or output.

GPIO registers
--------------

GPIO functionality is managed through specific registers, with each GPIO port having its own set:

- **MODER (Mode Register):** Configures each pin as input, output, analog, or alternate function.
  - 00: Input
  - 01: Output
  - 10: Alternate function
  - 11: Analog

- **PUPDR (Pull-Up/Pull-Down Register):** Sets pull-up, pull-down, or floating input states.
  - 00: Floating
  - 01: Pull-up
  - 10: Pull-down

- **OTYPER (Output Type Register):** Sets pin output type.
  - Push-Pull: Drives both high and low
  - Open-Drain: Drives low only (needs external pull-up)

- **OSPEEDR (Output Speed Register):** Controls pin output speed (low to high).

- **AFR (Alternate Function Register):** Assigns alternate peripheral functions.
  - Split into AFRL (pins 0–7) and AFRH (pins 8–15)

- **IDR (Input Data Register):** Reads current input state (high/low).

- **ODR (Output Data Register):** Sets output value for each pin.

- **BSRR (Bit Set/Reset Register):** Atomically sets or resets pins without affecting others.

GPIO Modes and Configuration
-----------------------------

- **Input Mode:** For reading external signals. May use pull-up/down resistors.
- **Output Mode:** Sends signals to external components; can be push-pull or open-drain.
- **Analog Mode:** Used for ADC/DAC operations with analog signals.
- **Alternate Function Mode:** Enables peripherals (e.g., UART, SPI, I2C, PWM).

GPIO in Practice
----------------

- **Digital Control:** Control LEDs, motors, relays.
- **Signal Monitoring:** Detect external events like button presses or sensor triggers.
- **Communication:** Use GPIOs with alternate functions for UART, SPI, I2C.
- **PWM:** Generate PWM signals for motor control or LED dimming.
- **Interrupts:** React to real-time events with GPIO-triggered interrupts.

Best Practices
--------------

- Use **BSRR** for atomic operations to avoid race conditions.
- Proper configuration of modes and registers ensures reliable GPIO behavior in embedded systems.

Summary
-------

GPIOs are foundational in embedded design, enabling interaction between microcontrollers and the external world. Mastery of GPIO configuration is key to building efficient, responsive, and reliable systems.
