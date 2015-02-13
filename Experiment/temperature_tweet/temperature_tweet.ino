#include <SPI.h> // needed in Arduino 0019 or later
#include <Ethernet.h>
#include <Twitter.h>

// The includion of EthernetDNS is not needed in Arduino IDE 1.0 or later.
// Please uncomment below in Arduino IDE 0022 or earlier.
//#include <EthernetDNS.h>


// Ethernet Shield Settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// If you don't specify the IP address, DHCP is used(only in Arduino 1.0 or later).
byte ip[] = { 192, 168, 2, 10 };//ipを指定してください。

// Your Token to Tweet (get it from http://arduino-tweet.appspot.com/)
Twitter twitter("212584805-hwnlDNYwPhAUWHqB8k4g3DNIXvrf8KBM2VbwTGo2");

// Message to post
//char msg[] = "Hello, World! I'm Arduino!";

void setup(){
  Ethernet.begin(mac, ip);
  // or you can use DHCP for autoomatic IP address configuration.
  // Ethernet.begin(mac);
  Serial.begin(9600);
}

void loop(){
  delay(60000);//１分感覚で温度を調査してツイートします。
    
  float a0 = analogRead(A0);
  float xV = (5*a0)/1024;
  int intV = xV * 100;//整数部
  int decV = int(xV * 1000) % 10;//小数点部
  String strMsg = String("ailab workspace is ");
  strMsg += intV;
  strMsg += ".";
  strMsg += decV;
  strMsg += " ℃";
  strMsg += " #shikarduino";
  Serial.println("tweet is \""+strMsg+"\"");
  char msg[255];
  strMsg.toCharArray(msg, 255);
  
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    // Specify &Serial to output received response to Serial.
    // If no output is required, you can just omit the argument, e.g.
    // int status = twitter.wait();
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}
