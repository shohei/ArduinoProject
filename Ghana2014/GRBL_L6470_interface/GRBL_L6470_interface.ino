#include <PinChangeInt.h>
#include <SPI.h>
//#include <MsTimer2.h>
 
#define PIN_SPI_MOSI 11
#define PIN_SPI_MISO 12
#define PIN_SPI_SCK 13
#define PIN_SPI_SS 10
#define PIN_BUSYn 5
#define PIN_BUSYn2 6
#define PIN_BUSYn3 7
#define PCINTn1 2
#define PCINTn2 3
#define PCINTn3 4
 
//#define PIN_SPI_MOSI 51
//#define PIN_SPI_MISO 50
//#define PIN_SPI_SCK 52
//#define PIN_SPI_SS 53
 
//Arduino Duemilanove(ATmega168/328を搭載するボード): 10(SS)、11(MOSI)、12(MISO)、13(SCK) 
//Arduino Mega: 50(MISO)、51(MOSI)、52(SCK)、53(SS) 
 
void setup()
{
    Serial.begin( 115200 );
    Serial.println("Start");
 
    Serial.println("setup ");
    delay(2000);
 
    pinMode(PIN_SPI_MOSI, OUTPUT);
    pinMode(PIN_SPI_MISO, INPUT);
    pinMode(PIN_SPI_SCK, OUTPUT);
    pinMode(PIN_SPI_SS, OUTPUT);
 
    digitalWrite(PIN_SPI_SS, HIGH);
 
    pinMode(PIN_BUSYn, INPUT);
    pinMode(PIN_BUSYn2, INPUT);
    pinMode(PIN_BUSYn3, INPUT);
 
    SPI.begin();
    SPI.setDataMode(SPI_MODE3);
    SPI.setBitOrder(MSBFIRST);
    //REMOVE PREVIOUS COMMAND 
    L6470_send(0x00);
    L6470_send(0x00);
    L6470_send(0x00);
    L6470_send(0x00);
     
    L6470_send2(0x00);
    L6470_send2(0x00);
    L6470_send2(0x00);
    L6470_send2(0x00);

    L6470_send3(0x00);
    L6470_send3(0x00);
    L6470_send3(0x00);
    L6470_send3(0x00);
    // Device reset
    L6470_send(0xc0);
    L6470_send2(0xc0);
    L6470_send3(0xc0);
 
    L6470_setup();
}
 
void loop()
{
    //test1();
    //delay(2000);
}
 
void L6470_send(unsigned char add_or_val){
    digitalWrite(PIN_SPI_SS, LOW); 
    SPI.transfer(add_or_val); 
    SPI.transfer(0);
    SPI.transfer(0);
    digitalWrite(PIN_SPI_SS, HIGH);
}
 
void L6470_send2(unsigned char add_or_val){
    digitalWrite(PIN_SPI_SS, LOW); 
    SPI.transfer(0);
    SPI.transfer(add_or_val); 
    SPI.transfer(0);
    digitalWrite(PIN_SPI_SS, HIGH); 
}
 
void L6470_send3(unsigned char add_or_val){
    digitalWrite(PIN_SPI_SS, LOW); 
    SPI.transfer(0);
    SPI.transfer(0);
    SPI.transfer(add_or_val); 
    digitalWrite(PIN_SPI_SS, HIGH); 
}
 
