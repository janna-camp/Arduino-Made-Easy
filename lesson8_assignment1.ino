/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 8 Assignment 1
*   Finding Light Levels
*/

void setup() {
  Serial.begin(9600); //begin serial monitor at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(A0)); //print analog pin val to serial monitor
  delay(500); //delay 500 ms (makes it easier to read serial monitor values)
}