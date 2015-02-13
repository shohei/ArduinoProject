//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01

//OUTPUT pin definition
int pin[4] = {10,11,12,13};

void setup(){
  //OUTPUT pin setting
  for(int i=0;i < 4;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop(){
      //STEP1
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      //STEP2
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      //STEP3
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      //STEP4
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
}
