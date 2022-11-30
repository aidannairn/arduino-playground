int switchState = 0; // Set switch to off by default

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);

  // If button not pressed
  if (switchState == LOW) {
    digitalWrite(3, HIGH); // Green LED On
    digitalWrite(4, LOW); // Red LED Off
    digitalWrite(5, LOW); // Red LED Off
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    // Wait a quarter of a second  
    delay(250);

    // Toggle LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);
  }
}