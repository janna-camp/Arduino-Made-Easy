/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 8 Assignment 2
*   Using Light Levels
*/

int photo = A0; //photoresistor pin
int LED = 9; //LED pin
int sevSeg[] = {2,3,4,5,6,7,8}; //seven segment display pins

// Seven-segment pin layout:
//    4
// 3     5
//    2
// 6     8
//    7

// arrays for displaying each number
// Pins:       2,3,4,5,6,7,8
int one[]   = {0,0,0,1,0,0,1};
int two[]   = {1,0,1,1,1,1,0};
int three[] = {1,0,1,1,0,1,1};
int four[]  = {1,1,0,1,0,0,1};
int five[]  = {1,1,1,0,0,1,1};
int six[]   = {1,1,1,0,1,1,1};

void setup() {
  //for loop to set seven segment pins to output
  for(int i = 2; i < 9; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(LED, OUTPUT); //set LED pin to output
}

void loop() {
  int prVal = analogRead(photo); //read photoresistor value

  // each part of the if/else if statement writes a pre-calculated value to the LED
  // and has a for loop that sets each LED to 0/1 based on corresponding die value array
  // change comparison values to represent readings from assignment 1

  if(prVal > 780){ //Seven segment value: 6
    analogWrite(LED, 255);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],six[i]);
    }
  }
  else if(prVal > 630){ //Seven segment value: 5
    analogWrite(LED, 213);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],five[i]);
    }
  }
  else if(prVal > 480){ //Seven segment value: 4
    analogWrite(LED, 171);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],four[i]);
    }
  }
  else if(prVal > 330){ //Seven segment value: 3
    analogWrite(LED, 129);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],three[i]);
    }
  }
  else if(prVal > 180){ //Seven segment value: 2
    analogWrite(LED, 87);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],two[i]);
    }
  }
  else if (prVal > 30){ //Seven segment value: 1
    analogWrite(LED, 45);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],one[i]);
    }
  }
  else{ //Turn LED and seven segment display off
    analogWrite(LED, 0);
    for(int i = 0; i < 7; i++){
      digitalWrite(sevSeg[i],LOW);
    }
  }

}
