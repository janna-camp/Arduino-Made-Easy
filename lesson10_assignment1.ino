/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 10 Assignment 1
*   Hello World
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //create LCD object
  
void setup(){
  lcd.init(); //initialize the lcd
  lcd.backlight(); //turn on the backlight
  delay(2000); //delay 2 seconds to make sure display is initialized
  
  lcd.setCursor(0, 0); //set cursor to row 0, column 0
  lcd.print("Hello World"); // display Hello World on display
}

void loop(){

}