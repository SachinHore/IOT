#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Roro";
const char* password = "123454321";

WiFiClient client;

unsigned long myChannelNumber = 2611348;
const char* myWriteAPIKey = "1ZDN0GWW1MIDE0VO";

int potPin = A0; // Analog pin connected to the potentiometer

void setup() {
  Serial.begin(115200); // Initialize serial
  pinMode(potPin, INPUT); // Set the potentiometer pin as input

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");

  ThingSpeak.begin(client); // Initialize ThingSpeak
}

void loop() {
  int potValue = analogRead(potPin); // Read the potentiometer value
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  // Send the potentiometer value to ThingSpeak
  ThingSpeak.setField(1, potValue); // Set field 1
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); // Write the value to ThingSpeak

  delay(20000); // Wait for 20 seconds to update the channel again
}

