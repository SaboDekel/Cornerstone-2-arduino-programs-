/*
/*
Itamar Dekel
Photorisister gonnected to an LED light 
2/6/25
*/
*/

// Constants for pin assignments
const int analogInPin = A0;  // Analog input pin (Photoresistor)
const int analogOutPin = 9;  // Analog output pin (LED)

// Variables for sensor calibration
int sensorValue = 0;  // Sensor reading
int outputValue = 0;  // PWM output value
int SMin = 1023;      // Initial high min value
int SMax = 0;         // Initial low max value

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Calibration Starting...");

  // Calibration loop (runs for 5 seconds)
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    int SV = analogRead(analogInPin); // Read sensor value
    if (SV < SMin) {
      SMin = SV;
    }
    if (SV > SMax) {
      SMax = SV;
    }
  }

  Serial.println("Calibration Finished.");
  Serial.print("Calibrated Min: ");
  Serial.println(SMin);
  Serial.print("Calibrated Max: ");
  Serial.println(SMax);
}

void loop() {
  // Read the analog sensor value
  sensorValue = analogRead(analogInPin);

  // Map the sensor value to the range 0-255 based on calibrated min/max
  outputValue = map(sensorValue, SMin, SMax, 0, 255);

  // Constrain the output value within the range 0-255
  outputValue = constrain(outputValue, 0, 255);

  // Set the LED brightness based on the constrained output
  analogWrite(analogOutPin, outputValue);

  // Print values to Serial Monitor
  Serial.print("Sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t Output = ");
  Serial.println(outputValue);

  Serial.print("Sensor Min = ");
  Serial.print(SMin);
  Serial.print("\t Sensor Max = ");
  Serial.println(SMax);

  // Small delay for stability
  delay(2);
}
