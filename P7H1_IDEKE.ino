/*
  P7L1
  <I>.<Dekel>
  <3/10/25>

  A one player Rock paper scissors game against the computer
  using 3 buttons (Inputs) as rock, paper and scissors. Also, using two LEDs to notify the play whether they won or the computer 
  using a random number generator in MatLab to produce a random output of rock,paper or scissors. The program is incoperating a winner system 
  tp detemrine the winner and send a output on the monitor and in the from of an LED light

*/

const int buttonRock = 2;    // Pin for Rock button
const int buttonPaper = 3;   // Pin for Paper button
const int buttonScissors = 4; // Pin for Scissors button
const int ledPlayer1 = 8;    // LED to show Player 1 wins
const int ledPlayer2 = 9;    // LED to show Player 2 wins

int playerChoice = 0; // Player 1 choice: 1 = Rock, 2 = Paper, 3 = Scissors
int winner = 0; // 0 = Draw, 1 = Player 1, 2 = Player 2

void setup() {
  pinMode(buttonRock, INPUT);
  pinMode(buttonPaper, INPUT);
  pinMode(buttonScissors, INPUT);
  pinMode(ledPlayer1, OUTPUT);
  pinMode(ledPlayer2, OUTPUT);
  Serial.begin(9600); // Start serial communication for MATLAB communication
}

void loop() {
  // Read button presses for Player 1's choice
  if (digitalRead(buttonRock) == HIGH) {
    playerChoice = 1; // Rock
  } else if (digitalRead(buttonPaper) == HIGH) {
    playerChoice = 2; // Paper
  } else if (digitalRead(buttonScissors) == HIGH) {
    playerChoice = 3; // Scissors
  }

  // If Player 1 has made a choice, send it to MATLAB for Player 2's random choice
  if (playerChoice > 0) {
    Serial.println(playerChoice); // Send Player 1's choice to MATLAB
    delay(1000); // Wait for MATLAB to send the winner back
    if (Serial.available() > 0) {
      winner = Serial.parseInt(); // Receive the winner from MATLAB

      // Display the winner
      if (winner == 1) {
        digitalWrite(ledPlayer1, HIGH);  // Player 1 wins
        digitalWrite(ledPlayer2, LOW);
      } else if (winner == 2) {
        digitalWrite(ledPlayer1, LOW);
        digitalWrite(ledPlayer2, HIGH);  // Player 2 wins
      } else {
        digitalWrite(ledPlayer1, LOW);
        digitalWrite(ledPlayer2, LOW);  // Draw
      }

      // Reset the game
      playerChoice = 0;
      winner = 0;
      delay(3000); // Wait before resetting the game
    }
  }
}
