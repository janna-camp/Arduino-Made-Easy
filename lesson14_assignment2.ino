/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 14 Assignment 2
*   Garage Door Opener
*/

#include <Servo.h>

Servo myServo; //create new servo object

int posFlag = 0; //position flag (0 - closed, 1 - open)
int newFlag = 1; //button press flag (1 indicates new button press)

void setup() {
  //attach servo to pin 9 and write value of 0
  myServo.attach(9);
  myServo.write(0);

  pinMode(2,INPUT); //set button pin to input
}

void loop() {
  newFlag = 1; //set new button press flag to 1 as button press has not occurred
  int buttonVal = digitalRead(2); //read button pin
  
  while(buttonVal == HIGH){ //while button is pressed
    //if current servo position is 180 and button press is new
    if(posFlag == 1 and newFlag == 1){
      //set servo position to 0 - a for loop decrementing 180-0
      //with delay function is used to achieve smooth movement
      //through the range of values

      for(int i = 180; i >= 0; i--){
        myServo.write(i);
        delay(5);
      }

      posFlag = 0; //set position flag to 0 (new servo position 0) 
      newFlag = 0; //set new button press to 0 (button press has been fulfilled) 
    }
    
    if(posFlag == 0 and newFlag == 1){
      //set servo position to 180 - a for loop incrementing 0-180
      //with delay function is used to achieve smooth movement
      //through the range of values

      for(int i = 0; i <= 180; i++){
        myServo.write(i);
        delay(5);
      }
      posFlag = 1; //set position flag to 1 (new servo position 180) 
      newFlag = 0; //set new button press to 0 (button press has been fulfilled) 
  	}
    
    buttonVal = digitalRead(2); //read button pin
  }
}
