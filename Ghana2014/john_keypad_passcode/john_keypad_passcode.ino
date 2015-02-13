void setup(){
 Serial.begin(9600); 
 Serial.println("Input password");
 delay(1000);
 pinMode(A2,OUTPUT);
    
}

char getChar(){
 char res;
 while(res<33){
   if(Serial.available()>0){
       res = Serial.read();
     }
  }
  return res;
}

void askPass(){
  char res;
  res = getChar();
  Serial.print("You input: ");
  Serial.println(res);
  switch(res){
   case 'a':
     Serial.println("You are principal");
     digitalWrite(A2,HIGH);
     delay(3000);
     digitalWrite(A2,LOW);
     break;
   case 'b':
     Serial.println("You are instructor");
     digitalWrite(A2,HIGH);
     delay(3000);
     digitalWrite(A2,LOW);
     break;
   case 'c': 
     Serial.println("You are student");
     digitalWrite(A2,HIGH);
     delay(3000);
     digitalWrite(A2,LOW);
     break;
   default:
     Serial.println("You are not the TTI member");
     digitalWrite(A2,HIGH);
     delay(200);
     digitalWrite(A2,LOW);
     delay(200);
     digitalWrite(A2,HIGH);
     delay(200);
     digitalWrite(A2,LOW);
     delay(200);
     digitalWrite(A2,HIGH);
     delay(200);
     digitalWrite(A2,LOW);
     delay(200);
     digitalWrite(A2,HIGH);
     delay(200);
     digitalWrite(A2,LOW);
     delay(200);
     digitalWrite(A2,HIGH);
     delay(200);
     digitalWrite(A2,LOW);
     delay(200);
     digitalWrite(A2,HIGH);
     delay(200);
     digitalWrite(A2,LOW);
     delay(200);
     break;
  } 
  delay(100);
}


void loop(){
  askPass();
  delay(1);
}




