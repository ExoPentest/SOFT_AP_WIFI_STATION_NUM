#include <WiFi.h> // WIFI LIBRARY

char ssid[] = "ESP32NETWORK"; // SSID & PUT SSID ACCORDING TO YOUR DESIRE
char pass[] = "REDACTED"; // PASS & PUT PASS ACCORDING TO YOUR DESIRE
const int Pin_Point = 2; // GPIO 2 

void Blinker() {
  for (int i = 0 ; i < 3 ; i++) { // 3 , I = 0 (Initial) , i++ added
    digitalWrite(Pin_Point , HIGH); // HIGH = 1 = ON , 2 = LED LIGHT BUILT IN GPIO
    delay(200); // Delayed

    digitalWrite(Pin_Point , LOW); // LOW = 0 = OFF , 2 = LED LIGHT BUILT IN GPIO
    delay(200); // Delayed

  }
}

void setup() {
  Serial.begin(115200);
  pinMode(Pin_Point,OUTPUT); // Pin Mode for 2 & OUPUT as of Light Built-in
  Blinker(); // Binker
  WiFi.mode(WIFI_AP); // Mode
  Serial.println("Setting up your Wifi"); // String Validation
  delay(5000); // Delayed
  if (WiFi.softAP(ssid,pass)) { // Status
    Serial.println("Access Point Started");  // String Validation
    Serial.println(WiFi.softAPIP());  // String Validation

  }else { // Else Statement
     Serial.println("Access Point Failed"); // String Validation
  }
  delay(10000); // Delayed




}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    
    Serial.println("No Device is Connected"); // String Validation
    Blinker() ; // Blinker
    
  } else { // Else Statement
    Serial.print(WiFi.softAPgetStationNum() ); // Number of Device Connected
    Serial.print("  "); // Imaginary Spaces
    Serial.println("Device Connected "); // String Validation
    
  }


}