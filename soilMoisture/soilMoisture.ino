const int moisturePin = 14;
int soilMoisture;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(moisturePin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  soilMoisture = analogRead(moisturePin);  
  //Serial.println(soilMoisture);

  
  if (soilMoisture < 2000) {
    Serial.println("Soil is wet!");

    lcd.setCursor(0, 0);
    lcd.print("Soil is Wet");
  }
  else {
    Serial.println("Soil is dry!");

    lcd.setCursor(0, 0);
    lcd.print("Soil is Dry");
  }
  
  delay(2000); 
}