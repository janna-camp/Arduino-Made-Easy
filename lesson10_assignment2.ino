/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 10 Assignment 2
*   Stopwatch
*/

#include <LiquidCrystal_I2C.h>

//button pins
int ssButton = 2;
int resetButton = 3;

//integers to hold pin readings
int ssButtonVal;
long startVal;

//flags to indicate if stopwatch has been started/stopped or reset
bool running = false;
bool reset = true;

LiquidCrystal_I2C lcd(0x27, 16, 2); //create new LCD object
  
void setup()
{
  //set button pins to input
  pinMode(ssButton, INPUT);
  pinMode(resetButton, INPUT);
  
  lcd.init(); //initialize the lcd
  lcd.backlight(); //turn on the backlight

  //display blank time on the top row
  lcd.setCursor(0, 0);
  lcd.print("Time: 00:00.000");
  
  //display button titles on the bottom row
  lcd.setCursor(0, 1);
  lcd.print("Start/Stop Reset");
}

void loop()
{
  ssButtonVal = digitalRead(ssButton); //read value of start/stop button

  //if start/stop button is pressed and stopwatch is not yet running, start the stopwatch
  while(ssButtonVal == HIGH and running == false){ 
    ssButtonVal = digitalRead(ssButton); //read value of start/stop button
    startVal = millis(); //get current runtime of program

    //calculate timer time from previous runtime and current runtime 
    //(if timer has been stopped and restarted)
    if(reset == false){startVal = millis()-currVal;}
    
    while(ssButtonVal == LOW){ //make sure button press is finished
      reset = false; //set reset flag to false (time is no longer 0 and thus not reset)
      running = true; //set running flag to true (stopwatch is now running)

      int currVal = millis() - startVal; // calculate the current time value by finding current millis and subtracting the start time
      int minutes = currVal / 60000; // calculate minutes (integer) by dividing the current time value by 60000
      int seconds = (currVal % 60000)/ 1000; // calculate seconds (integer) by dividing the current value by 1000
      int millisecs = currVal % 1000; // calculate milliseconds by finding the remainder of dividing the current time value by 1000 (modulus)

      //the sprintf function formats data to be displayed on the lcd
      //the string of characters gets saved to the char array timeDisp
      char timeDisp[9];
      sprintf(timeDisp, "%02d:%02d.%03d",minutes,seconds,millisecs);
      
      lcd.setCursor(6, 0); //set lcd cursor to column 6, row 0
      lcd.print(timeDisp); //print timeDisp array to lcd
      
      ssButtonVal = digitalRead(ssButton); //read value of start/stop button
    }
  }
  
  //if start/stop button is pressed and stopwatch is already running, stop the stopwatch
  while(ssButtonVal == HIGH and running == true){
    ssButtonVal = digitalRead(ssButton); //read value of start/stop button

    while(ssButtonVal == LOW){ //make sure button press is finished
      running = false; //set running flag to false (stopwatch is no longer running)
      
      //if reset button is pressed and stopwatch has not yet been reset
      if(digitalRead(resetButton) == HIGH and reset == false){ //reset the time
        reset = true; //set reset flag to true (time has been reset to 0)
        
        //display blank time on the top row
        lcd.setCursor(0, 0);
        lcd.print("Time: 00:00.000 ");
      }
      
      ssButtonVal = digitalRead(ssButton); //read value of start/stop button
    }
  }
}