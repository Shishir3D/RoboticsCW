#define BLYNK_TEMPLATE_ID "TMPL601n8puIx"
#define BLYNK_TEMPLATE_NAME "firstProject"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "NM9jUhHbfSNJBRC9bDvIX0D4XeGbjrDO"; // Using the same auth token for Blynk and WiFi
char ssid[] = "Islington College";    // Enter your WiFi name
char pass[] = "I$LiNGT0N2024";       // Enter your WiFi password

BLYNK_WRITE(V0) {
  digitalWrite(V0, param.asInt());
}

void setup() {
  pinMode(V0, OUTPUT);
  Blynk.begin(auth,ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}