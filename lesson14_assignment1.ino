/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 14 Assignment 1
*   Point the Way
*/

#include <Servo.h>

Servo myServo; //create new servo object
int servoPos = 0; //integer to hold servo position

void setup() {
  //attach servo to pin 9 and write current servoPos (0)
  myServo.attach(9);
  myServo.write(servoPos);

  //set button pins to input
  pinMode(2,INPUT);
  pinMode(3, INPUT);
}

void loop() {
  //while button 1 is pressed and servo is not at minimum value
  while(digitalRead(2) == HIGH and servoPos > 0){
    servoPos--; //decrement servo position integer
    myServo.write(servoPos); //write new position value
    delay(5); //delay 5 milliseconds to allow for servo movement
  }

  //while button 2 is pressed and servo is not at maximum value
  while(digitalRead(3) == HIGH and servoPos < 180){
    servoPos++; //increment servo position integer
    myServo.write(servoPos); //write new position value
    delay(5); //delay 5 milliseconds to allow for servo movement
  }
}
