#include "fastio.h"

#define _DELAY_1_9_US __asm__ __volatile__ ("nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"" nop\n\t"); 

#define _WRITE(port, v)     do { if (v) {DIO ##  port ## _PORT -> PIO_SODR = DIO ## port ## _PIN; } else {DIO ##  port ## _PORT->PIO_CODR = DIO ## port ## _PIN; }; } while (0)
#define WRITE(pin,v) _WRITE(pin,v)
#define _READ(pin) (DIO ##  pin ## _PORT->PIO_PDSR & DIO ##  pin ## _PIN ? 1 : 0) // does return 0 or pin value
#define READ(pin) _READ(pin)

#define STEP_COUNT 2000000
#define STEP 2 
#define DIR 3 

int deadtime;
int freq = 2000;

void setup()
{
  pinMode(STEP,OUTPUT);
  pinMode(DIR,OUTPUT);
  pinMode(13,OUTPUT);

  deadtime = 1/freq*1000*1000;
}

void loop()
{
  testCW();
  delay(5000);
  testCCW();
  delay(5000);
}

void testCW(){
  ledOn();
  digitalWrite(DIR,LOW);
  for(int i=0;i<STEP_COUNT;i++){
     doSendPulse();
     delayMicroseconds(deadtime);
  }
  ledOff();
}

void testCCW(){
  ledOn();
  digitalWrite(DIR,HIGH);
  for(int i=0;i<STEP_COUNT;i++){
     doSendPulse();
     delayMicroseconds(deadtime);
  }
  ledOff();
}

void doSendPulse(){
    WRITE(STEP,true);
    _DELAY_1_9_US;
    WRITE(STEP,false);
    _DELAY_1_9_US;
}


void ledOn(){
  digitalWrite(13,HIGH);
}

void ledOff(){
  digitalWrite(13,LOW);
}