#include <Servo.h>
#include <MsTimer2.h>
// 可変抵抗器に接続したアナログピンの番号

const int potentiometerPin1 = 0;  // const = 定数
const int potentiometerPin2 = 1;
const int potentiometerPin3 = 2;
const int potentiometerPin4 = 3;
const int potentiometerPin5 = 4;
const int potentiometerPin6 = 5;
char str[35];
int count;

int angle1,angle2,angle3,angle4,angle5,angle6,angle7;

// サーボ

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;

void setup(){
  
  // サーボを使用するピンとしてデジタルピンの8番と9番をセット
  
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(12);
  servo6.attach(12);
  servo7.attach(13);
  
  Serial.begin(9600);
  MsTimer2::set(1000, dispAngle);    
  MsTimer2::start();     
}

void loop() {
  
   // 指定したアナログピンから可変抵抗器の値を読み取る.
                        
  int value1 = analogRead(potentiometerPin1);
  int value2 = analogRead(potentiometerPin2);
  int value3 = analogRead(potentiometerPin3);
  int value4 = analogRead(potentiometerPin4);
  int value5 = analogRead(potentiometerPin5);
  int value6 = analogRead(potentiometerPin6);
  
  // 読み取った値を0から179までに変換
  // map(変換したい数値, 現在の範囲の下限, 現在の範囲の上限, 変換後の範囲の下限, 変換後の範囲の上限)
  
  angle1 = map(value1, 0, 1023, 0, 179);
  angle2 = map(value2, 0, 1023, 0, 179);
  angle3 = map(value3, 0, 1023, 0, 179);
  angle4 = map(value4, 0, 1023, 0, 179);
  angle5 = map(value5, 0, 1023, 0, 179);
  angle6 = map(value6, 0, 1023, 0, 179);
  
  //Serial.println(angle1);

  // サーボの角度を設定する. 
   
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  servo5.write(angle5);
  servo6.write(angle5);
  servo7.write(angle6);
  
  delay(15);
  
}

void dispAngle(){
 count++;
 sprintf(str,"%dsec: %d %d %d %d %d %d",count,angle1,angle2,angle3,angle4,angle5,angle6,angle7);
 Serial.println(str);
}




