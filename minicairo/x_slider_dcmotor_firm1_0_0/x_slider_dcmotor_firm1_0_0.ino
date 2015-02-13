int DIRPIN = 4;
int AIN = A0;
int OUT1 = 5;
int OUT2 = 6;

int analogValue;

void setup(){
  pinMode(DIRPIN,INPUT);
  pinMode(OUT1,OUTPUT);
  pinMode(OUT2,OUTPUT);
  //Serial.begin(9600);
}

void loop(){ 
  //analogValue = analogRead(AIN);
  //Serial.print(analogValue);
  while(analogRead(AIN) > 1000){
    if(digitalRead(DIRPIN) == LOW){
      //Serial.println("REGULAR ROT");
      digitalWrite(OUT1,HIGH);  
      digitalWrite(OUT2,LOW);
    } else if (digitalRead(DIRPIN)==HIGH){
      //Serial.println("REVERSER ROT");
      digitalWrite(OUT1,LOW); 
      digitalWrite(OUT2,HIGH);
    }
  }
}

