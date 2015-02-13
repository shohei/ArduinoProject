//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01

//OUTPUT pin definition
int pin[4] = {10,11,12,13};
//INPUT pin definition
//for stepping
int steppin = 3;
//for direction
int dirpin = 4;
//initialize the constant
int number = 1;

void setup(){
  //OUTPUT pin setting
  for(int i=0;i < 4;i++){
    pinMode(pin[i], OUTPUT);
  }
  //INPUT pin setting 
  pinMode(steppin,INPUT); 
  pinMode(dirpin,INPUT);
}

void loop(){
  if(digitalRead(dirpin) == HIGH) {
  // reverse  
  if(digitalRead(steppin) == HIGH){  
  switch(number){
  case 1:
      //STEP4
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      number = 2;
      break;
  case 2:
      //STEP3
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      number = 3;
      break;
  case 3:
      //STEP2
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      number = 4;
      break;
  case 4:
      //STEP1
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      number = 1;
      break;
     }
    }
  } else{
  if(digitalRead(steppin) == HIGH){  
  switch(number){
    case 1:
      //STEP1
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      number = 2;
      break;
    case 2:
      //STEP2
      digitalWrite(pin[0], HIGH);
      digitalWrite(pin[1], LOW);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      number = 3;
      break;    
    case 3:
      //STEP3
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], LOW);
      digitalWrite(pin[3], HIGH);
      number = 4;
      break;
    case 4:
      //STEP4
      digitalWrite(pin[0], LOW);
      digitalWrite(pin[1], HIGH);
      digitalWrite(pin[2], HIGH);
      digitalWrite(pin[3], LOW);
      number = 1;
      break;
     }
    }
  }
}
