//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01
//int pin[4] = {10,11,12,13};//A,B,A-,B-

int pin[4] = {3,5,6,9};//for PWM output

int t_delay = 0;
int t_micro = 300;

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
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],pwmmax);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP2
    analogWrite(pin[0],pwmmax*0.25);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],pwmmax*0.75);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP3
    analogWrite(pin[0],pwmmax*0.5);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],pwmmax*0.5);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP4
    analogWrite(pin[0],pwmmax*0.75);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],pwmmax*0.25);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP5
    analogWrite(pin[0],pwmmax);
    analogWrite(pin[1],0);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP6
    analogWrite(pin[0],pwmmax*0.75);
    analogWrite(pin[1],pwmmax*0.25);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP7
    analogWrite(pin[0],pwmmax*0.5);
    analogWrite(pin[1],pwmmax*0.5);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP8
    analogWrite(pin[0],pwmmax*0.25);
    analogWrite(pin[1],pwmmax*0.75);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP9
    analogWrite(pin[0],0);
    analogWrite(pin[1],pwmmax);
    analogWrite(pin[2],0);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP10
    analogWrite(pin[0],0);
    analogWrite(pin[1],pwmmax*0.75);
    analogWrite(pin[2],pwmmax*0.25);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP11
    analogWrite(pin[0],0);
    analogWrite(pin[1],pwmmax*0.5);
    analogWrite(pin[2],pwmmax*0.5);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP12
    analogWrite(pin[0],0);
    analogWrite(pin[1],pwmmax*0.25);
    analogWrite(pin[2],pwmmax*0.75);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP13
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],pwmmax);
    analogWrite(pin[3],0);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP14
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],pwmmax*0.75);
    analogWrite(pin[3],pwmmax*0.25);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP15
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],pwmmax*0.5);
    analogWrite(pin[3],pwmmax*0.5);
    delay(t_delay);
    delayMicroseconds(t_micro);
    //STEP16
    analogWrite(pin[0],0);
    analogWrite(pin[1],0);
    analogWrite(pin[2],pwmmax*0.25);
    analogWrite(pin[3],pwmmax*0.75);
    delay(t_delay);
    delayMicroseconds(t_micro);
}
