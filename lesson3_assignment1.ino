/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 3 Assignment 1
*   One-Way Traffic Signal
*/

int green = 2; //Schematic: LED3
int yellow = 3; //Schematic: LED2
int red = 4; //Schematic: LED1

void setup() {
  //Initialize LED pins to output
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  //Turn green and yellow off and red on
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
}

void loop() {
  delay(5000); //5 seconds for red light

  //Turn red off and green on
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(5000); //5 seconds for green light

  //Turn green off and yellow on
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(2000); //2 seconds for yellow light

  //Turn yellow off and red on
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
}
