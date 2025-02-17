const int ledPins[] = {2, 3, 4, 5, 6}; // Connect LEDs to pins 2, 3, 4, 5, 6

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int numFingers = Serial.read() - '0'; // Convert character to number

    // Turn off all LEDs first
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // Turn on the LEDs based on the number of fingers
    for (int i = 0; i < numFingers; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
}
