#include <aJSON.h>


void setup() {
  Serial.begin(9600);
  delay(1000);

}

void showTest(){
  String json_string = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  char *charBuf = new char[json_string.length() + 1];
  json_string.toCharArray(charBuf, json_string.length() + 1);
  aJsonObject* root = aJson.parse(charBuf);
  aJsonObject* sensor = aJson.getObjectItem(root, "sensor");
  char *sensor_str = aJson.print(sensor);
  Serial.print("Test result: ");
  Serial.println(sensor_str);
  delete[] charBuf;
}

void loop() {
  String response="";
  bool end = false;
  bool begin = false;
  Serial.println("outer loop");

//  while (!end) {
//    char c = Serial.read();
//    if (c == '{') {
//      begin = true;
//    }
//    if (begin) response += (c);
//    if (c == '}') {
//      end = true;
//      break;
//    }
//    delay(1);
//  }
  while(!end){
    if(Serial.available() > 0)
      {
         begin = true;
         response = Serial.readStringUntil('\n');
         Serial.println(response);
         end = true;
       }
  }
  
  if (begin) {
    Serial.print("Received: ");
    Serial.println(response);

//    char *charBuf = new char[response.length() + 1]();
    char charBuf[200];
//    response.toCharArray(charBuf, response.length() + 1);    
    response.toCharArray(charBuf, 200);    
//    charBuf[response.length() + 1]='\0';    
    Serial.print("charBuf: ");
    Serial.println(charBuf);
    aJsonObject* root = aJson.parse(charBuf);
    Serial.println("getObjectItem");    
    aJsonObject* sensor = aJson.getObjectItem(root, "sensor");
    Serial.println("valuestring"); 
    String sensor_str = sensor->valuestring;   

    Serial.print("Parsed Result: ");
    Serial.println(sensor_str);

    delete[] charBuf;   
    delay(1); 

    showTest();
  }
}
