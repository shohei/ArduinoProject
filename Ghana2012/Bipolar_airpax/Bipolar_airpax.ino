//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01
int pin[4] = {9,10,11,12};

void setup(){
  for(int i=0;i < 4;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop(){
    //STEP1
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(30);
    //STEP1
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(30);

    //STEP2
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(30);
    //STEP2
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(30);

    //STEP3
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], HIGH);
    digitalWrite(pin[3], LOW);
    delay(30);
    //STEP3
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], LOW);
    delay(30);

    //STEP4
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(30);
    //STEP4
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    digitalWrite(pin[2], LOW);
    digitalWrite(pin[3], HIGH);
    delay(30);

}

