int STDBY = 11;
int SA = 12;
int SB = 13;

int status = 1;

int t_delay = 3;

void setup(){
  pinMode(STDBY,OUTPUT);//STAND BY SIGNAL
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
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,LOW);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 2;
    break;
  case 2:
    //STEP2
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,HIGH);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 3;
    delay(t_delay);
    break;
  case 3:
    //STEP3
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,HIGH);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 4;
    delay(t_delay);
    break;
  case 4:
    //STEP4
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,LOW);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 1;
    delay(t_delay);
    break;   
  }
}

void r_rotate(){
  switch(status){
  case 1:
    //STEP1
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,LOW);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 4;
    delay(t_delay);
    break;
  case 2:
    //STEP2
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,HIGH);
    digitalWrite(SB,HIGH);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 1;
    break;
  case 3:
    //STEP3
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,HIGH);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 2;
    break;
  case 4:
    //STEP4
    digitalWrite(STDBY,HIGH);
    digitalWrite(SA,LOW);
    digitalWrite(SB,LOW);
    delay(t_delay);
    digitalWrite(STDBY,LOW);
    status = 3;
    break;   
  }

  
}
