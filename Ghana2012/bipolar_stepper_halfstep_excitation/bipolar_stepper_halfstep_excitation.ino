int EN_A = 10;
int EN_B = 11;
int SA = 12;
int SB = 13;

int status = 1;

int t_delay = 1;
int t_micro = 2000;


void setup(){
  pinMode(EN_A,OUTPUT);//STAND BY FOR A
  pinMode(EN_B,OUTPUT);//STAND BY FOR B
  pinMode(SA,OUTPUT);//SIGNAL FOR A
  pinMode(SB,OUTPUT);//SIGNAL FOR B
}

void loop(){
rotate();
/*  
for(int i=0;i<10000;i++){
  rotate();
}  
for(int i=0;i<10000;i++){
  r_rotate();
}  
*/

}

void rotate(){
  
switch(status){
//HALF STEP EXCITATION
  case 1:
    //STEP1
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,LOW);
    digitalWrite(SA,HIGH);
    delayMicroseconds(t_micro);
    status = 2;
    break;
  case 2:
    //STEP2
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,HIGH);
    status = 3;
    delayMicroseconds(t_micro);
    break;
  case 3:
    //STEP3
    digitalWrite(EN_A,LOW);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SB,HIGH);
    status = 4;
    delayMicroseconds(t_micro);
    break;
  case 4:
    //STEP4
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,HIGH);
    delayMicroseconds(t_micro);
    status = 5;
    break;   
  case 5:
    //STEP5
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,LOW);
    digitalWrite(SA,LOW);
    delayMicroseconds(t_micro);
    status = 6;
    break;
  case 6:
    //STEP6
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,LOW);
    delayMicroseconds(t_micro);
    status = 7;
    break;
  case 7:
    //STEP7
    digitalWrite(EN_A,LOW);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SB,LOW);
    delayMicroseconds(t_micro);
    status = 8;
    break;
  case 8:
    //STEP8
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,LOW);
    delayMicroseconds(t_micro);
    status = 1;
    break;   
  }
}


void r_rotate(){
switch(status){
//HALF STEP EXCITATION
  case 1:
    //STEP1
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,LOW);
    digitalWrite(SA,HIGH);
    delayMicroseconds(t_micro);
    status = 8;
    break;
  case 2:
    //STEP2
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,HIGH);
    status = 1;
    delayMicroseconds(t_micro);
    break;
  case 3:
    //STEP3
    digitalWrite(EN_A,LOW);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SB,HIGH);
    status = 2;
    delayMicroseconds(t_micro);
    break;
  case 4:
    //STEP4
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,HIGH);
    delayMicroseconds(t_micro);
    status = 3;
    break;   
  case 5:
    //STEP5
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,LOW);
    digitalWrite(SA,LOW);
    delayMicroseconds(t_micro);
    status = 4;
    break;
  case 6:
    //STEP6
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,LOW);
    delayMicroseconds(t_micro);
    status = 5;
    break;
  case 7:
    //STEP7
    digitalWrite(EN_A,LOW);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SB,LOW);
    delayMicroseconds(t_micro);
    status = 6;
    break;
  case 8:
    //STEP8
    digitalWrite(EN_A,HIGH);
    digitalWrite(EN_B,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,LOW);
    delayMicroseconds(t_micro);
    status = 7;
    break;   
  }
}

