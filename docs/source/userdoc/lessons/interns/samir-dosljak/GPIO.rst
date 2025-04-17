==============
Lesson 1: GPIO
==============

GPIO (General-Purpose Input/Output) is a module (peripheral) that serves as an interface between a microcontroller and external devices. The GPIO module consists of multiple ports, each with a set of configurable pins (in our case, 16 pins per port). To configure those pins, different registers within the GPIO peripheral are used:

1. **MODER** (Mode Register)
2. **PUPDR** (Pull-Up/Pull-Down Register)
3. **OTYPER** (Output Type Register)
4. **OSPEEDR** (Output Speed Register)
5. **AFR** (Alternate Function Register)
6. **IDR** (Input Data Register)
7. **ODR** (Output Data Register)
8. **BSRR** (Bit Set/Reset Register)

1. **MODER** (Mode Register)  
MODER is a 32-bit register used to define the mode of pins. This is done by setting two bits within the register for each GPIO pin of a specific port. The following are the four modes that every GPIO pin can be in:

- Input mode (00) - the pin is in reading mode, which means it receives digital signals from external sources.
- Output mode (01) - the pin is in writing mode, which means it sends digital signals to external devices.
- Alternate function mode (10) - pins are enabled to work with peripherals like USART, I2C, SPI, and PWM.
- Analog mode (11) - pins can receive or send analog signals and this mode is usually used with ADC (Analog-to-Digital Converter) and DAC (Digital-to-Analog Converter).

2. **PUPDR** (Pull-Up/Pull-Down Register)  
This register defines whether the input pin is internally connected to a pull-up or pull-down resistor, or neither (floating). It also has two bits for each pin:

- 00: Floating (no pull-up or pull-down)
- 01: Pull-Up
- 10: Pull-Down

3. **OTYPER** (Output Type Register)  
This register defines whether the output is set as push-pull or open-drain. Push-pull can drive both low and high logic levels, while open-drain can only drive low and requires an external pull-up resistor to achieve high logic levels.

4. **OSPEEDR** (Output Speed Register)  
Defines output speed as low, medium, fast, or high. The speed also affects the strength of output signals. Lower speeds are clearer but some applications need higher speed to operate in real-time. Higher speed can cause electromagnetic interference and consume more power.

5. **AFR** (Alternate Function Register)  
This register selects which alternate function a pin will use when configured in alternate function mode. It is used to connect GPIO pins to internal peripherals such as USART, SPI, I2C, etc.

6. **IDR** (Input Data Register)  
This register is used to read digital signals from input pins.

7. **ODR** (Output Data Register)  
This register is used to send high or low logic levels to output pins.

8. **BSRR** (Bit Set/Reset Register)  
This register allows atomic setting and resetting of individual output bits without affecting other bits in the same register.

Some of the practical applications where GPIO pins are used include:

- Digital Control  
- Signal Monitoring  
- Communication  
- PWM  
- Interrupt Handling