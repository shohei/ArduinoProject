#include <Wire.h>
#define I2C_ADDR (0xA2 >> 1)  // 1ビット目未使用のため1ビット右シフトする。

void setup() {
  Serial.begin(9600);
  Serial.println("RTC Test Start");

  Wire.begin();  // initialize I2C
  delay(1000);   // wait for oscillitator standing by

  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00); 
  Wire.write(0x20); // 00 Control 1　STOP(bit5)-1 
  Wire.write(0x00); // 01 Control 2
  Wire.write(0x00); // 02 Seconds
  Wire.write(0x02); // 03 Minutes　　　 〃 　　min 0 ～ 59
  Wire.write(0x01); // 04 Hours　　　　 〃 　　hour 0 ～ 23
  Wire.write(0x1C); // 05 Days 　　　　 〃 　　day 1 ～ 31
  Wire.write(0x00); // 06 Weekdays 　　 〃 　　day of the week 0 ～ 6
  Wire.write(0x02); // 07 Months 　　　 〃 　　month 1 ～ 12
  Wire.write(0x0E); // 08 Years　　　　 〃 　　year 0 ～ 99
  Wire.write(0x00); // 09 Minutes Alarm　0 ～ 59
  Wire.write(0x00); // 0A Hours Alarm　　0 ～ 23
  Wire.write(0x00); // 0B Days Alarm 　　1 ～ 31
  Wire.write(0x00); // 0C Weekdays Alarm　0 ～ 6
  Wire.write(0x00); // 0D CLKOUT 
  Wire.write(0x00); // 0E Timer control
  Wire.write(0x00); // 0F Timer　　　　　
  Wire.write(0x00); // 00 Control 1　STOP(bit5)-0 -> RESET 
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x02);
  Wire.endTransmission();
  delay(1);
  Wire.requestFrom(I2C_ADDR, 7);
  int sec = Wire.read();    // sec
  int min = Wire.read();    // min
  int hour = Wire.read();   // hour
  int day = Wire.read();    // day
  int week = Wire.read();   // day of the week
  int month = Wire.read();  // month
  int year = Wire.read();   // year

  Serial.print("20");
  Serial.print(year, DEC);
  Serial.print("-");
  Serial.print(month, DEC);
  Serial.print("-");
  Serial.print(day, DEC);
  Serial.print(" ");
  if(hour<10){
    Serial.print("0");
  }
  Serial.print(hour, DEC);
  Serial.print(":");
  if(min<10){
    Serial.print("0");
  }
  Serial.print(min, DEC);
  Serial.print(":");
  if(sec<10){
    Serial.print("0");
  }
  Serial.println(sec, DEC);

  delay(1000);
}

