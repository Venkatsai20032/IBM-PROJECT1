#include <Wire.h>
#include <WiFi.h>
#include <ThingSpeak.h>

const char *ssid = "Wokwi-GUEST";
const char *password = "";

#define TRIG_PIN 26
#define ECHO_PIN 25
#define POTENTIOMETER_PIN A0  
const float contaminationThreshold = 7.0;

unsigned long channelID = 2327527; // Use Your ThingSpeak Channel ID
const char *writeAPIKey = "3K1OPPG28L2BIA3E"; // Use Your ThingSpeak Write API Key

WiFiClient client;

void setup() {
  Serial.begin(115200);
  connectToWiFi();
  ThingSpeak.begin(client);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  float distance = readUltrasonicDistance();
  float pHValue = analogRead(POTENTIOMETER_PIN) / 100.0;  
  
  Serial.print("Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("pH Value: ");
  Serial.println(pHValue);

  if (pHValue < contaminationThreshold) {
    Serial.println("Water is contaminated!");
  } else {
    Serial.println("Water is clean.");
  }

  ThingSpeak.setField(1, distance);
  ThingSpeak.setField(2, pHValue);

  int updateSuccess = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (updateSuccess) {
    Serial.println("ThingSpeak update successful");
  } else {
    Serial.println("Error updating ThingSpeak");
  }

  delay(2000); 
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
}

float readUltrasonicDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  return pulseIn(ECHO_PIN, HIGH) * 0.0343 / 2;
}
