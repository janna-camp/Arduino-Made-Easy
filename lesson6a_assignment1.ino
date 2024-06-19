/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 6a  Assignment 1
*   Electronic Die #1
*/

int tilt = 9; //tilt switch pin
int tiltState; //integer to hold the value of the tilt switch pin
int rolled = 0; //flag to show if die has been rolled
int off = 0; //flag to show if lights are off
int LEDs[] = {2,3,4,5,6,7,8}; //LED pins

// LED pin layout:
// 2     6
// 3  5  7
// 4     8

// arrays for displaying each number
// Pins:       2,3,4,5,6,7,8
int one[]   = {0,0,0,1,0,0,0};
int two[]   = {1,0,0,0,0,0,1};
int three[] = {1,0,0,1,0,0,1};
int four[]  = {1,0,1,0,1,0,1};
int five[]  = {1,0,1,1,1,0,1};
int six[]   = {1,1,1,0,1,1,1};

void setup() {
  //for loop to set LED pins to output (0-7 index values for LED array)
  for(int i = 0; i < 8; i++){
    pinMode(LEDs[i], OUTPUT);
  }

  pinMode(tilt, INPUT); //set tilt switch pin to input

  //for loop to turn all LEDs off
  for(int i = 0; i < 8; i++){
    digitalWrite(LEDs[i], LOW);
  }
}

void loop() {
  tiltState = digitalRead(tilt); //read tilt switch

  while(tiltState == LOW){ //while tilt switch is tilted (die is being rolled)
    if(off == 0){ //if LEDs are not off, turn them all off and set off flag to 1
      for(int i = 0; i < 7; i++){
        digitalWrite(LEDs[i],LOW);
      }
      off = 1;
    }
    
    tiltState = digitalRead(tilt); //read tilt switch
    rolled = 1; //die has been rolled
  }

  //if switch is not tilted (die is not being rolled) and die has been rolled (rolled flag)
  if(tiltState == HIGH and rolled == 1){ 
    rolled = 0; //reset rolled flag as roll will be fulfilled once if statement completes
    off = 0; //reset off flag as LEDs will be on once if statement completes
    int dice = random(1,7); //create variable to hold roll value - random value 1-6

    switch(dice){ //switch statement contains cases for each possible die value
      //each case has a for loop that sets each LED to 0/1 based on corresponding
      //die value array
      
      case 1:
        for(int i = 0; i < 7; i++){
          digitalWrite(LEDs[i],one[i]);
        }
        break;
      case 2:
        for(int i = 0; i < 7; i++){
          digitalWrite(LEDs[i],two[i]);
        }
        break;
      case 3:
        for(int i = 0; i < 7; i++){
          digitalWrite(LEDs[i],three[i]);
        }
        break;
      case 4:
        for(int i = 0; i < 7; i++){
          digitalWrite(LEDs[i],four[i]);
        }
        break;
      case 5:
        for(int i = 0; i < 7; i++){
          digitalWrite(LEDs[i],five[i]);
        }
        break;
      case 6:
        for(int i = 0; i < 7; i++){
          digitalWrite(LEDs[i],six[i]);
        }
        break;
    }
  }
}
