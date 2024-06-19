/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 4 Assignment 1
*   Button Pushing
*/

void setup() {
  pinMode(2, OUTPUT); //LED set to output
  pinMode(3, INPUT); //button set to input
}

void loop() {
  if(digitalRead(3) == HIGH){ //if button is pressed
    digitalWrite(2, HIGH); //turn LED on
  }
  else{ //if button is not pressed
    digitalWrite(2, LOW); //turn LED off
  }
}
