/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 7 Assignment 1
*   Buzzing About
*/

//buzzer: pin 2
//potentiometer: pin A0

void setup() {
  pinMode(2,OUTPUT); //set buzzer pin to output
}

void loop() {
  //map value of potentiometer from analog range 0-1023 to frequency range 31-5000
  int freqVal = map(analogRead(A0),0,1023,31,5000);
  tone(2,freqVal); //play mapped frequency on buzzer
}
