/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 16 Assignment 1
*   Stepper Motor Timer
*/

#include <Stepper.h>

//set LED pin values
int red = 3;
int green = 5;
int blue = 6;

//set buzzer and button pin values
int piezo = 7;
int button = 12;

Stepper myStepper(2048, 8, 10, 9, 11);

void setup() {
  //set LED pins to output
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

  //blue light on to indicate timer is not running
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);

  //initialize buzzer and button pins
  pinMode(piezo,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  if(digitalRead(button) == HIGH){ //if button pressed - start timer
    //turn blue light off and green light on
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);

    //move stepper for 45 seconds (1536 steps at 1 rpm)
    myStepper.setSpeed(1);
    myStepper.step(1536);

    digitalWrite(red, HIGH); //turn red light on (green + red = yellow)
    myStepper.step(341); //move stepper for 10 seconds

    digitalWrite(green, LOW); //turn green light off (red stays on)
    myStepper.step(171); //move stepper for 5 seconds

    digitalWrite(red, LOW); //turn red light off

    //play tone on buzzer for 3 seconds, then turn off
    tone(piezo, 440);
    delay(3000);
    noTone(piezo);

  }

  digitalWrite(blue, HIGH); //turn blue light back on to indicate timer is finished

}