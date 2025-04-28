=============
GPIO Overview
=============

They act as the interface between the microcontroller and external devices.
Each GPIO pin can be configured to either send data out (output mode) or receive data in (input mode), allowing the microcontroller to interact with sensors, LEDs, motors, and more.
GPIO is a foundational skill for embedded development.

GPIO Registers control GPIO operations, and each GPIO port on the microcontroller has its own set of registers.
Key registers include:
MODER (Mode Register):
Defines the functional mode of each pin: input, output, analog, or alternate function.
The MODER register has two bits per pin, with each bit pair representing one of four modes:input mode,General-purpose output mode,alternate function mode,analog mode

PUPDR (Pull-Up/Pull-Down Register):
Controls the input state of the pin, specifying whether it is connected internally to a pull-up resistor, pull-down resistor, or neither (floating).
Each pin has a pair of bits in the PUPDR register, set as follows:No pull-up or pull-down (floating),Pull-up,Pull-down

OTYPER (Output Type Register):
Specifies whether an output pin is configured as push-pull or open-drain.
This setting affects how the pin drives the load:
Push-Pull: The pin can actively drive high and low signals.
Open-Drain: The pin can only drive low; an external pull-up resistor is needed for high logic.

OSPEEDR (Output Speed Register): - Sets the output speed (low, medium, fast, high) for each pin, which also affects the strength ofix the output signal.

AFR (Alternate Function Register): - Configures the pin to work with an alternate function, such as a peripheral interface (e.g., USART, SPI, or PWM).

IDR (Input Data Register): - Used to read the current logical level (high or low) of each input pin, providing real-time data about the state of external signals connected to the pins.

ODR (Output Data Register): - Used to set the logical level of each output pin directly. Writing a high or low value to a bit in ODR changes the output state of the corresponding GPIO pin.

BSRR (Bit Set/Reset Register): - A specialized register that allows setting or clearing individual pins without affecting the other bits in the ODR register.

GPIO Modes and Configurations GPIO pins can be configured in various modes:
Input Mode:
Configures the pin to receive external signals.
When reading sensor data or monitoring signals, input mode is necessary.

Output Mode:
Configures the pin to send data or signals to external devices.
Output pins can be set to either push-pull or open-drain mode, depending on the required drive characteristics.

Analog Mode:
Sets the pin for analog functions, typically used when the pin is connected to an Analog-to-Digital Converter (ADC) or Digital-to-Analog Converter (DAC).
This mode is useful for processing signals from analog sensors.

Alternate Function Mode:
Enables the pin to work with other peripherals like USART, SPI, I2C, timers, and PWM.
Each pin can support multiple alternate functions, which can be selected through the AFR register.

To configure GPIO pins effectively, we need to understand the purpose of each mode and register.

GPIO in Practical Applications GPIO pins provide the hardware interface for microcontrollers to interact with the external world. Here are some practical uses:
Digital Control: - Control devices like LEDs, relays, and small motors. - Output pins are used to send signals, while input pins can detect the status of external digital sensors.
Signal Monitoring: - Used in applications that require monitoring high/low states from external devices (e.g., checking if a door is open or closed).
Communication: - GPIO pins in alternate function mode allow the microcontroller to communicate with other devices using protocols like UART, SPI, and I2C.
PWM (Pulse Width Modulation): - Some GPIO pins can generate PWM signals in alternate function mode, useful for applications like motor control or LED dimming.
Interrupt Handling: - Many GPIO pins can be configured to trigger interrupts on specific events, such as a change in state (e.g., a button press). - Interrupts allow the microcontroller to respond immediately to events, which is essential for responsive systems.

==============================================================================================

The most important features for GPIO in STM32F411xC/E

-Up to 16 I/Os under control
-Modes: Each I/O can be configured as:
Input: Floating, pull-up, pull-down, or analog
Output: Push-pull or open-drain with pull-up or pull-down
Alternate function: Push-pull or open-drain with pull-up/down capability.
-GPIO pins can be set or reset using the GPIOx_BSRR register for efficient control
-The GPIOx_LCKR register locks the configuration to prevent accidental changes
-Output speed for each pin can be selected for optimized performance

Each GPIO pin can be individually configured into one of the following modes:
Input Modes:
Floating: The pin is not connected to any internal resistor and is left floating
Pull-up: The pin is connected to Vdd through a pull-up resistor
Pull-down: The pin is connected to GND through a pull-down resistor
Analog: The pin is set to work with analog signals
Output Modes:
Open-drain: The pin can pull the line low but requires an external pull-up resistor to pull the line high. Can be configured with pull-up or pull-down resistors.
Push-pull: The pin can actively drive both high and low levels. Can also be configured with pull-up or pull-down resistors.
Alternate Function Modes:
Alternate Function Push-pull: The pin is configured for an alternate peripheral function (e.g., UART, SPI) and works in push-pull mode, with the option to use pull-up or pull-down resistors.
Alternate Function Open-drain: The pin is configured for an alternate peripheral function and works in open-drain mode, with the option for pull-up or pull-down resistors.

