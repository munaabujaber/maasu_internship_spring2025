#include "clock.hpp"
#include "gpio.hpp"
#include "usart.hpp"

int main() {
    Clock::init();

    GPIO::enableClock(GPIOA);

    GPIO::configurePin(GPIOA, 5, GPIO::Mode::Output);  // LED

    GPIO::configurePin(GPIOA, 9, GPIO::Mode::AltFunc, GPIO::OutputType::PushPull,
                       GPIO::Pull::None, GPIO::Speed::VeryHigh, 7);  // USART1_TX

    GPIO::configurePin(GPIOA, 10, GPIO::Mode::AltFunc, GPIO::OutputType::PushPull,
                       GPIO::Pull::None, GPIO::Speed::VeryHigh, 7);  // USART1_RX

    USART::init(USART1, 115200);
    USART::writeString(USART1, "System initialized.\r\n");

    while (true) {
        GPIO::writePin(GPIOA, 5, true);
        for (volatile int i = 0; i < 100000; ++i);
        GPIO::writePin(GPIOA, 5, false);
        for (volatile int i = 0; i < 100000; ++i);
        USART::writeString(USART1, "LED toggled\r\n");
    }

    return 0;
}

