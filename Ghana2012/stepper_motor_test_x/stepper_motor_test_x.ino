//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01

//rotate six and a half
#define MAX 1000

//OUTPUT pin definition
int pin[4] = {5,6,7,8};

int delay_t = 5;

void setup(){
  //OUTPUT pin setting
  for(int i=0;i < 4;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop(){

//  stepping_reverse();

  for(int i = 0;i< MAX;i++){
       stepping();
    }
    for(int i = 0;i< MAX;i++){
       stepping_reverse();
    }

    while(1){
    }

}

void stepping(){
        //STEP1
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      delay(delay_t);
      //STEP2
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      delay(delay_t);
      //STEP3
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      delay(delay_t);
      //STEP4
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      delay(delay_t);
}

void stepping_reverse(){
      //STEP4
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      delay(delay_t);
      //STEP3
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      delay(delay_t);
      //STEP2
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      delay(delay_t);
        //STEP1
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      delay(delay_t);
}


