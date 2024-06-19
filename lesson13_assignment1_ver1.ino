/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 13 Assignment 1
*   Changing Speeds
*
*   Version 1
*/

int motorPin = 9; //set pin number for motor control pin
int potPin = A0; //set pin number for potentiometr

void setup() {
  pinMode(motorPin, OUTPUT); //set motor control pin to output
}

void loop() {
  //read the potentiometer pin and map the value from the analog range 0-1023 to the pwm range 0-255
  int pwmVal = map(analogRead(potPin),0,1023,0,255);
  
  //write the mapped value to the motor control pin
  analogWrite(motorPin,pwmVal);
}