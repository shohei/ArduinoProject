/*
Central AVR firmware
Created by Shohei Aoki, 2013
*/

/*
############COMMAND REFERENCE###############
EXAMPLE: x:f:n300;
1st param: x , y or z (axis to drive)
2nd param: f , r or h (forward, reverse, and halt)
3rd param: integer following n (rpm value)
*/

int incomingByte = 0;
String incomingStr = "";
char incomingChar;
String buf;
int receivedMode = 0;
String rot_speed;

/*
##########PIN ASSIGNMENT#########
*/
int RXpin = 0;//Reserved
int TXpin = 1;//Reserved
int xpin = 2;
int ypin = 3;
int zpin = 4;
int dirpin = 5;
int triggerPin = 6;
int drivepin[] = {10,11,12,13};

void setup(){
 Serial.begin(9600);
}

void loop(){  
/*
######### RECEIVE THE MESSAGE##########
*/
  int i = 0;  
  buf="";
  char axis[2];
  char operationMode[2];
  if(Serial.available()>0){
   incomingByte = Serial.read();  
    if(incomingByte == '!'){
      buf.concat('!');
      receivedMode = 1;
      while(receivedMode){        
        if(Serial.available()>0){
        incomingChar = (char) Serial.read();
        buf.concat(incomingChar);
        i++;
        if(incomingChar == ';'){ 
        receivedMode = 0;
        }  
      }
     }
     Serial.write("received buffer:");
     Serial.println(buf);
  /*
  #########PARSE THE CONTENT##########
  */
     buf.substring(1,2).toCharArray(axis,2);
     buf.substring(3,4).toCharArray(operationMode,2);
     int n_loc = buf.indexOf("n"); 
     int stop_loc = buf.indexOf(";");
     int rot_speed =buf.substring(n_loc+1,stop_loc).toInt();
     
     switch(axis[0]){
      case 'x':
        digitalWrite(xpin,HIGH);
        Serial.println("X axis selected.");
        runOperation(axis[0],operationMode[0],rot_speed);
        break;
      case 'y':
        digitalWrite(ypin,HIGH);
        Serial.println("Y axis selected.");
        runOperation(axis[0],operationMode[0],rot_speed);
        break;
      case 'z':
        digitalWrite(zpin,HIGH);
        Serial.println("Z axis selected.");
        runOperation(axis[0],operationMode[0],rot_speed);
        break;
      default:
        Serial.println("No valid axis selected.");      
        break;
     } 
   } 
  }
}

void runOperation(char axis, char operationMode,int rot_speed){
  switch(operationMode){
   case 'f':
     //REGULAR DIRECTION
     digitalWrite(triggerPin,HIGH);
     digitalWrite(dirpin,HIGH);
     rotateMotor(rot_speed);
     break;
   case 'r':
     //REVERSE DIRECTION
     digitalWrite(triggerPin,HIGH);
     digitalWrite(dirpin,LOW);
     rotateMotor(rot_speed);
     break;   
   case 'h': 
     //HALT OPERATION
     digitalWrite(triggerPin,LOW);
     break;    
  } 
}

void rotateMotor(int rot_speed){
  
  
}


