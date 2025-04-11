====================
Lesson 2 - GPIO
====================

General Overview
----------------
Basically like, GPIO pins are like the *“doors”* on your microcontroller that let it talk to the outside world.


You could use these pins to send or receive signals, depending on what you need:

-- If you're sending data to something like an LED or a motor, you would set the pin to output mode. 

-- If you're reading data from something like a sensor or a button, you would set it to input mode. 

These pins seem super versatile, which is why they're used in almost every project I would guess.

GPIO Registers
--------------
Each GPIO pin has its own set of “controls” that let you decide how it should behave. 
These controls are stored in registers, and they can be adjusted to suit your needs. 
Here are the important ones:

- **Mode Register (MODER)**: This tells the pin what it’s supposed to do. Should it act as an input, an output, or do something special like communicate with a sensor?
- **Pull-up/Pull-down Register (PUPDR)**: If you're reading from a pin, this register decides whether it should pull the signal high (pull-up), low (pull-down), or leave it floating (no resistance).
- **Output Type Register (OTYPER)**: This defines how the output behaves. A pin can either push the signal both high and low (push-pull), or only push the signal low (open-drain, which needs an extra pull-up resistor).
- **Output Speed Register (OSPEEDR)**: This sets how fast the pin can change its signal. Some pins can handle faster changes than others, but this comes at the cost of more power and possible interference.
- **Alternate Function Register (AFR)**: Some pins can be used for special tasks like serial communication (UART), SPI, or I2C. This register sets them up for those tasks.
- **Input Data Register (IDR)**: This reads the value of the input pins. It's like asking, “Hey, is the button pressed, or is the sensor value high or low?”
- **Output Data Register (ODR)**: This is where you set the output pins. If you want the pin to be high, you write a `1`; if you want it low, you write a `0`.
- **Bit Set/Reset Register (BSRR)**: This is a neat way to change the state of individual pins without messing with the rest.

Detailed Explanation of Key Registers
-------------------------------------
- The **Mode Register (MODER)** is like a pin's job description.  You can set it to input mode, general output, alternate function, or analog. The values look like this: `00` means input, `01` means output, `10` is for special functions, and `11` is for analog signals.

- The **Pull-up/Pull-down Register (PUPDR)** helps when you're reading from a pin. It decides whether the pin should have a built-in resistor to pull the signal up or down, or if it should just float with no pull at all.For example, `01` sets a pull-up resistor, and `10` sets a pull-down resistor.

- The **Output Type Register (OTYPER)** controls how the output pin behaves. If you want it to actively drive both high and low signals (like a typical on/off switch), you use push-pull. If you only want the pin to go low and need an external resistor to make it high, you use open-drain.

- The **Output Speed Register (OSPEEDR)** controls how quickly the pin can change. This could be low, medium, fast, or high speed. Faster changes are useful for tasks that need quick data, but it also uses more power and can cause interference.

- The **Alternate Function Register (AFR)** is where you tell the pin to perform special functions like serial communication (UART), SPI, or I2C.  It’s split into two sections: AFRL (for pins 0 to 7) and AFRH (for pins 8 to 15).

- The **Input Data Register (IDR)** is where you check the current state of the input pin.  This is useful if you want to know if a button has been pressed or if a sensor is giving a high or low reading.

- The **Output Data Register (ODR)** lets you set the output pin to a high or low state. Just write a `1` to set it high and a `0` to set it low.

- The **Bit Set/Reset Register (BSRR)** is a quicker way to set or reset pins. Instead of writing to the whole register, you can directly change a specific pin, making it more efficient.

GPIO Pin Modes
--------------
There are several ways to set up GPIO pins, depending on what you need them to do. 


- In input mode, the pin can receive signals, like reading from a sensor or detecting a button press. 

- In output mode, the pin sends signals, such as turning on an LED or controlling a motor. 

There are two types of output modes: **push-pull** *(where the pin can go both high and low)* and **open-drain** *(where the pin only goes low and needs an external pull-up resistor to go high)*. 


You can also set pins to analog mode for things like Analog-to-Digital Conversion (ADC) or Digital-to-Analog Conversion (DAC). 

Finally, alternate function mode is used for special tasks like serial communication or timer control, which you could configure through the AFR register.

GPIO Interrupts
---------------
GPIO pins can also trigger interrupts, meaning they can make the microcontroller wake up and do something important, like handling a button press. 
This would be super useful for saving power because the microcontroller can sleep until something important happens, making the system more efficient.

Key Takeaways
--------------
**GPIOs are key to making embedded systems interactive.** Understanding how to configure them is crucial for controlling your hardware. 
Whether you're reading sensor data, turning on LEDs, or setting up communication, GPIO pins make it all possible. :)