#include <SPI.h>

// Pin definition
#define PIN_SPI_MOSI 11
#define PIN_SPI_MISO 12
#define PIN_SPI_SCK 13
#define PIN_SPI_SS 10
#define PIN_BUSY 9
#define PIN_dia 3

void setup()
{
pinMode(PIN_SPI_MOSI, OUTPUT);
pinMode(PIN_SPI_MISO, INPUT);
pinMode(PIN_SPI_SCK, OUTPUT);
pinMode(PIN_SPI_SS, OUTPUT);
pinMode(PIN_BUSY, INPUT);
pinMode(PIN_dia, INPUT);
digitalWrite(PIN_SPI_SS, HIGH);
SPI.begin();
SPI.setDataMode(SPI_MODE3);
SPI.setBitOrder(MSBFIRST);

L6470_send(0x00);//nop命令
L6470_send(0x00);
L6470_send(0x00);
L6470_send(0x00);

L6470_send(0xc0);//デバイスリセットコマンド

//L6470を設定
L6470_setup();

//指定座標に回転
L6470_send(0x60);//GoTo(ABS_POS)
L6470_send(0x00);//値(22bit)
L6470_send(0x00);
L6470_send(0xc8);

L6470_send(0x60);//GoTo(ABS_POS)
L6470_send(0x00);//値(22bit)
L6470_send(0x00);
L6470_send(0x64);

L6470_send(0x60);//GoTo(ABS_POS)
L6470_send(0x00);//値(22bit)
L6470_send(0x00);
L6470_send(0x32);

L6470_send(0x60);//GoTo(ABS_POS)
L6470_send(0x00);//値(22bit)
L6470_send(0x04);
L6470_send(0x7e);

L6470_send(0x70);//GoHome

//step clock mode
L6470_send(0x58);//0x58:正転,0x59:逆転
//attachInterrupt(1, CCW,CHANGE);
}


void loop(){
  CW();
  delay(3000);
}

void L6470_send(unsigned char add_or_val){
  while(!digitalRead(PIN_BUSY)){
  } //BUSYが解除されるまで待機
  digitalWrite(PIN_SPI_SS, LOW); // ~SSイネーブル。
  SPI.transfer(add_or_val); // アドレスもしくはデータ送信。digitalWrite(PIN_SPI_SS, HIGH); // ~SSディスエーブル。
}

void L6470_setup(){
//MAX SPEED OF ROTATION
L6470_send(0x07);//レジスタアドレス
L6470_send(0x00);//値(10bit),デフォルト0x41
L6470_send(0x40);
//VOLTAGE WHEN STOPPED
L6470_send(0x09);//レジスタアドレス
L6470_send(0x80);//値(8bit),デフォルト0x29
//VOLTAGE WHILE CONSTANT ROTATION
L6470_send(0x0a);//レジスタアドレス
L6470_send(0x80);//値(8bit),デフォルト0x29
//VOLTAGE WHILE ACCERALATING
L6470_send(0x0b);//レジスタアドレス
L6470_send(0x80);//値(8bit),デフォルト0x29
//VOLTAGE WHILE DEACCERALATING
L6470_send(0x0c);//レジスタアドレス
L6470_send(0x80);//値(8bit),デフォルト0x29

//フ ル ス テ ッ プ,ハ ー フ ス テ ッ プ,1/4, 1/8,…,1/128 ステップの設定
L6470_send(0x16);//レジスタアドレス
L6470_send(0x00);//値(8bit)
}

void CW(){
L6470_send(0x58);
//attachInterrupt(1, CCW,CHANGE);
}
void CCW(){
L6470_send(0x59);
//attachInterrupt(1, CW,CHANGE);
}
