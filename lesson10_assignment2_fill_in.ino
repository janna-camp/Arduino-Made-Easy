/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 10 Assignment 2
*   Stopwatch
*/

#include <LiquidCrystal_I2C.h>

//pins
int ssButton = 2;
int resetButton = 3;

//pin readings
int ssButtonVal;
long startVal;

//flags
bool running = false;
bool reset = true;

LiquidCrystal_I2C lcd(0x27, 16, 2);
  
void setup()
{
  //initialize button pins to input
  
  //initialize the lcd
  //turn on the backlight

  //set cursor to column 0, row 0
  //print "Time: 00:00.000" on lcd 
  
  //set cursor to column 0, row 1
  //print "Start/Stop Reset" on lcd
}

void loop()
{
  ssButtonVal = digitalRead(ssButton);

  while(ssButtonVal == HIGH and running == false){ //start the stopwatch
    ssButtonVal = digitalRead(ssButton);
    startVal = millis();
    
    if(reset == false){startVal = millis()-currVal;}

    while(ssButtonVal == LOW){ //make sure button press is finished
      //set reset flag to false (time is no longer 0 and thus not reset)
      //set running flag to true (stopwatch is now running)

      // calculate the current time value by finding current millis and subtracting the start time
      // calculate minutes (integer) by dividing the current time value by 60000
      // calculate seconds (integer) by dividing the current value by 1000
      // calculate milliseconds by finding the remainder of dividing the current time value by 1000 (modulus)

      char timeDisp[9];
      sprintf(timeDisp, "%02d:%02d.%03d",minutes,seconds,millisecs);
      
      //set lcd cursor to column 6, row 0
      //print timeDisp array to lcd
      
      ssButtonVal = digitalRead(ssButton);
    }
  }
  
  while(ssButtonVal == HIGH and running == true){ //stop the stopwatch
    ssButtonVal = digitalRead(ssButton);

    while(ssButtonVal == LOW){ //make sure button press is finished
      //set running flag to false (stopwatch is no longer running)
      
      if(digitalRead(resetButton) == HIGH and reset == false){ //reset the time
        //set reset flag to true (time has been reset to 0)
        //set cursor to column 0, row 0
        //print "Time: 00:00.000" on lcd 
      }
      
      ssButtonVal = digitalRead(ssButton);
    }
  }
}