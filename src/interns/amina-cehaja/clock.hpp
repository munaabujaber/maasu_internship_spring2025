#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <cstdint>

namespace Clock {

void enablePowerInterface();
void setVoltageScaling(uint32_t scale);
void enableHSE(bool bypass = false);
void enableHSI();
bool isHSEReady();
bool isHSIReady();
void configurePLL(uint32_t pllm, uint32_t plln, uint32_t pllp);
void enablePLL();
bool isPLLReady();
void setFlashLatency(uint32_t latency);
void configureBusPrescalers(uint32_t ahb, uint32_t apb1, uint32_t apb2);
void selectSysClockSource(uint32_t source);
uint32_t getSysClockSource();

void init();

} // namespace Clock

#endif // CLOCK_HPP
