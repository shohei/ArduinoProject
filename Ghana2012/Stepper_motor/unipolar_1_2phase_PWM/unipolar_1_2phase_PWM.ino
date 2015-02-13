//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01
int pin[4] = {10,11,12,13};

//int pin[4] = {3,5,6,9};//for PWM output

int t_delay = 0;
int t_micro = 400;

//int pwmmax = 102;// 255*2/5, for 2V output
int pwmmax = 255; //success
//int pwmmax = 200;

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
    analogWrite(pin[0],pwmmax);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP2
    analogWrite(pin[0],pwmmax);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP3
    analogWrite(pin[0],pwmmax);
    analogWrite(pin[1],pwmmax);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP4
   analogWrite(pin[0],0);
    analogWrite(pin[1],pwmmax);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP5
    analogWrite(pin[0],0);
    analogWrite(pin[1],pwmmax);
    analogWrite(pin[2],pwmmax);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP6
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],pwmmax);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP7
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],pwmmax);
    analogWrite(pin[3],pwmmax);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP8
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],pwmmax);
    delay(t_delay);
    delayMicroseconds(t_micro);
}
