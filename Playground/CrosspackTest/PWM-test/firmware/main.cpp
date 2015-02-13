/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include "pwm.h"
#include <util/delay.h>

int main(void){
  Pwm p;
  p.PWM16_init();
  int i;
  while(1){
    for(i=0;i<10;i++){
      p.PWM16_write(i*10);
      _delay_ms(200);
    }   
    for(i=10;i>0;i--){
      p.PWM16_write(i*10);
      _delay_ms(200);
    }   
  }
  return 0;
}

