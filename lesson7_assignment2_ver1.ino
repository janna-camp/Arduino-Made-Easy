/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 2 Assignment 1
*   Color Adjusting
*   Version 1
*/

//pin numbers for RGB LED pins
int red = 9;
int green = 10;
int blue = 11;

//pin numbers for potentiometer pins
int redPot = A0;
int greenPot = A1;
int bluePot = A2;

void setup() {
  //set LED pins to output
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  // map each potentiometer value from analog range 0-1023 to PWM range 0-255
  int redVal   = map(analogRead(redPot),0,1023,0,255);
  int greenVal = map(analogRead(greenPot),0,1023,0,255);
  int blueVal  = map(analogRead(bluePot),0,1023,0,255);

  //write each mapped val to LED pins
  analogWrite(red,redVal);
  analogWrite(green,greenVal);
  analogWrite(blue,blueVal);
}
