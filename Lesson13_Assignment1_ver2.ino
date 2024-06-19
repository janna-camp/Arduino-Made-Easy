/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 13 Assignment 1
*   Changing Speeds
*
*   Version 2
*/

void setup() {
  pinMode(9, OUTPUT); //set motor control pin to output
}

void loop() {
  //read the potentiometer pin and map the value from the analog range 0-1023 to the pwm range 0-255
  //and write the mapped value to the motor control pin
  analogWrite(9,map(analogRead(A0),0,1023,0,255));
}