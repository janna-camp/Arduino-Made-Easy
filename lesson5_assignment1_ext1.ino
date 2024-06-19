/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 5 Assignment 1
*   Mini Piano
*
*   Project Extension #1
*/

int buzzer = 10; //buzzer pin
int notes[] = {262, 294, 330, 349, 392, 440, 494, 523}; //note frequencies
int buttons[] = {0,0,0,0,0,0,0,0}; //array to hold button pin read values

void setup() {
  //for loop to set pins 2-9 to input
  for(int i = 2; i < 10; i++){
    pinMode(i,INPUT);
  }
  pinMode(buzzer, OUTPUT); //buzzer pin set to output
}

void loop() {
  //for loop uses numbers 0-7 to set button array values
  //array values are digital readings of pins 2-9
  for(int i = 0; i < 8; i++){
    buttons[i] = digitalRead(i+2);
  }

  //if/else if/else statement to check button values
  //if a button is high, that frequency will play
  //if multiple buttons are pressed, the first button pressed will be the frequency played
  //if no button is pressed, buzzer will be turned off
  
  if(buttons[0] == HIGH){
    tone(buzzer, notes[0]);
  }
  else if(buttons[1] == HIGH){
    tone(buzzer, notes[1]);
  }
  else if(buttons[2] == HIGH){
    tone(buzzer, notes[2]);
  }
  else if(buttons[3] == HIGH){
    tone(buzzer, notes[3]);
  }
  else if(buttons[4] == HIGH){
    tone(buzzer, notes[4]);
  }
  else if(buttons[5] == HIGH){
    tone(buzzer, notes[5]);
  }
  else if(buttons[6] == HIGH){
    tone(buzzer, notes[6]);
  }
  else if(buttons[7] == HIGH){
    tone(buzzer, notes[7]);
  }
  else{
    noTone(buzzer);
  }
}
