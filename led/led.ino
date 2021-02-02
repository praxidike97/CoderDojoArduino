int ledNumber = 7;
int blinkDuration = 500;

void setup() {
  pinMode(ledNumber, OUTPUT);
}

void loop() {
  digitalWrite(ledNumber, HIGH); 
  delay(blinkDuration);   
  digitalWrite(ledNumber, LOW);
  delay(blinkDuration);  
}
