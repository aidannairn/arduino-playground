const int sensorPin = A0;
const float baselineTemp = 24.0; // Set baseline temp to be compared against live temp

void setup() {
  /*  
    Open a connection between the Arduino and the computer 
    9600 is the speed at which the Arduino will communicate (9600 bits p/s)
  */
  Serial.begin(9600);

  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);


  Serial.print(". degrees C: ");
  // Convert the voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  // The higher the temperature compared to baseline - The more LEDs that should turn on
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1000);  
}