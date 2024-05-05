#define BLYNK_TEMPLATE_ID "TMPL6YpEK4W37"
#define BLYNK_TEMPLATE_NAME "switch"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "BlynkEdgent.h"

#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Pins
const int trigPin = 5;
const int echoPin = 18;
const int buzzerPin = 15;
const int moisturePin = 32; //the analog pin
const int motorControlPin = 2;

// LCD
const int lcdColumns = 16;
const int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// Constants
#define SOUND_SPEED 0.034
int soilMoisture;
BlynkTimer timer; //create an object named timer of class BlynkTimer

// Function prototypes
void setup();
void readTemperatureAndHumidity();
void displayTemperatureAndHumidity(float temperature, float humidity);
void ultrasonicSensor();
void moistureSensor();

void setup()
{
  Serial.begin(115200);

  delay(100);
  BlynkEdgent.begin();

  Serial.println(F("DHTxx test!"));

  pinMode(motorControlPin, OUTPUT);
  digitalWrite(motorControlPin, LOW);

  pinMode(moisturePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  dht.begin();
  lcd.init();
  lcd.backlight();

  timer.setInterval(2000L, moistureSensor); //timer will run every two secs 
  timer.setInterval(2000L, readTemperatureAndHumidity); //timer will run every two secs
  timer.setInterval(2000L, ultrasonicSensor); //timer will run every two secs
  timer.setInterval(5800L, lcdClear); //lcd will get cleared every 5.8 secs
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  if (value) {
    digitalWrite(motorControlPin, HIGH);
  } else {
    digitalWrite(motorControlPin, LOW);
  }
}

void readTemperatureAndHumidity() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  displayTemperatureAndHumidity(t, h);

  Blynk.virtualWrite(V2, h); //writes humidity
  Blynk.virtualWrite(V3, t); //write temperature
}

void displayTemperatureAndHumidity(float temperature, float humidity) {
  lcd.setCursor(0, 0);
  lcd.print("H: " + String(int(humidity)) + "%");

  lcd.setCursor(8, 0);
  lcd.print("T: " + String(int(temperature)));
}

void ultrasonicSensor() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distanceCm = duration * SOUND_SPEED / 2;

  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  lcd.setCursor(8, 1);
  lcd.print("D :" + String(distanceCm) + "cm");

  if (distanceCm < 5) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    Serial.println("BEEP!!!");
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  Blynk.virtualWrite(V1, distanceCm);
}

void moistureSensor() {
  soilMoisture = analogRead(moisturePin);
  Serial.println("Soil Moisture : " + String(soilMoisture));

  int moisturePercentage = map(soilMoisture, 4095, 0, 0, 100);
  Blynk.virtualWrite(V4, moisturePercentage);

  lcd.setCursor(0, 1);
  lcd.print("M :" + String(moisturePercentage) + "%");

  if (soilMoisture < 30) { //if soil is dry and moisture level is less than 30 percent
    Serial.println("Soil is DRY!");
    digitalWrite(motorControlPin, LOW); //when soil is dry, motor will stay off
    lcd.setCursor(0, 0);
  } else { //if moisture percentage is more than 30 percent then
    Serial.println("Soil is MOIST!");
    digitalWrite(motorControlPin, HIGH); //when soil is moist, motor is work
    lcd.setCursor(0, 0);
  }
}

void lcdClear() {
  lcd.clear();
}
