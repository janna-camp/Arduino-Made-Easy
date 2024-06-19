/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 5 Assignment 1
*   Mini Piano
*/

int buzzer = 10; //buzzer pin

//note frequencies
int c1 = 262;
int d = 294;
int e = 330;
int f = 349;
int g = 392;
int a = 440;
int b = 494;
int c2 = 523;

void setup() {
  //for loop to set pins 2-9 to input (buttons)
  for(int i = 2; i < 10; i++){
    pinMode(i,INPUT);
  }
  pinMode(buzzer, OUTPUT); //set buzzer pin to output
}

void loop() {
  //read each button press
  int button1 = digitalRead(2);
  int button2 = digitalRead(3);
  int button3 = digitalRead(4);
  int button4 = digitalRead(5);
  int button5 = digitalRead(6);
  int button6 = digitalRead(7);
  int button7 = digitalRead(8);
  int button8 = digitalRead(9);

  //if/else if/else statement to check button values
  //if a button is high, that frequency will play
  //if multiple buttons are pressed, the first button pressed will be the frequency played
  //if no button is pressed, buzzer will be turned off

  if(button1 == HIGH){
    tone(buzzer, c1);
  }
  else if(button2 == HIGH){
    tone(buzzer, d);
  }
  else if(button3 == HIGH){
    tone(buzzer, e);
  }
  else if(button4 == HIGH){
    tone(buzzer, f);
  }
  else if(button5 == HIGH){
    tone(buzzer, g);
  }
  else if(button6 == HIGH){
    tone(buzzer, a);
  }
  else if(button7 == HIGH){
    tone(buzzer, b);
  }
  else if(button8 == HIGH){
    tone(buzzer, c2);
  }
  else{
    noTone(buzzer);
  }
}
