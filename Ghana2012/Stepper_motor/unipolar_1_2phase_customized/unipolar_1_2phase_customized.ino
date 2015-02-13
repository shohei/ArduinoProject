//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01
int pin[4] = {10,11,12,13};

//int pin[4] = {3,5,6,9};//for PWM output

int t_delay = 0;
int t_micro = 380;

int unit = 102;// 255*2/5, for 2V output

void setup(){
  for(int i=0;i < 4;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop(){
  rotate();
  //digitalWrite(pin[0],HIGH);
}

void rotate(){
      //STEP1
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP2
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP3
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP4
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP5
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP6
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP7
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP8
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
}
