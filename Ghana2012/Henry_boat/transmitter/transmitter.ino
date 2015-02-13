//transmitter program
//produced by shohei aoki

int input0;
int input1;
int speed;
int angle;

void setup(){
  //start serial communication
  Serial.begin(9600);
}

void loop(){
  input0 = analogRead(0);
  input1 = analogRead(1);
  speed = input0;
  angle = map(input1,0, 1023, 0, 179);
  Serial.print("a");
  Serial.print(speed);
  Serial.print(":");
  Serial.print(angle);
  Serial.print("e"); //stop word
  //Serial.println(""); // carriage return
  delay(1000);      //wait for 10ms
}

