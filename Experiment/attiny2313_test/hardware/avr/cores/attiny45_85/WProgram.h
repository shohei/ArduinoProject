#ifndef WProgram_h
#define WProgram_h

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <avr/interrupt.h>

#include "wiring.h"

#ifdef __cplusplus
//#include "HardwareSerial.h" // burp

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

#if defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny85__)
const static uint8_t A1 = 7;
const static uint8_t A2 = 3;
const static uint8_t A3 = 2;
#endif

