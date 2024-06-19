/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 12 Assignment 1
*   Scoreboard
*/

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// To use scoreboard:
// - Press button A/B to choose home/away
// - Press number keys to enter score
// - Press # to set score after entering
// - Press * to reset score to 0

int colPos = 0; //column position variable will be updated based on home/away selection

LiquidCrystal_I2C lcd(0x27, 16, 2); //create new LCD object

const byte ROWS = 4; //keypad has four rows
const byte COLS = 4; //keypad has four columns
char keys[ROWS][COLS] = { //array for keypad character layout
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //create new keypad object

void setup() {
  lcd.init(); //initialize the lcd
  lcd.backlight(); //turn on the backlight
  
  //display heading on top row
  lcd.setCursor(0, 0);
  lcd.print("  Home    Away");
}

void loop() {
  char teamKey = keypad.getKey(); //get key press for home/away selection

  if (teamKey != NO_KEY){ //if key is pressed

    //set column position based on home/away selection
    if(teamKey == 'A'){ colPos = 2; }
    else if(teamKey == 'B'){ colPos = 10; }

    char scoreKey = keypad.getKey(); //get key press for score input

    if(colPos != 0){ //if colPos is not 0, then a team has been selected
      lcd.setCursor(colPos, 1); //set cursor to colPos on row 1
      lcd.print("        "); //clear score by writing over current score with spaces
      lcd.setCursor(colPos, 1); //set cursor to colPos on row 1
      lcd.blink(); //blink cursor so user knows program is ready to have score entered

      while(scoreKey != '#'){ //while score is being entered
        //if key pressed is a number or *
        if(scoreKey != NO_KEY and scoreKey != 'A' and scoreKey != 'B' and scoreKey != 'C' and scoreKey != 'D'){ 
          if(scoreKey == '*'){ //if * pressed then reset score to 0 for selected team
            lcd.setCursor(colPos, 1); //set cursor to colPos on row 1
            lcd.print("        "); //print over score with spaces
            lcd.setCursor(colPos, 1); //set cursor to colPos on row 1
            lcd.print('0'); //print 0 as new score
            break; //exit while loop
          }

          lcd.print(scoreKey); //print pressed number to screen
        }
        scoreKey = keypad.getKey(); //get next key press       
      } 
    }
    
    lcd.noBlink(); //stop blinking cursor since score entering is finished
    colPos = 0; //reset column position to 0
  }
}
