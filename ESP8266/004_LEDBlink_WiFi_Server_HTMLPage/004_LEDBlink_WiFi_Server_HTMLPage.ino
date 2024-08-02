#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
ESP8266WebServer techno(80);
void handleRoot();
void LED(); //function declaration for handling LED
void NotRoot();
int led = D4;
void setup() {
  pinMode(D4,OUTPUT);
  Serial.begin(115200);
  WiFi.begin("Roro","123454321");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println("\n");
  Serial.println("Connected to Home");
  Serial.println(WiFi.localIP());
  techno.on("/",HTTP_GET,handleRoot); //setting the server to call handleroot when ("/") url is accessed with a GET request
  techno.on("/LED",HTTP_POST,LED);//here url is accessed with a POST request
  techno.onNotFound(NotRoot);// for unknown urls
  techno.begin();
  
}
void loop() {
     techno.handleClient();
}

void handleRoot(){
  techno.send(200,"text/html",
  "<form action=\"/LED\"method=\"POST\"><input type=\"submit\"value=\"Tooggle LED\"></form>");//contains a button to toggle the led
}//submits a POST request to /LED url

void LED(){
  digitalWrite(led, !digitalRead(led));//toggles the led
  techno.sendHeader("Location","/");//redirects the client to root url
  techno.send(303);//status code 303 which indicates a redirect to url-
}

void NotRoot(){
  techno.send(404, "text/plain","404:Not Found");
}

