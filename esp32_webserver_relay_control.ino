
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WebServer server(80);
int relayPin = 5;

void handleOn() {
  digitalWrite(relayPin, LOW);
  server.send(200, "text/plain", "Relay ON");
}

void handleOff() {
  digitalWrite(relayPin, HIGH);
  server.send(200, "text/plain", "Relay OFF");
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
