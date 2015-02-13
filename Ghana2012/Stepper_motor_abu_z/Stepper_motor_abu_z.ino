//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01

//INPUT pin definition
//for step
int zstep = 0;
//for direction
int zdir = 1;
//OUTPUT pin definition
int zpin[4] = {2,3,4,5};

//initialize the constant
int znum = 1;

void setup(){
  //OUTPUT pin setting
  for(int i=0;i < 4;i++){
    pinMode(zpin[i], OUTPUT);
  }
  //INPUT pin setting 
  pinMode(zstep,INPUT); 
  pinMode(zdir,INPUT);
}

void loop(){
  //FOR zstep
  if(digitalRead(zdir) == HIGH) {
  // reverse  
  if(digitalRead(zstep) == HIGH){  
  switch(znum){
  case 1:
      //STEP4
      digitalWrite(zpin[0], LOW);
      digitalWrite(zpin[1], HIGH);
      digitalWrite(zpin[2], HIGH);
      digitalWrite(zpin[3], LOW);
      znum = 2;
      break;
  case 2:
      //STEP3
      digitalWrite(zpin[0], LOW);
      digitalWrite(zpin[1], HIGH);
      digitalWrite(zpin[2], LOW);
      digitalWrite(zpin[3], HIGH);
      znum = 3;
      break;
  case 3:
      //STEP2
      digitalWrite(zpin[0], HIGH);
      digitalWrite(zpin[1], LOW);
      digitalWrite(zpin[2], LOW);
      digitalWrite(zpin[3], HIGH);
      znum = 4;
      break;
  case 4:
      //STEP1
      digitalWrite(zpin[0], HIGH);
      digitalWrite(zpin[1], LOW);
      digitalWrite(zpin[2], HIGH);
      digitalWrite(zpin[3], LOW);
      znum = 1;
      break;
     }
    }
  } else{
  if(digitalRead(zstep) == HIGH){  
  switch(znum){
    case 1:
      //STEP1
      digitalWrite(zpin[0], HIGH);
      digitalWrite(zpin[1], LOW);
      digitalWrite(zpin[2], HIGH);
      digitalWrite(zpin[3], LOW);
      znum = 2;
      break;
    case 2:
      //STEP2
      digitalWrite(zpin[0], HIGH);
      digitalWrite(zpin[1], LOW);
      digitalWrite(zpin[2], LOW);
      digitalWrite(zpin[3], HIGH);
      znum = 3;
      break;    
    case 3:
      //STEP3
      digitalWrite(zpin[0], LOW);
      digitalWrite(zpin[1], HIGH);
      digitalWrite(zpin[2], LOW);
      digitalWrite(zpin[3], HIGH);
      znum = 4;
      break;
    case 4:
      //STEP4
      digitalWrite(zpin[0], LOW);
      digitalWrite(zpin[1], HIGH);
      digitalWrite(zpin[2], HIGH);
      digitalWrite(zpin[3], LOW);
      znum = 1;
      break;
     }
    }
  }

}
