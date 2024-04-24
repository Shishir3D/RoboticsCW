// chatgpt code

#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Pins
const int trigPin = 5;
const int echoPin = 18;
const int buzzerPin = 15;
const int moisturePin = 14;
const int motorControlPin = 2;

// LCD
const int lcdColumns = 16;
const int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// Constants
#define SOUND_SPEED 0.034

// Function prototypes
void setup();
void readTemperatureAndHumidity();
void displayTemperatureAndHumidity(float temperature, float humidity);
void ultrasonicSensor();
void moistureSensor();

void setup() {
  Serial.begin(9600);
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
}

void loop() {
  readTemperatureAndHumidity();
  ultrasonicSensor();
  moistureSensor();
  delay(1500);
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
}

void displayTemperatureAndHumidity(float temperature, float humidity) {
  lcd.setCursor(0, 0);
  lcd.print("Humidity: " + String(humidity) + "%");

  lcd.setCursor(0, 1);
  lcd.print("Temperature: " + String(temperature));

  delay(1500);
  lcd.clear();
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

  lcd.setCursor(0, 1);
  lcd.print("GAP :" + String(distanceCm) + "cm");

  if (distanceCm < 20) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    Serial.println("BEEP!!!");
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}

void moistureSensor() {
  int soilMoisture = analogRead(moisturePin);
  Serial.println("Soil Moisture : " + String(soilMoisture));

  if (soilMoisture < 3000) {
    Serial.println("Soil is wet!");
    digitalWrite(motorControlPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Soil is Wet");
  } else {
    Serial.println("Soil is dry!");
    digitalWrite(motorControlPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Soil is Dry");
  }
}
