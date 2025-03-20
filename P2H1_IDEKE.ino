/* 
Programming HW #1 
I.Dekel
TimeLord
*/
const int LED1 = 13; // Define LED1 connected to pin 13
const int LED2 = 12; // Define LED2 connected to pin 12

void setup() {
  pinMode(LED1, OUTPUT); // Set pin 13 as an output for LED1
  pinMode(LED2, OUTPUT); // Set pin 12 as an output for LED2
}

void loop() {
  // Turn on LED1 (Heart 1) for 400 milliseconds
  digitalWrite(LED1, HIGH);
  delay(400);

  // Turn on LED2 (Heart 2) for 100 milliseconds
  digitalWrite(LED2, HIGH);
  delay(100);

  // Turn off LED1 (Heart 1)
  digitalWrite(LED1, LOW);
  delay(400);

  // Turn off LED2 (Heart 2)
  digitalWrite(LED2, LOW);
  delay(100);
}
