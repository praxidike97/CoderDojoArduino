const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int buzzerPin = 12;

void setup() {
   Serial.begin(9600);
   pinMode(buzzerPin,OUTPUT);
}

void loop() {
   long duration, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);

   // Send out sound wave
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);

   // Receive the pulse duration deom the sound wave
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);

   cm = microsecondsToCentimeters(duration);

   if (cm < 10.0){
      delay(250);
      digitalWrite(buzzerPin,HIGH);
      delay(250);
      digitalWrite(buzzerPin,LOW);
   }

   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}


long microsecondsToCentimeters(long microseconds) {
   // Sound travels with 0.034 cm/us and we have to divide by 2 because we measure the 
   // way forth and back
   return microseconds * 0.034 / 2;
}
