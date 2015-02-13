#include "pwm.h"
#include <util/delay.h>

int main(void){
  Pwm::PWM16_init();
  int i;
  while(1){
    for(i=0;i<10;i++){
      Pwm::PWM16_write(i*10);
      _delay_ms(200);
    }
    for(i=10;i>0;i--){
      Pwm::PWM16_write(i*10);
      _delay_ms(200);
    }
  }
}
