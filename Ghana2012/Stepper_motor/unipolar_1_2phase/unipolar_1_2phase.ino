//STEPPER MOTOR DRIVING PROGRAM
//MOTOR ＳＴ－４２ＢＹＧ０２０
//int pin[4] = {10,11,12,13};
int pin[4] = {5,6,7,8};


//int pin[4] = {3,5,6,9};//for PWM output

int t_delay = 0;
//int t_micro = 500;
int t_micro = 500;

int status = 1;

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
 switch(status){
  case 1:
    //STEP1
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 2;
  case 2:
    //STEP2
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 3;
  case 3:
    //STEP3
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 4;
  case 4:
    //STEP4
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 5;
  case 5:
    //STEP5
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 6;
  case 6:
    //STEP6
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 7;
  case 7:
    //STEP7
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 8;
  case 8:
    //STEP8
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 1;
 }
}

void r_rotate(){
 switch(status){
  case 1:
    //STEP1
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 2;
  case 2:
    //STEP2
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 3;
  case 3:
    //STEP3
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 4;
  case 4:
    //STEP4
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 5;
  case 5:
    //STEP5
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 6;
  case 6:
    //STEP6
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 7;
  case 7:
    //STEP7
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 8;
  case 8:
    //STEP8
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    delayMicroseconds(t_micro);
    status = 1;
 }
}
