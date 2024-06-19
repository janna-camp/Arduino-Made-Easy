/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 7 Assignment 2
*   Color Adjusting
*   Version 2
*/

void setup() {
  //set LED pins to output
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // map each potentiometer value from analog range 0-1023 to PWM range 0-255
  // and write each value to LED pins
  analogWrite(9, map(analogRead(A0),0,1023,0,255));
  analogWrite(10, map(analogRead(A1),0,1023,0,255));
  analogWrite(11, map(analogRead(A2),0,1023,0,255));
}