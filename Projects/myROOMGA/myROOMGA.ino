int left1 = 2;
int leftPWM = 3;
int left2 = 4;
int status_left = 0; //if CW

int right1 = 5;
int rightPWM = 6;
int right2 = 7;
int status_right = 0;//if CW

int val;

void setup(){
  Serial.begin(9600);
  pinMode(left1,OUTPUT);
  pinMode(leftPWM,OUTPUT);
  pinMode(left2,OUTPUT);
  pinMode(right1,OUTPUT);
  pinMode(rightPWM,OUTPUT);
  pinMode(right2,OUTPUT);

  //NO PWM when testing
  //digitalWrite(leftPWM,HIGH);
  //digitalWrite(rightPWM,HIGH);
  analogWrite(leftPWM,100);
  analogWrite(rightPWM,100);
}

int delay_t = 2000;
int delay_tt = 500;

void loop(){
 if(Serial.available()>0){ //データが来たら
    val=Serial.read();    //データを読み込み、valへ代入
  
 Serial.print(val);
  rightBrake();
  leftBrake();

  if(val=='F'){           
    forward();
    Serial.println("forward");
  }else if(val=='B'){                 
    back();
    Serial.println("back");
  } else if(val=='R'){
    turnRight();
    Serial.println("turn right");
  } else if(val=='L'){
    turnLeft();
    Serial.println("turn left");
  } else if(val =='S'){
    leftBrake();
    rightBrake(); 
  }
}
  /*
  leftCW();
  delay(delay_t);
  leftCCW();
  delay(delay_t);
  leftBrake();

  rightCW();
  delay(delay_t);
  rightCCW();
  delay(delay_t);
  rightBrake();
  */
}

//TODO:引数にはPWMの値をとる
void leftCW(){
  digitalWrite(left1,HIGH);
  digitalWrite(left2,LOW);
  status_left = 0;
}

void leftCCW(){
  digitalWrite(left1,LOW);
  digitalWrite(left2,HIGH); 
  status_left = 1;
}

void leftBrake(){
if(status_left == 0){
  leftCCW();
  delay(100);
  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  } else if(status_left == 1){
  leftCW();
  delay(100);
   digitalWrite(left1,LOW);
   digitalWrite(left2,LOW);
 } else {
   digitalWrite(left1,LOW);
   digitalWrite(left2,LOW);
 }
}

void rightCW(){
  digitalWrite(right1,HIGH);
  digitalWrite(right2,LOW);
  status_right=0;
}

void rightCCW(){
  digitalWrite(right1,LOW);
  digitalWrite(right2,HIGH);
  status_right=1;
}

void rightBrake(){
if(status_right == 0){
  rightCCW();
  delay(100);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  } else if(status_right == 1){
  rightCW();
  delay(100);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
 } else {
   digitalWrite(right1,LOW);
   digitalWrite(right2,LOW);
 }
}

void back(){
  analogWrite(leftPWM,50);
  analogWrite(rightPWM,50);
  leftCW();
  rightCCW(); 
}

void forward(){
  analogWrite(leftPWM,40);
  analogWrite(rightPWM,40);
  leftCCW();
  rightCW();  
}

void turnLeft(){
  analogWrite(leftPWM,120);
  analogWrite(rightPWM,120);
  leftCW();
  rightCW(); 
}


void turnRight(){
  analogWrite(leftPWM,120);
  analogWrite(rightPWM,120);
  leftCCW();
  rightCCW();
}

