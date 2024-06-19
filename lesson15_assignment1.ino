/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 15 Assignment 1
*   Termperature Controlled Fan
*/

#include <Servo.h>

Servo myServo; //create new servo object

void setup() {
  myServo.attach(10); //attach servo to pin 10
  pinMode(6, OUTPUT); //set DC motor control pin to output
}

void loop() {
  int sensorVal = analogRead(A0); //read temperature sensor pin

  //equations to convert analog value into voltage and temperature values
  float voltage = sensorVal * (5.0 / 1024.0);
  float tempC = (voltage - 0.5) * 100;
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  //for each temperature range, write a pwm value to the DC motor control pin
  //and set servo motor to given position
  if(tempF > 100){
    analogWrite(6,80);
    myServo.write(144);
  }
  else if(tempF > 77){
    analogWrite(6,70);
    myServo.write(108);
  }
  else if(tempF > 50){
    analogWrite(6,60);
    myServo.write(72);
  }
  else{
    analogWrite(6,0);
    myServo.write(36);
  }

  delay(3000);
}
