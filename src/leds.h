#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

void Leds_Create(uint16_t *leds);
void Leds_On(uint8_t n);
void Leds_Off(uint8_t n);
void Leds_AllOn();
void Leds_AllOff();
bool Leds_IsOn(uint8_t n);

#endif
