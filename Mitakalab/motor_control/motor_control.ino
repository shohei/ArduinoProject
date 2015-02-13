/*pin記述領域
 E = pin5 = 7 
 D = pin6 = 6 
 G = pin7 = 5 
 C = pin8 = 4 
 dot = pin9 = 3 
 B = pin10 = 1 
 A = pin11 = 0 
 F = pin12 = 2 
*/

int analogValue = 0;

//LEDセグメント対応領域
int A = 0; 
int B = 1;
int C = 4;
int D = 6;
int E = 7;
int F = 2;
int G = 5;

//define the function
void showZero(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);   
}
void showOne(){
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);  
}
 
void showTwo(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(G,HIGH);
}
 
void showThree(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(G,HIGH);   
}
void showFour(){
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);  
}

void resetLED(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}

//Main part
void setup(){
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT); 
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);

  //Serial.begin(9600);
}

void loop(){
  analogValue = analogRead(0);
  //Serial.println(analogValue);
  //delay(1000);
  
  resetLED();
  if(analogValue == 0) {
    showZero(); 
  }
  else if(analogValue >0 && analogValue <255) {
    showOne();
  }
  else if(analogValue >= 255 && analogValue < 510) {
    showTwo();
  }
  else if(analogValue >= 510 && analogValue < 765) {
    showThree();
  }
  else if(analogValue >= 765) {
    showFour();
  }
}
