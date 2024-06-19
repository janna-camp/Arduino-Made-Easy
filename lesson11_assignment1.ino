/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 11 Assignment 1
*   Reading Keys
*/

#include <Keypad.h>

int sevSeg[] = {13,12,11,10,A3,A4,A5}; //seven segment display pins

// arrays for displaying each character
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

const byte ROWS = 4; //keypad has four rows
const byte COLS = 4; //keypad has four columns
char keys[ROWS][COLS] = { //array for keypad character layout
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

//create new keypad object
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  //for loop to set seven segment pins to output
  for(int i=0; i < 8; i++){
    pinMode(sevSeg[i],OUTPUT);
  }
}

void loop(){
  char key = keypad.getKey(); //get current pressed key

  if (key != NO_KEY){ //if a key is pressed
    switch(key){ //switch statement contains cases for each possible keypad value
      //each case has a for loop that sets each segment to 0/1 based on corresponding
      //character value array
      case '1':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],one[i]);
        }
      	break;
      case '2':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],two[i]);
        }
      	break;
      case '3':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],three[i]);
        }
      	break;
      case '4':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],four[i]);
        }
      	break;
      case '5':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],five[i]);
        }
      	break;
      case '6':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],six[i]);
        }
      	break;
      case '7':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],seven[i]);
        }
      	break;
      case '8':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],eight[i]);
        }
      	break;
      case '9':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],nine[i]);
        }
      	break;
      case '0':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],zero[i]);
        }
      	break;
      case 'A':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],a[i]);
        }
      	break;
      case 'B':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],b[i]);
        }
      	break;
      case 'C':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],c[i]);
        }
      	break;
      case 'D':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],d[i]);
        }
      	break;
      case '#':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],pound[i]);
        }
      	break;
      case '*':
        for(int i = 0; i < 8; i++){
          digitalWrite(sevSeg[i],ast[i]);
        }
      	break;
    }
  }
}