/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 2 Assignment 1
*   Blinky Blinky
*/

void setup() {
  pinMode(2,OUTPUT); //LED pin
}

void loop() {
  digitalWrite(2,HIGH); //Turn LED on
  delay(1000); //Wait 1 second
  digitalWrite(2,LOW); //Turn LED off
  delay(1000); //Wait 1 second
}