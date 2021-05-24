#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "5dZnmJ92AgspPGykSozHzsvxaWvDnjIB";

BlynkTimer timer;


#ifndef STASSID
#define STASSID "Ganaderia_de_Weckx"
#define STAPSK  "B4n4n4@007!"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

void myTimerEvent() { Blynk.virtualWrite(V5, millis() / 1000);}

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }

  Blynk.begin(auth);
  timer.setInterval(1000L, myTimerEvent);
  
  IPAddress ipv4 = WiFi.localIP();
  Serial.print("Connected: ");
  Serial.println(ipv4);
  delay(500);
}

void loop() {
  Blynk.run();
  timer.run();
}
