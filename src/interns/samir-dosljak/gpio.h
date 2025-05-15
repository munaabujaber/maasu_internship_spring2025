#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    GPIO_MODE_INPUT = 0x00,
    GPIO_MODE_OUTPUT = 0x01,
    GPIO_MODE_AF = 0x02,
    GPIO_MODE_ANALOG = 0x03
} GPIO_Mode;

typedef enum
{
    GPIO_OTYPE_PP = 0x00,
    GPIO_OTYPE_OD = 0x01
} GPIO_OType;

typedef enum
{
    GPIO_OSPEED_LOW = 0x00,
    GPIO_OSPEED_MEDIUM = 0x01,
    GPIO_OSPEED_FAST = 0x02,
    GPIO_OSPEED_HIGH = 0x03
} GPIO_OSpeed;

typedef enum
{
    GPIO_NO_PULL = 0x00,
    GPIO_PULL_UP = 0x01,
    GPIO_PULL_DOWN = 0x02
} GPIO_PuPd;

typedef enum
{
    GPIO_AF_0 = 0b0000,
    GPIO_AF_1 = 0b0001,
    GPIO_AF_2 = 0b0010,
    GPIO_AF_3 = 0b0011,
    GPIO_AF_4 = 0b0100,
    GPIO_AF_5 = 0b0101,
    GPIO_AF_6 = 0b0110,
    GPIO_AF_7 = 0b0111,
    GPIO_AF_8 = 0b1000,
    GPIO_AF_9 = 0b1001,
    GPIO_AF_10 = 0b1010,
    GPIO_AF_11 = 0b1011,
    GPIO_AF_12 = 0b1100,
    GPIO_AF_13 = 0b1101,
    GPIO_AF_14 = 0b1110,
    GPIO_AF_15 = 0b1111
}GPIO_AF;

void gpio_init(GPIO_TypeDef *port, uint16_t pin, GPIO_Mode mode, GPIO_OType otype, GPIO_OSpeed ospeed, GPIO_PuPd pupd, GPIO_AF alternate_function);
bool gpio_read_pin(GPIO_TypeDef *port, uint16_t pin);
void gpio_write_pin(GPIO_TypeDef *port, uint16_t pin, bool value);
uint16_t gpio_read_port(GPIO_TypeDef *port);
void gpio_write_port(GPIO_TypeDef *port, uint16_t value);
void gpio_toggle(GPIO_TypeDef *port, uint16_t pin);

#endif