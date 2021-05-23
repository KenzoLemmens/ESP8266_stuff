#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "ssid"
#define STAPSK  "psk"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }
  IPAddress ipv4 = WiFi.localIP();
  Serial.print("Connected: ");
  Serial.println(ipv4);
  delay(500);
}

void loop() {
  delay(500);
}
