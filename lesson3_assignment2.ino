/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 3 Assignment 1
*   Four-Way Traffic Signal
*/

int red_1 = 4; //Schematic: LED4
int yellow_1 = 3; //Schematic: LED5
int green_1 = 2; //Schematic: LED6

int red_2 = 7; //Schematic: LED10
int yellow_2 = 6; //Schematic: LED11
int green_2 = 5; //Schematic: LED12

int red_3 = 8; //Schematic: LED9
int yellow_3 = 9; //Schematic: LED8
int green_3 = 10; //Schematic: LED7

int red_4 = 11; //Schematic: LED3
int yellow_4 = 12; //Schematic: LED2
int green_4 = 13; //Schematic: LED1

// Pairs of Lights: 1/4 ; 2/3

void setup() {
  
  //Set all LED pins to output
  pinMode(green_1, OUTPUT);
  pinMode(yellow_1, OUTPUT);
  pinMode(red_1, OUTPUT);

  pinMode(green_2, OUTPUT);
  pinMode(yellow_2, OUTPUT);
  pinMode(red_2, OUTPUT);

  pinMode(green_3, OUTPUT);
  pinMode(yellow_3, OUTPUT);
  pinMode(red_3, OUTPUT);

  pinMode(green_4, OUTPUT);
  pinMode(yellow_4, OUTPUT);
  pinMode(red_4, OUTPUT);

  ///////////////////////////////////////

  //Turn all red lights on and all green and yellow lights off
  digitalWrite(green_1, LOW);
  digitalWrite(yellow_1, LOW);
  digitalWrite(red_1, HIGH);

  digitalWrite(green_2, LOW);
  digitalWrite(yellow_2, LOW);
  digitalWrite(red_2, HIGH);

  digitalWrite(green_3, LOW);
  digitalWrite(yellow_3, LOW);
  digitalWrite(red_3, HIGH);

  digitalWrite(green_4, LOW);
  digitalWrite(yellow_4, LOW);
  digitalWrite(red_4, HIGH);
}

void loop() {

  delay(1000); //1 second of all red lights

  ///////////////////////////////////////

  //Turn 2 & 3 red off and green on
  digitalWrite(red_2, LOW);
  digitalWrite(red_3, LOW);
  digitalWrite(green_2, HIGH);
  digitalWrite(green_3, HIGH);

  delay(5000); //5 seconds of 2 & 3 green

  //Turn 2 & 3 green off and yellow on
  digitalWrite(green_2, LOW);
  digitalWrite(green_3, LOW);
  digitalWrite(yellow_2, HIGH);
  digitalWrite(yellow_3, HIGH);

  delay(2000); //2 seconds of 2 & 3 yellow

  ///////////////////////////////////////

  //Turn 2 & 3 yellow off and red on
  digitalWrite(yellow_2, LOW);
  digitalWrite(yellow_3, LOW);
  digitalWrite(red_2, HIGH);
  digitalWrite(red_3, HIGH);

  delay(1000); //1 second of all red

  ///////////////////////////////////////

  //Turn 1 & 4 red off and green on
  digitalWrite(red_1, LOW);
  digitalWrite(red_4, LOW);
  digitalWrite(green_1, HIGH);
  digitalWrite(green_4, HIGH);

  delay(5000); //5 seconds of 1 & 4 green

  //Turn 1 & 4 green off and yellow on
  digitalWrite(green_1, LOW);
  digitalWrite(green_4, LOW);
  digitalWrite(yellow_1, HIGH);
  digitalWrite(yellow_4, HIGH);

  delay(2000); //2 seconds of 1 & 4 yellow

  ///////////////////////////////////////

  //Turn 1 & 4 yellow off and red on
  digitalWrite(yellow_1, LOW);
  digitalWrite(yellow_4, LOW);
  digitalWrite(red_1, HIGH);
  digitalWrite(red_4, HIGH);
}