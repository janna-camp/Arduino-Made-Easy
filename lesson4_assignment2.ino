/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 4 Assignment 2
*   Button Buzzer
*/

void setup() {
  pinMode(2, INPUT); //button set to input
  pinMode(3, OUTPUT); //buzzer set to output
}

void loop() {
  if(digitalRead(2) == HIGH){ //if button is pressed
    tone(3, 440); //play note
  }
  else{ //if button is not pressed
    noTone(3); //stop note
  }
}