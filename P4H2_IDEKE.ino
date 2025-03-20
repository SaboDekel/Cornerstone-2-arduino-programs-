/*
Itamar Dekel
Servo figure it out 
2/7/25
*/

#include <Servo.h>
Servo servo;
int myservo = 90;
#define button1 2
#define button2 3

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  servo.attach(4);
  servo.write(myservo);
  Serial.begin(9600); 
}

void loop() {
  int increase = digitalRead(button1);
  int decrease = digitalRead(button2);

  if (increase == HIGH && decrease == HIGH) {
    // Both buttons pressed: Reset servo to neutral
    myservo = 90;
  } 
  else if (increase == HIGH) {
    // Button 1 pressed: Increase servo value
    myservo += 2;
  } 
  else if (decrease == HIGH) {
    // Button 2 pressed: Decrease servo value
    myservo -= 2;
  }

  // Constrain servo value to allowable range
  myservo = constrain(myservo, 0, 180);

  // Print current servo value
  Serial.println(myservo);

  // Set servo to the current value
  servo.write(myservo);

  delay(50); // Small delay to avoid excessive changes
}
