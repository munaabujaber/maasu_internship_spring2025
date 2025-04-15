=============
GPIO Overview
=============

They act as the interface between the microcontroller and external devices.
Each GPIO pin can be configured to either send data out (output mode) or receive data in (input mode), 
allowing the microcontroller to interact with sensors, LEDs, motors, and more.
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

    ODR (Output Data Register): - Used to set the logical level of each output pin directly. 
    Writing a high or low value to a bit in ODR changes the output state of the corresponding GPIO pin.

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

Each I/O port bit is freely programmable, however the I/O port registers have to be
accessed as 32-bit words, half-words or bytes. The purpose of the GPIOx_BSRR register is
to allow atomic read/modify accesses to any of the GPIO registers.


When the system is reset (just powered on or after a reset), all the GPIO pins are set to input floating mode.
This means the pins are not connected to anything internally, so they can "float" (have an undefined state) unless you specifically configure them.

When a GPIO pin is configured as an output, the value you write to the Output Data Register (GPIOx_ODR) will be sent to the pin. 
This means if you set a bit in the register to 1 or 0, the corresponding pin will output that value.
The pin can be in two output modes:
    Push-pull mode: The pin can drive both high and low values.
    Open-drain mode: The pin can only pull the line low (when the pin is set to 0), and it needs an external pull-up resistor to pull the line high when it's not actively driven.

The Input Data Register (GPIOx_IDR) reads the value from the GPIO pin.
The value of the pin (whether it's high or low) is sampled on each AHB clock cycle (this happens continuously).

All GPIO pins have weak internal pull-up and pull-down resistors.
These resistors can be enabled or disabled through the GPIOx_PUPDR register.
    Pull-up: The resistor pulls the pin to a high state (Vdd).
    Pull-down: The resistor pulls the pin to a low state (GND).
    These internal resistors are useful for setting the default state of the pin when it's not actively driven.

The microcontroller has pins that can be connected to onboard peripherals.Each pin is connected to a multiplexer which can route pin's function to diffrent peripherals,
but only one function can be active at a time on each pin.
Each pin has 16 alternate functions(AF0 TO AF15).
After reset all pins are connected to AF0 which is default alternate function.
AF1 to AF13-these are mapped to various peripherals and functionalities(UART,SPI..).
AF15 - specifically used for Cortex-M4 with FPU EVENTOUT.

Peripherals have alternate functions that can be mapped to diffrent I/O pins allowing efficient use of available pins.
To connect pin to a system function - AF0:
    JTAG/SWD pins-after a reset,these pins are reserverd for debbuging(not controlled by GPIO)
    RTC_REFIN - this pin should be in input floating mode
    MCO1 and MCO2 - these need to be configured in alternate function mode

We can configure wanted I/O  as output or input  in the GPIOx_MODER register.

Peripheral alternate function:
For the ADC, configure the desired I/O as analog in the GPIOx_MODER register.
For other peripherals:
  Configure the desired I/O as an alternate function in the GPIOx_MODER register
  Select the type, pull-up/pull-down and output speed via the GPIOx_OTYPER,
  GPIOx_PUPDR and GPIOx_OSPEEDR registers
  Connect the I/O to the desired AFx in the GPIOx_AFRL or GPIOx_AFRH register


GPIO Control Registers:
    GPIOx_MODER: Configures the I/O direction (input, output, alternate function, or analog).
    GPIOx_OTYPER: Defines the output type (push-pull or open-drain).
    GPIOx_OSPEEDR: Configures the speed of the I/O pin.
    GPIOx_PUPDR: Configures the pull-up or pull-down resistors for the I/O.

I/O Port Data Registers:
    GPIOx_ODR: Output Data Register, where data to be output is stored (read/write accessible).
    GPIOx_IDR: Input Data Register, where input data is stored (read-only).

Bitwise Handling (GPIOx_BSRR):
    GPIOx_BSRR allows you to set or reset individual bits in GPIOx_ODR.
    Atomic operation: It allows bitwise manipulation without the need for disabling interrupts. Writing to GPIOx_BSRR does not lock the bits, and they can be accessed directly.

GPIO Locking Mechanism:
    GPIOx_LCKR: The lock register freezes the configuration of GPIO pins. After a correct sequence, it locks the configuration until the next reset.
    The LOCK sequence requires a 32-bit access to ensure that bits in the control registers cannot be modified after being locked.

Alternate Function (AF) Input/Output:
    GPIOx_AFRL and GPIOx_AFRH: Registers that allow you to select from 16 alternate functions for each I/O pin.
    These alternate functions can be peripherals like UART, SPI, etc., and you can only select one function for each pin at a time.

External Interrupts/Wakeup:
    All GPIO ports can be configured to handle external interrupts. The pin must be in input mode for this.
    The configuration for wake-up events is handled by the EXTI module.

Input Configuration:
    When an I/O is set as an input:
        The output buffer is disabled.
        The Schmitt trigger input is enabled.
        The pull-up/pull-down resistors are activated depending on the GPIOx_PUPDR setting.
        The input data is sampled every clock cycle and can be read from the GPIOx_IDR.

Output Configuration:
    When the I/O port is programmed as output:
        The output buffer is enabled
        The Schmitt trigger input is activated.
        The weak pull-up and pull-down resistors are activated.
        The data present on the I/O pin are sampled into the input data register every AHB clock cycle
        A read access to the input data register gets the I/O state
        A read access to the output data register gets the last written value

Alternate function configuration
    When the I/O port is programmed as alternate function:
        The output buffer can be configured as open-drain or push-pull
        The output buffer is driven by the signal coming from the peripheral (transmitter enable and data)
        The Schmitt trigger input is activated
        The weak pull-up and pull-down resistors are activated or not depending on the valuein the GPIOx_PUPDR register
        The data present on the I/O pin are sampled into the input data register every AHBclock cycle
        A read access to the input data register gets the I/O state

Analog configuration
    When the I/O port is programmed as analog configuration:
        The output buffer is disabled
        The Schmitt trigger input is deactivated, providing zero consumption for every analogalue of the I/O pin. 
        The output of the Schmitt trigger is forced to a constant value (0).
        The weak pull-up and pull-down resistors are disabled
        Read access to the input data register gets the value “0”

        