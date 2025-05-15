#pragma once
#include "stm32f4xx.h"

class GPIO {
public:
    enum class Mode { Input = 0b00, Output = 0b01, AltFunc = 0b10, Analog = 0b11 };
    enum class OutputType { PushPull = 0, OpenDrain = 1 };
    enum class Pull { None = 0b00, PullUp = 0b01, PullDown = 0b10 };
    enum class Speed { Low = 0b00, Medium = 0b01, High = 0b10, VeryHigh = 0b11 };

    static void enableClock(GPIO_TypeDef* GPIOx);
    static void configurePin(GPIO_TypeDef* GPIOx, uint32_t pin, Mode mode,
                             OutputType outputType = OutputType::PushPull,
                             Pull pull = Pull::None,
                             Speed speed = Speed::Low,
                             uint8_t altFunc = 0);
    static void writePin(GPIO_TypeDef* GPIOx, uint32_t pin, bool state);
};
