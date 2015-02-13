//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01
int pin[4] = {10,11,12,13};

int t_delay = 1;

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
    //STEP2
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    //STEP3
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(t_delay);
    //STEP4
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(t_delay);
}
