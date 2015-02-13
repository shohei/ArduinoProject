int flag = 0;

void setup(){
 Serial.begin(9600);
 while(!Serial){
   ;
 }
}

void loop(){

  if(flag == 0){  
   if(Serial.available() > 0) {
     Serial.write("PA;PA;VS4;!VZ4;!MC1;!PZ0,20;PU0,0;PD190,0;PD190,190;PD0,190;!MC0;");     
     flag = 1;
    }
   }

}
