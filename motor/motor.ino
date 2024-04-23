int pinn = 26;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinn, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(pinn, HIGH);
  delay(1000);
  digitalWrite(pinn, LOW);
  delay(1000);
  // put your main code here, to run repeatedly:
  /*
  if (Serial.available() > 0) {
    // Read the incoming byte
    int myInput = Serial.read();

    if (myInput == 1) {
      // If '1' is received, set pin 23 HIGH
      digitalWrite(pinn, HIGH);
      delay(200);
      Serial.println("Pin 23 set to HIGH");
    }
    else {
      digitalWrite(pinn, LOW);
      delay(500);
    
    }
  }
  */
}
