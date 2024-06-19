/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 11 Assignment 1
*   Reading Keys
*/

#include <Keypad.h>

int sevSeg[] = {13,12,11,10,A3,A4,A5,A2};

int one[]   = {0,0,0,1,0,0,1};
int two[]   = {1,0,1,1,1,1,0};
int three[] = {1,0,1,1,0,1,1};
int four[]  = {1,1,0,1,0,0,1};
int five[]  = {1,1,1,0,0,1,1};
int six[]   = {1,1,1,0,1,1,1};
int seven[] = {0,0,1,1,0,0,1};
int eight[] = {1,1,1,1,1,1,1};
int nine[]  = {1,1,1,1,0,0,1};
int zero[]  = {0,1,1,1,1,1,1};
int a[]     = {1,1,1,1,1,0,1};
int b[]     = {1,1,0,0,1,1,1};
int c[]     = {0,1,1,0,1,1,0};
int d[]     = {1,0,0,1,1,1,1};
int pound[] = //fill in your own display
int ast[]   = //fill in your own display

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  for(int i=0; i < 8; i++){
    pinMode(sevSeg[i],OUTPUT);
  }
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    switch(key){
      case '1':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],one[i]);
        }
      	break;
      //////////////////////////////////////////////////////////
      // fill in switch cases

      //////////////////////////////////////////////////////////
    }
  }
    
}
