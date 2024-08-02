#include<ESP8266WiFi.h>
void setup() {
   Serial.begin(115200);
   WiFi.softAP("MYESP",123456789);
   Serial.println("\n");
   Serial.println(WiFi.softAPIP());
}

void loop() {
}
