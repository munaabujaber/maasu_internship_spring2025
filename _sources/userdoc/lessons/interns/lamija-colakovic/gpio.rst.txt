====
GPIO
====
GPIO(General Purpose Input/Output) represents the interface between externals and devices and microcontroller. Each GPIO pin can receive data as an input or 
send data as an output. They include key registers:

1. MODER (Mode Register):
Mod Register defines the four functional modes: input, output, analog and alternate function.
Input mode configures the pin to receive external signals.

Output mode configures the pin to send data or signals to external devices.

Analog mode sets the pin for analog functions, typically used when the pin is connected to an Analog-to-Digital Converter (ADC) 
or Digital-to-Analog Converter (DAC).

Alternate Function mode enables the pin to work with other peripherals like USART, SPI, I2C, timers, and PWM.

2. PUPDR (Pull-Up/Pull-Down Register):
Controls the input state of the pin. Each pin has a pair of bits in the PUPDR register, such as: No pull-up or pull-down,
pull-up and pull down.

3. OTYPER (Output Type Register):

Specifies whether an output pin is configured as push-pull or open-drain.
Push-Pull: The pin can actively drive high and low signals.
Open-Drain: The pin can only drive low.

OSPEEDR (Output Speed Register): - Sets the output speed for each pin.

AFR (Alternate Function Register): - Configures the pin to work with an alternate function, such as a peripheral interface (e.g., USART, SPI, or PWM).

IDR (Input Data Register): - Used to read the current logical level (high or low) of each input pin.

ODR (Output Data Register): - Used to set the logical level of each output pin directly.

BSRR (Bit Set/Reset Register): - A specialized register that allows setting or clearing individual pins without affecting the other bits in the ODR register.

Practical uses of GPIO:

Digital Control: - Control devices like LEDs, relays, and small motors.

Signal Monitoring: - Used in applications that require monitoring high/low states from external devices (e.g., checking if a door is open or closed). 

Communication: -Alternate function configurations enable dedicated communication lines, with each GPIO pin mapped to specific peripheral functions.

PWM (Pulse Width Modulation): - PWM signals adjust duty cycles to control the power delivered to connected devices.

Interrupt Handling: - Interrupts allow the microcontroller to respond immediately to events, which is essential for responsive systems... data as an output. They include key registers:

1. MODER (Mode Register):
Mod Register defines the four functional modes: input, output, analog and alternate function.
Input mode configures the pin to receive external signals.

Output mode configures the pin to send data or signals to external devices.

Analog mode sets the pin for analog functions, typically used when the pin is connected to an Analog-to-Digital Converter (ADC) 
or Digital-to-Analog Converter (DAC).

Alternate Function mode enables the pin to work with other peripherals like USART, SPI, I2C, timers, and PWM.

2. PUPDR (Pull-Up/Pull-Down Register):
Controls the input state of the pin. Each pin has a pair of bits in the PUPDR register, such as: No pull-up or pull-down,
pull-up and pull down.

3. OTYPER (Output Type Register):

Specifies whether an output pin is configured as push-pull or open-drain.
Push-Pull: The pin can actively drive high and low signals.
Open-Drain: The pin can only drive low.

OSPEEDR (Output Speed Register): - Sets the output speed for each pin.

AFR (Alternate Function Register): - Configures the pin to work with an alternate function, such as a peripheral interface (e.g., USART, SPI, or PWM).

IDR (Input Data Register): - Used to read the current logical level (high or low) of each input pin.

ODR (Output Data Register): - Used to set the logical level of each output pin directly.

BSRR (Bit Set/Reset Register): - A specialized register that allows setting or clearing individual pins without affecting the other bits in the ODR register.

Practical uses of GPIO:

Digital Control: - Control devices like LEDs, relays, and small motors.

Signal Monitoring: - Used in applications that require monitoring high/low states from external devices (e.g., checking if a door is open or closed). 

Communication: -Alternate function configurations enable dedicated communication lines, with each GPIO pin mapped to specific peripheral functions.

PWM (Pulse Width Modulation): - PWM signals adjust duty cycles to control the power delivered to connected devices.

Interrupt Handling: - Interrupts allow the microcontroller to respond immediately to events, which is essential for responsive systems...