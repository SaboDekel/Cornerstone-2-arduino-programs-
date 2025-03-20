/* 
Programming HW #3
I.Dekel
Traffic light
*/

// Traffic Light Pins
const int greenLED = 11;  
const int yellowLED = 12;
const int redLED = 13;
const int buttonPin = 2;  // the number of the pushbutton pin
// RGB Pedestrian Light Pins
const int PL_R = 7;  // Red Pin of RGB LED
const int PL_G = 6;  // Green Pin of RGB LED
const int PL_B = 5;  // Blue Pin of RGB LED
// Timing Constants
const long greenDuration = 5000;   // 5 sec
const long yellowDuration = 2500;  // 2.5 sec
const long redDuration = 7500;     // 7.5 sec
const long whiteDuration = 3000;   // 3 sec pedestrian crossing
const long blinkDuration = 2000;   // 2 sec blinking
const long blinkInterval = 250;    // 0.25 sec per blink
int buttonState = 0;  // variable for reading the pushbutton status
void setup() {
    // Traffic Lights
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(buttonPin, INPUT);
    // Pedestrian Light (RGB)
    pinMode(PL_R, OUTPUT);
    pinMode(PL_G, OUTPUT);
    pinMode(PL_B, OUTPUT);
}

void loop() {
    unsigned long previousMillis = millis();
    // Green LED ON for 5 sec
    digitalWrite(greenLED, HIGH);
    while (millis() - previousMillis < greenDuration) {
          buttonState = digitalRead(buttonPin);
          if (buttonState == HIGH) {
            break;          
            }    
      }
    digitalWrite(greenLED, LOW);
    // Yellow LED ON for 2.5 sec
    previousMillis = millis();
    digitalWrite(yellowLED, HIGH);
    while (millis() - previousMillis < yellowDuration) {}
    digitalWrite(yellowLED, LOW);
    // Red LED ON for 7.5 sec
    previousMillis = millis();
    digitalWrite(redLED, HIGH);
    // --- Pedestrian Light Cycle Starts ---
    // Step 1: White Light for 3 sec (Pedestrians Cross)
    setRGB(255, 255, 255); // White
    delay(whiteDuration);
    // Step 2: Blinking Orange (Yellowish) for 2 sec
    for (int i = 0; i < (blinkDuration / (2 * blinkInterval)); i++) {
        setRGB(255, 165, 0); // Orange
        delay(blinkInterval);
        setRGB(0, 0, 0); // Off
        delay(blinkInterval);
    }
    // Step 3: Solid Orange until next cycle
    setRGB(255, 165, 0); // Solid Orange
    while (millis() - previousMillis < redDuration) {}
    // Reset everything before restarting loop
    digitalWrite(redLED, LOW);
}
// Function to control RGB LED

void setRGB(int r, int g, int b) {
    analogWrite(PL_R, r);
    analogWrite(PL_G, g);
    analogWrite(PL_B, b);
}