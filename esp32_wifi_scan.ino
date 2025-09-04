#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  Serial.println("Scanning...");
  int n = WiFi.scanNetworks();
  Serial.println("Scan done");
  for (int i = 0; i < n; ++i) {
    Serial.printf("%d: %s (%d)
", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
  }
  delay(5000);
}
