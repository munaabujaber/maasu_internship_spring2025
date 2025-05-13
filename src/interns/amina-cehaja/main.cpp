#include "clock.hpp"
#include "gpio.hpp"
#include "usart.hpp"

// System ticks
uint32_t ticks = 0;

// SysTick handler
void systick_handler() {
    ticks++;
}

// Delay function using system ticks
void delay_ms(const uint32_t &ms) {
    uint32_t start = ticks;
    uint32_t end = start + ms;

    // Check overflow
    if (end < start)
        while (ticks > start);

    // Wait for ticks to wrap around to zero
    while (ticks < end);
}

int main() {
    // Set HSE frequency and PLL settings for 100 MHz system clock
    uint32_t hse_freq = 25000000;   // 25 MHz HSE
    uint32_t pll_n = 400;           // PLL multiplier (for 100 MHz)
    uint32_t pll_m = 25;            // PLL divider
    uint32_t pll_p = 2;             // PLLP divider

    // Initialize clock with flexible parameters
    Clock::init(hse_freq, pll_n, pll_m, pll_p);

    // Assuming the system clock is now 100 MHz after PLL setup
    uint32_t system_clock = 100000000;  // 100 MHz

    // Enable GPIOA clock and configure pins
    GPIO::enableClock(GPIOA);

    // Configure pins
    GPIO::configurePin(GPIOA, 5, GPIO::Mode::Output);  // LED pin
    GPIO::configurePin(GPIOA, 9, GPIO::Mode::AltFunc, GPIO::OutputType::PushPull,
                       GPIO::Pull::None, GPIO::Speed::VeryHigh, 7);  // USART1_TX
    GPIO::configurePin(GPIOA, 10, GPIO::Mode::AltFunc, GPIO::OutputType::PushPull,
                       GPIO::Pull::None, GPIO::Speed::VeryHigh, 7);  // USART1_RX

    // Initialize USART1 with a baudrate of 115200
    USART::init(USART1, 115200, system_clock);  // Pass system clock here
    USART::writeString(USART1, "System initialized.\r\n");

    // SysTick timer configuration for 1 ms interval (if SysTick is 1 ms)
    SysTick_Config(system_clock / 1000);  // Assuming 100 MHz SYSCLK

    // Main loop
    while (true) {
        GPIO::writePin(GPIOA, 5, true);  // Turn on LED
        delay_ms(500);                   // Delay 500 ms
        GPIO::writePin(GPIOA, 5, false); // Turn off LED
        delay_ms(500);                   // Delay 500 ms
        USART::writeString(USART1, "LED toggled\r\n");
    }

    return 0;
}