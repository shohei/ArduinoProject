void setup(){
 Serial.begin(31250);
}

byte buffer = 0x00;

void loop(){
 while(Serial.available()){
   byte current = Serial.read();
   Serial.println(current);
   if(buffer == 0x55){
     Serial.println("The note starts");
     Serial.println(current,HEX);
   } else if (buffer == 0x00) {
     Serial.println("The note ends");
     Serial.println(current,HEX);
   } else {
     Serial.println("-----"); 
   }
   buffer = Serial.read();
   Serial.println(buffer); 
 }
}

