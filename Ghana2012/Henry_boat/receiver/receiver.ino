//receiver program
//produced by shohei aoki

#include <Servo.h>
#include <string.h>

Servo myservo;
char* speed_string;
char* angle_string;
int speed;
int angle;

void setup(){
  //start serial communication
  Serial.begin(9600);
  //D8 is a digital output for PWM
  pinMode(10,OUTPUT);
  //D2 is a servo signal pin
  myservo.attach(9);
}

void loop(){
  //array for the data(number and character)
  char str[20];
  recvStr(str);
  speed_string = strtok(str,":");
  angle_string = strtok(NULL,"e");
  speed = atoi(speed_string);
  angle = atoi(angle_string);
  Serial.println(speed);
  Serial.println(angle);
  analogWrite(10,speed);//PWM output
  myservo.write(angle); //set the servo angle
}

void recvStr(char *buf)
{
  int i = 0;
  char first_c;
  char c;
  while (1) {
    if (Serial.available()) {
      first_c = Serial.read();
      Serial.print(first_c);
      if(first_c == 'a') { //'a' as a start signal      
        c = Serial.read();
        buf[i] = c;
        if (c == 'e') break; // e is a stop word
        i++;
        }
     }  
   else { Serial.print("-"); }  
}
  buf[i] = 'e';
}
