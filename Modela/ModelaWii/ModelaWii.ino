#include "Wire.h"

#include "WiiClassic.h"
#include <iostream>
#include <sstream>
using namespace std;

WiiClassic wiiClassy = WiiClassic();

int currentX = 0;
int currentY = 0;

int delay_t = 100;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  wiiClassy.begin();
  wiiClassy.update();
  while(!Serial){
  }
  //Serial.write("PA;PA;VS4;!VZ4;!MC1;!PZ0,20;");
  char* charac[] = {"P","A",";","P","A",";","V","S","4",";","!","V","Z","4",";","!","M","C","1",";","!","P","Z","0",",","2","0",";","P","U","0",",","0",";","P","D","1","9","0",",","0",";","P","D","1","9","0",",","1","9","0",";","P","D","0",",","1","9","0",";","!","M","C","0",";"};
  int charac_num = sizeof charac /sizeof charac[0];
  for(int i=0;i<charac_num;++i) {
      Serial.write(charac[i]);
    delay(delay_t);
  }
}

void loop() {
  delay(100); // 1ms is enough to not overload the wii Classic, 100ms seems to ease the serial terminal a little
  wiiClassy.update();

  // 
  /* 
  // PRINT RAW BYTES  FOR DEBUG
   // STATUS IS FIRST FOUR BYTES
   for (int i = 0; i < 4; i ++) {
   for (int j = 7; j >= 0; j--) {
   if ((wiiClassy.getRawStatus()[i] & (1 << j)) == 0) {
   Serial.print("0");
   }
   else{
   Serial.print("1");
   }
   }
   Serial.println();
   }
   // BUTTONS IS NEXT TWO BYTES
   for (int i = 0; i < 2; i ++) {
   for (int j = 7; j >= 0; j--) {
   if ((wiiClassy.getRawButtons()[i] & (1 << j)) == 0) {
   Serial.print("0");
   }
   else{
   Serial.print("1");
   }
   }
   Serial.println();
   }
  Serial.println("---");
   */

  /*
  Serial.print("Buttons:");


  if (wiiClassy.leftShoulderPressed()) {
    Serial.print("LS.");
  }
  if (wiiClassy.rightShoulderPressed()) {
    Serial.print("RS.");
  }
  if (wiiClassy.lzPressed()) {
    Serial.print("lz.");
  }
  if (wiiClassy.rzPressed()) {
    Serial.print("rz.");
  }
  if (wiiClassy.leftDPressed()) {
    Serial.print("LD.");
  }

  if (wiiClassy.rightDPressed()) {
    Serial.print("RD.");
  }

  if (wiiClassy.upDPressed()) {
    Serial.print("UD.");
  }
  if (wiiClassy.downDPressed()) {
    Serial.print("DD.");
  }

  if (wiiClassy.selectPressed()) {
    Serial.print("select.");
  }

  if (wiiClassy.homePressed()) {
    Serial.print("home.");
  }
  if (wiiClassy.startPressed()) {
    Serial.print("start.");
  }

  if (wiiClassy.xPressed()) {
    Serial.print("x.");
  }

  if (wiiClassy.yPressed()) {
    Serial.print("y.");
  }

  if (wiiClassy.aPressed()) {
    Serial.print("a.");
  }

  if (wiiClassy.bPressed()) {
    Serial.print("b.");
  }

  Serial.println();
  Serial.print("right shoulder: ");
  Serial.println(wiiClassy.rightShouldPressure());
  Serial.print(" left shoulder: ");

  Serial.println(wiiClassy.leftShouldPressure());
  Serial.print("  left stick x: ");

  Serial.println(wiiClassy.leftStickX());
  Serial.print("  left stick y: ");

  Serial.println(wiiClassy.leftStickY());
  Serial.print(" right stick x: ");

  Serial.println(wiiClassy.rightStickX());
  Serial.print(" right stick y: ");

  Serial.println(wiiClassy.rightStickY());
  Serial.println("---");
  */
  //pulse = (int)500+8*wiiClassy.leftStickX();
  //updateServo();

  Serial.print(currentX);
  Serial.print(",");
  Serial.println(currentY);
  
  if (wiiClassy.xPressed()) {
    currentY += 50;

    int answer;
    Serial.write("P");
    delay(delay_t);
    Serial.write("U");
    delay(delay_t);
    /*
    int numx = (int)log10(currentX) + 1;
    for(int i=0;i<numx-1;i++){
      answer = currentX / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }*/
    Serial.write(currentX);
    delay(delay_t);
    Serial.write(",");
    delay(delay_t);
    /*
    int numy = (int)log10(currentY) + 1;
    for(int i=0;i<numy-1;i++){
      int answer = currentY / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }
    */
    Serial.write(currentY);
    delay(delay_t);
    Serial.write(";");
    delay(delay_t);
  }

  if (wiiClassy.yPressed()) {
    currentX -= 50;
    int answer;
    Serial.write("P");
    delay(delay_t);
    Serial.write("U");
    delay(delay_t);
    /*
    int numx = (int)log10(currentX) + 1;
    for(int i=0;i<numx-1;i++){
      answer = currentX / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }
    */
    Serial.write(currentX);
    delay(delay_t);
    Serial.write(",");
    delay(delay_t);
    /*
    int numy = (int)log10(currentY) + 1;
    for(int i=0;i<numy-1;i++){
      int answer = currentY / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }
    */
    Serial.write(currentY);
    delay(delay_t);
    Serial.write(";");
    delay(delay_t);  }

  if (wiiClassy.aPressed()) {
    currentX += 50; 
    int answer;
    Serial.write("P");
    delay(delay_t);
    Serial.write("U");
    delay(delay_t);
    /*
    int numx = (int)log10(currentX) + 1;
    for(int i=0;i<numx-1;i++){
      answer = currentX / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }
    */
    Serial.write(currentX);
    delay(delay_t);
    Serial.write(",");
    delay(delay_t);
    /*
    int numy = (int)log10(currentY) + 1;
    for(int i=0;i<numy-1;i++){
      int answer = currentY / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }
    */
    Serial.write(currentY);
    delay(delay_t);
    Serial.write(";");
    delay(delay_t);  }

  if (wiiClassy.bPressed()) {
    currentY -= 50;
    int answer;
    Serial.write("P");
    delay(delay_t);
    Serial.write("U");
    delay(delay_t);
    /*
    int numx = (int)log10(currentX) + 1;
    for(int i=0;i<numx-1;i++){
      answer = currentX / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }*/
    Serial.write(currentX);
    delay(delay_t);
    Serial.write(",");
    delay(delay_t);
    /*
    int numy = (int)log10(currentY) + 1;
    for(int i=0;i<numy-1;i++){
      int answer = currentY / pow(10,i);
      Serial.write(answer);
      delay(delay_t);
    }
    */
    Serial.write(currentY);
    delay(delay_t);
    Serial.write(";");
    delay(delay_t);
  }
}