void L6470_setup(){
    Serial.println("L6470 #1 setup ");
    //MAX ROTATION SPEED (default: 0x41)
    L6470_send(0x07);
    L6470_send(0x00);
    L6470_send(0x30);
    //VOLTAGE WHILE MOTOR HALT (default: 0x29)
    L6470_send(0x09);
    L6470_send(0x20);
    //VOLTAGE WHILE MOTOR ROTATING (default: 0x29) 
    L6470_send(0x0a);
    L6470_send(0x40);
    //VOLTAGE WHILE MOTOR ACCERALATING (default: 0x29)  
    L6470_send(0x0b);
    L6470_send(0x40);
    //VOLTAGE WHILE MOTOR DEACCERALATING (default: 0x29)   
    L6470_send(0x0c);
    L6470_send(0x40);
    //STEP MODE (0x00: Full step)
    L6470_send(0x16);
    L6470_send(0x00);
 
    Serial.println("L6470 #2 setup ");
 
    L6470_send2(0x07);
    L6470_send2(0x00);
    L6470_send2(0x30);
 
    L6470_send2(0x09);
    L6470_send2(0x20);
 
    L6470_send2(0x0a);
    L6470_send2(0x40);
 
    L6470_send2(0x0b);
    L6470_send2(0x40);
 
    L6470_send2(0x0c);
    L6470_send2(0x40);
 
    L6470_send2(0x16);
    L6470_send2(0x00);
    
    Serial.println("L6470 #3 setup ");
 
    L6470_send3(0x07);
    L6470_send3(0x00);
    L6470_send3(0x30);
 
    L6470_send3(0x09);
    L6470_send3(0x20);
 
    L6470_send3(0x0a);
    L6470_send3(0x40);
 
    L6470_send3(0x0b);
    L6470_send3(0x40);
 
    L6470_send3(0x0c);
    L6470_send3(0x40);
 
    L6470_send3(0x16);
    L6470_send3(0x00);

    //step clock mode
    L6470_send(0x58);//0x58:正転,0x59:逆転
    L6470_send2(0x58);//0x58:正転,0x59:逆転
    L6470_send3(0x58);//0x58:正転,0x59:逆転
    PCintPort::attachInterrupt(PCINTn1, CCW1,CHANGE);
    PCintPort::attachInterrupt(PCINTn2, CCW2,CHANGE);
    PCintPort::attachInterrupt(PCINTn3, CCW3,CHANGE);
}

void CW1(){
  L6470_send(0x58);
  attachInterrupt(PCINTn1, CCW1,CHANGE);
}

void CCW1(){
  L6470_send(0x59);
  attachInterrupt(PCINTn1, CW1,CHANGE);
}

void CW2(){
  L6470_send2(0x58);
  attachInterrupt(PCINTn2, CCW2,CHANGE);
}

void CCW2(){
  L6470_send2(0x59);
  attachInterrupt(PCINTn2, CW2,CHANGE);
}

void CW3(){
  L6470_send3(0x58);
  attachInterrupt(PCINTn3, CCW3,CHANGE);
}

void CCW3(){
  L6470_send3(0x59);
  attachInterrupt(PCINTn3, CW3,CHANGE);
}

void test1()
{
    Serial.println("test1 ");
 
    delay(1000);
 
    L6470_send(0x51);//正転
    L6470_send(0x00);
    L6470_send(0x40);
    L6470_send(0x00);
 
    L6470_send2(0x50);//逆転　
    L6470_send2(0x00);
    L6470_send2(0x40);
    L6470_send2(0x00);
    delay(2000);
 
    L6470_send(0xB0);//SoftStop
    L6470_send2(0xB0);//SoftStop
    delay(2000);
 
    L6470_send(0x50);//逆転　
    L6470_send(0x00);
    L6470_send(0x40);
    L6470_send(0x00);
 
    L6470_send2(0x51);//正転
    L6470_send2(0x00);
    L6470_send2(0x40);
    L6470_send2(0x00);

    L6470_send(0x50);//逆転
    L6470_send(0x00);
    L6470_send(0x40);
    L6470_send(0x00);

    delay(2000);
 
    L6470_send(0xB0);//SoftStop
    L6470_send2(0xB0);//SoftStop
    L6470_send3(0xB0);//SoftStop
    delay(2000);
 
    L6470_send(0x51);//正転
    L6470_send(0x01);
    L6470_send(0x00);
    L6470_send(0x00);
 
    L6470_send2(0x50);//逆転　
    L6470_send2(0x01);
    L6470_send2(0x00);
    L6470_send2(0x00);
    delay(10000);
 
    L6470_send(0xB0);//SoftStop
    L6470_send2(0xB0);//SoftStop
    delay(2000);
 
    L6470_send(0x50);//逆転　
    L6470_send(0x01);
    L6470_send(0x00);
    L6470_send(0x00);
 
    L6470_send2(0x51);//正転
    L6470_send2(0x01);
    L6470_send2(0x00);
    L6470_send2(0x00);
    delay(10000);
 
    L6470_send(0xB8);//HardStop
    L6470_send2(0xB8);//HardStop
    delay(2000);
 
    L6470_send(0x70);//GoHome
    L6470_send2(0x70);//GoHome
    delay(2000); 
}

