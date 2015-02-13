//STEPPER MOTOR DRIVING PROGRAM
//MOTOR 4209L-03-01

//INPUT pin definition
//for step
int xstep = 0;
int ystep = 1;
//for direction
int xdir = 2;
int ydir = 3;
//OUTPUT pin definition
int xpin[4] = {9,10,11,12};
int ypin[4] = {5,6,7,8};

//initialize the constant
int xnum = 1;
int ynum = 1;

void setup(){
  //OUTPUT pin setting
  for(int i=0;i < 4;i++){
    pinMode(xpin[i], OUTPUT);
    pinMode(ypin[i], OUTPUT);
  }
  //INPUT pin setting 
  pinMode(xstep,INPUT); 
  pinMode(xdir,INPUT);
  pinMode(ystep,INPUT);
  pinMode(ydir,INPUT);
}

void loop(){
  //FOR XSTEP
  if(digitalRead(xdir) == HIGH) {
  // reverse  
  if(digitalRead(xstep) == HIGH){  
  switch(xnum){
  case 1:
      //STEP4
      digitalWrite(xpin[0], LOW);
      digitalWrite(xpin[1], HIGH);
      digitalWrite(xpin[2], HIGH);
      digitalWrite(xpin[3], LOW);
      xnum = 2;
      break;
  case 2:
      //STEP3
      digitalWrite(xpin[0], LOW);
      digitalWrite(xpin[1], HIGH);
      digitalWrite(xpin[2], LOW);
      digitalWrite(xpin[3], HIGH);
      xnum = 3;
      break;
  case 3:
      //STEP2
      digitalWrite(xpin[0], HIGH);
      digitalWrite(xpin[1], LOW);
      digitalWrite(xpin[2], LOW);
      digitalWrite(xpin[3], HIGH);
      xnum = 4;
      break;
  case 4:
      //STEP1
      digitalWrite(xpin[0], HIGH);
      digitalWrite(xpin[1], LOW);
      digitalWrite(xpin[2], HIGH);
      digitalWrite(xpin[3], LOW);
      xnum = 1;
      break;
     }
    }
  } else{
  if(digitalRead(xstep) == HIGH){  
  switch(xnum){
    case 1:
      //STEP1
      digitalWrite(xpin[0], HIGH);
      digitalWrite(xpin[1], LOW);
      digitalWrite(xpin[2], HIGH);
      digitalWrite(xpin[3], LOW);
      xnum = 2;
      break;
    case 2:
      //STEP2
      digitalWrite(xpin[0], HIGH);
      digitalWrite(xpin[1], LOW);
      digitalWrite(xpin[2], LOW);
      digitalWrite(xpin[3], HIGH);
      xnum = 3;
      break;    
    case 3:
      //STEP3
      digitalWrite(xpin[0], LOW);
      digitalWrite(xpin[1], HIGH);
      digitalWrite(xpin[2], LOW);
      digitalWrite(xpin[3], HIGH);
      xnum = 4;
      break;
    case 4:
      //STEP4
      digitalWrite(xpin[0], LOW);
      digitalWrite(xpin[1], HIGH);
      digitalWrite(xpin[2], HIGH);
      digitalWrite(xpin[3], LOW);
      xnum = 1;
      break;
     }
    }
  }

  //FOR YSTEP
  if(digitalRead(ydir) == HIGH) {
  // reverse  
  if(digitalRead(ystep) == HIGH){  
  switch(ynum){
  case 1:
      //STEP4
      digitalWrite(ypin[0], LOW);
      digitalWrite(ypin[1], HIGH);
      digitalWrite(ypin[2], HIGH);
      digitalWrite(ypin[3], LOW);
      ynum = 2;
      break;
  case 2:
      //STEP3
      digitalWrite(ypin[0], LOW);
      digitalWrite(ypin[1], HIGH);
      digitalWrite(ypin[2], LOW);
      digitalWrite(ypin[3], HIGH);
      ynum = 3;
      break;
  case 3:
      //STEP2
      digitalWrite(ypin[0], HIGH);
      digitalWrite(ypin[1], LOW);
      digitalWrite(ypin[2], LOW);
      digitalWrite(ypin[3], HIGH);
      ynum = 4;
      break;
  case 4:
      //STEP1
      digitalWrite(ypin[0], HIGH);
      digitalWrite(ypin[1], LOW);
      digitalWrite(ypin[2], HIGH);
      digitalWrite(ypin[3], LOW);
      xnum = 1;
      break;
     }
    }
  } else{
  if(digitalRead(ystep) == HIGH){  
  switch(ynum){
    case 1:
      //STEP1
      digitalWrite(ypin[0], HIGH);
      digitalWrite(ypin[1], LOW);
      digitalWrite(ypin[2], HIGH);
      digitalWrite(ypin[3], LOW);
      ynum = 2;
      break;
    case 2:
      //STEP2
      digitalWrite(ypin[0], HIGH);
      digitalWrite(ypin[1], LOW);
      digitalWrite(ypin[2], LOW);
      digitalWrite(ypin[3], HIGH);
      ynum = 3;
      break;    
    case 3:
      //STEP3
      digitalWrite(ypin[0], LOW);
      digitalWrite(ypin[1], HIGH);
      digitalWrite(ypin[2], LOW);
      digitalWrite(ypin[3], HIGH);
      ynum = 4;
      break;
    case 4:
      //STEP4
      digitalWrite(ypin[0], LOW);
      digitalWrite(ypin[1], HIGH);
      digitalWrite(ypin[2], HIGH);
      digitalWrite(ypin[3], LOW);
      ynum = 1;
      break;
     }
    }
  }

}
