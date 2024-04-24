#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

const int trigPin = 5; //white wire
const int echoPin = 18; //yellow wire
const int buzzerPin = 15;

const int moisturePin = 14;
int soilMoisture;

int motorControlPin = 23;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
float distanceInch;


// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  pinMode(motorControlPin, OUTPUT);
  digitalWrite(motorControlPin, LOW);

  pinMode(moisturePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  dht.begin();
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);


  lcd.setCursor(0, 0);
  lcd.print("Humidity: " + String(h) + "%");
  
  // clears the display to print new message

  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Temperature: " + String(t));
  
  

  //Serial.print("Humidity: " + String(h) + "%");
  //Serial.println("Temperature: " + String(t));
  delay(1000);
  lcd.clear();


  //ultrasonic9


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  lcd.setCursor(0, 1);
  //lcd.clear();
  lcd.print("GAP :" +  String(distanceCm) + "cm");

  // Check if distance is less than 20 cm
  if (distanceCm < 20) {
    // If distance is less than 20 cm, turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    Serial.println("BEEP!!!");
  

  } else {
    // If distance is greater than or equal to 20 cm, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  soilMoisture = analogRead(moisturePin);  
  Serial.println("Soil Moisture : " + String(soilMoisture));

  if (soilMoisture < 3000) {
    Serial.println("Soil is wet!");

    digitalWrite(motorControlPin, LOW); //turns off the motor
    lcd.setCursor(0, 0);
    lcd.print("Soil is Wet");
  }
  else {
    Serial.println("Soil is dry!");

    digitalWrite(motorControlPin, HIGH); //turns on the motor
    lcd.setCursor(0, 0);
    lcd.print("Soil is Dry");
  }

}
