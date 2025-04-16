================
Lesson 2 - GPIO
================


General- Purpose Input/Output pins are one of the most crucial parts of embedded systems, since they represent the interface between any external device and the microcontroller. GPIO can be configured in input or output mode. Output - sends data, while input - receives data. This is important for interaction with sensors, monitors etc. GPIO pins are used often because it serves many roles, often simultaneously with an application.

GPIO registers control the operations on GPIO and each GPIO port on microcontroller has its own set of registers which are configured by developers individually or as a group.
**Key registers are :** 

- mode register (MODER)
- pull-up/pull-down register (PUPDR)
- output type register (OTYPER)
- output speed register (OSPEEDR)
- alternative function register (AFR)
- input data register (IDR)
- output data register (ODR)
- bit set/reset register (BSRR)

1. mode register (MODER) - used for defining functional mode of each pin: input 00, general-purpose output 01, alternate function 10, analog 11

2. pull-up/pull-down register (PUPDR) - controls input state of the pin, specifies whether connection is internally to a pull-up resistor 01, pull-down resistor 10 or floating mode (neither) 00.

3. output type register (OTYPER) - specifies if an output pin is configured as push-pull (can actively drive high and low signals) or open-drain (pin can only drive low, an external pull-up resistor is needed for high logic.

4. The output speed register (OSPEEDR) is used to set how quickly a GPIO pin can change its output state. You can choose between low, medium, fast, or high speed. This affects how fast signals are sent from the microcontroller to other components. High-speed settings are useful when transferring data rapidly, but they also increase power consumption and can cause more electromagnetic interference, which might affect nearby electronics. So, when speed matters, you can go for a higher setting—but if not, using lower speeds is more efficient.

5. The alternate function register (AFR) allows a GPIO pin to act as something more than just input or output. For example, it can be connected to other parts of the microcontroller like serial communication (USART), SPI, I2C, timers, or PWM outputs. This is how we enable communication between the microcontroller and other external devices or modules. The AFR is actually divided into two parts: AFRL, which is used for pins 0 to 7, and AFRH, which is used for pins 8 to 15. Each pin is assigned 4 bits to select the specific alternate function you want it to perform.

6. The input data register (IDR) is used to read the current state of input pins. When you connect something like a button or a sensor to a pin configured in input mode, IDR tells you whether that pin is currently in a high (1) or low (0) state. This is useful for detecting if an external event has happened—like a button press or a change in sensor output.

7. The output data register (ODR) is the opposite of IDR. It is used to manually set the value of output pins. If you want to turn an LED on or off, for example, you write a value to the corresponding bit in the ODR register. Setting the bit to 1 drives the pin high, and setting it to 0 drives it low. This directly controls the signal sent out of the pin.

8. The bit set/reset register (BSRR) is a more efficient and safer way to change the state of specific output pins. Instead of changing the entire ODR register and possibly affecting other pins, the BSRR lets you set or reset individual pins independently. Writing to the lower half of the register sets a pin high, while writing to the upper half resets it to low. This is especially useful in time-sensitive or interrupt-heavy applications, because it ensures that only the targeted pin is affected in a single atomic operation.


Next, GPIO pins can be used in different modes, depending on what kind of job the pin needs to do. Understanding each of these modes helps you configure your microcontroller correctly.

- Input mode is used when the pin needs to receive signals, like reading data from a sensor or detecting if a button was pressed. Input pins are often connected to pull-up or pull-down resistors to ensure they stay in a known state when nothing is connected.

- Output mode is when the pin needs to send signals out, like turning on an LED or controlling a motor. In this mode, you can choose between two types: push-pull and open-drain. Push-pull can drive the pin both high and low, making it suitable for most basic applications. Open-drain, on the other hand, can only pull the pin low—it needs an external pull-up resistor to go high. This is useful when multiple devices share the same line.

- Analog mode is selected when the pin is connected to analog functions like ADC (Analog-to-Digital Converter) or DAC (Digital-to-Analog Converter). This is necessary when reading values from analog sensors or generating analog outputs.

- Alternate function mode is used when the pin should work with another peripheral. For example, to use a pin for communication over UART or SPI, you’d select this mode and configure the AFR register accordingly. Each pin can support different alternate functions depending on the microcontroller.

To configure GPIO correctly in a real project, you need to combine multiple registers. For example, if you’re setting up a pin as an output, you’ll define the mode in MODER, choose the output type in OTYPER, and adjust the speed using OSPEEDR. If you’re configuring it as an input, you might enable a pull-up or pull-down resistor through the PUPDR register, based on whether you want the default state to be high or low.

Many GPIOs can trigger interrupts. This means the microcontroller doesn’t need to constantly check the pin state—it can "sleep" and be alerted instantly when something important happens, like a button press. This is key for making systems more efficient and responsive.

In summary, GPIOs are essential for making embedded systems interactive. Whether you’re reading sensor data, sending control signals, or enabling communication with other devices, understanding how to use the GPIO registers and modes gives you full control over hardware behavior. Learning how to configure these pins properly is one of the most important steps in mastering embedded development.

**My key takeaways from this lesson:**

- I have learnt what GPIO are, how to deal with them and when to use each of the kinds, I have already had some knowledge from Operating Systems course during my studies, but this made it easier for me to understand everything to the core.
- As external sources for writing this docs, I have used documentation provided by Maasu, Oracle official page and my Operating Systems coursebook.

