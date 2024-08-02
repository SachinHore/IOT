#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

void handleRoot();
void NotRoot();

ESP8266WebServer techno(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin("Roro",123456789);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println("/n ");
  Serial.println("Successfully Connected to Home ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
  techno.on("/",handleRoot);
  techno.onNotFound(NotRoot);
  techno.begin();
  Serial.println("Server started");
}

void loop() {
  techno.handleClient();
}

void handleRoot(){
  techno.send(200,"text/plain","hello World");
}

void NotRoot(){
  techno.send(404,"text/plain","404 : Not Found");
}

