#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <cstdint>

// Enumeracije za Flash latency i voltage scaling
enum class FlashLatency {
    _0ws = 0,
    _1ws = 1,
    _2ws = 2,
    _3ws = 3,
    _4ws = 4,
    _5ws = 5,
    _6ws = 6,
    _7ws = 7
};

enum class VoltageScale {
    Scale3 = 0b00,
    Scale2 = 0b01,
    Scale1 = 0b11
};

// Struktura za konfiguraciju clock sistema
struct ClockConfig {
    uint32_t pll_n;
    uint32_t pll_p;
    FlashLatency flash_latency;
    VoltageScale voltage_scale;
};

// Funkcije za inicijalizaciju
void clock_init(const ClockConfig& config);
void clock_init_100MHz(void);

#endif // CLOCK_HPP
