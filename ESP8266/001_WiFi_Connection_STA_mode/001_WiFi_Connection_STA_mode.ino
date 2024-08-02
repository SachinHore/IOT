#include<ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("Home","123456789");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println("Successfully Connected to Home ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());

}

void loop() {
  // put your main code here, to run repeatedly:

}
