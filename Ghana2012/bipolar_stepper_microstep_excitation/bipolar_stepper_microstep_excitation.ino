//This is to drive the bipolar stepper motor using TA7291P

int pA = 6;
int _pA = 7;
int pB = 8;
int _pB = 9;
int PWM_A = 10;//FOR PWM OUTPUT
int PWM_B = 11;//FOR PWM OUTPUT

int status = 1;

int t_micro = 700;
int t_delay  = 0;

int quarter = 255/4;

void setup(){
  pinMode(pA,OUTPUT);//COIL A
  pinMode(_pA,OUTPUT);//COIL A bar
  pinMode(pB,OUTPUT);//COIL B
  pinMode(_pB,OUTPUT);//COIL B bar
  pinMode(PWM_A,OUTPUT);
  pinMode(PWM_B,OUTPUT);
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
    //MICRO STEP EXCITATION
  case 1:
    //STEP1
    digitalWrite(pA,LOW);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_B,quarter*4);
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 2;
    break;
  case 2:
    //STEP2
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_A,quarter);
    analogWrite(PWM_B,quarter*3);
    status = 3;
    delayMicroseconds(t_micro);
    delay(t_delay);
    break;
  case 3:
    //STEP3
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_A,quarter*2);
    analogWrite(PWM_B,quarter*2);    
    status = 4;
    delayMicroseconds(t_micro);
    delay(t_delay);
    break;
  case 4:
    //STEP4
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_A,quarter*3);
    analogWrite(PWM_B,quarter);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 5;
    break;   
  case 5:
    //STEP5
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter*4);
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 6;
    break;
  case 6:
    //STEP6
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter*3);
    analogWrite(PWM_B,quarter);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 7;
    break;
  case 7:
    //STEP7
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter*2);
    analogWrite(PWM_B,quarter*2);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 8;
    break;
  case 8:
    //STEP8
    digitalWrite(pA,HIGH);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter);
    analogWrite(PWM_B,quarter*3);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 9;
    break;   
  case 9:
    //STEP9
    digitalWrite(pA,LOW);
    digitalWrite(_pA,LOW);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_B,quarter*4);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 10;
    break;
  case 10:
    //STEP10
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter);
    analogWrite(PWM_B,quarter*3);    
    delay(t_delay);
    status = 11;
    delayMicroseconds(t_micro);
    break;
  case 11:
    //STEP11
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter*2);
    analogWrite(PWM_B,quarter*2);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 12;
    break;
  case 12:
    //STEP12
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,HIGH);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter*3);
    analogWrite(PWM_B,quarter);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 13;
    break;   
  case 13:
    //STEP13
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,LOW);
    analogWrite(PWM_A,quarter*4);
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 14;
    break;
  case 14:
    //STEP14
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_A,quarter*3);
    analogWrite(PWM_B,quarter);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 15;
    break;
  case 15:
    //STEP15
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_A,quarter*2);
    analogWrite(PWM_B,quarter*2);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 1;
    break;
  case 16:
    //STEP16
    digitalWrite(pA,LOW);
    digitalWrite(_pA,HIGH);
    digitalWrite(pB,LOW);
    digitalWrite(_pB,HIGH);
    analogWrite(PWM_A,quarter);
    analogWrite(PWM_B,quarter*3);    
    delayMicroseconds(t_micro);
    delay(t_delay);
    status = 1;
    break;   
  }
}


void r_rotate(){

}


