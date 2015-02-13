#ifndef WProgram_h
#define WProgram_h

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <avr/interrupt.h>

#include "wiring.h"
#include "WString.h"

#ifdef __cplusplus
#include "HardwareSerial.h"

uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned int);
long map(long, long, long, long, long);
#endif

#endif

#if defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644P__)
const static uint8_t A0 = 31;
const static uint8_t A1 = 30;
const static uint8_t A2 = 29;
const static uint8_t A3 = 28;
const static uint8_t A4 = 27;
const static uint8_t A5 = 26;
const static uint8_t A6 = 25;
const static uint8_t A7 = 24;
#endif

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

