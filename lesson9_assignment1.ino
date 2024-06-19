/*
*   Arduino Made Easy
*   by Janna Camp
*
*   Lesson 9 Assignment 1
*   Ultrasonic Alarm
*/

int trigPin = 9; //ultrasonic trig pin
int echoPin = 10; //ultrasonic echo pin

//LED pins
int green = 4;
int yellow = 5;
int red = 6;

int buzzer = 7; //buzzer pin

void setup() {
  //set ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //set LED pins to output
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  //set buzzer pins to output
  pinMode(buzzer, OUTPUT);

  //turn LEDs off
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
}

void loop() {

  digitalWrite(trigPin, LOW); //send low signal from trig pin to make sure pin is cleared
  delayMicroseconds(2); //delay 2 ms to ensure low signal registers in echo pin

  digitalWrite(trigPin, HIGH); //set trig pin to high to send ping
  delayMicroseconds(10); //delay 10 ms for ping to send
  digitalWrite(trigPin, LOW); //set trig pin to low to end ping

  //pulseIn function will measure the duration of time to receive ping on echo pin
  long duration = pulseIn(echoPin, HIGH);

  int distance = duration * 0.0343 / 2; //calculate distance using speed of sound

  if(distance <= 15){ //if 15 cm or less
    //turn on red light (green and yellow turn off)
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);

    tone(buzzer, 300); //play tone on buzzer to indicate close proximity
  }
  else if(distance > 15 and distance <= 30){ //if distance 16-30 cm
    //turn on yellow light (green and red turn off)
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);

    noTone(buzzer); //ensure buzzer is off
  }
  else{
    //turn on green light (yellow and red turn off)
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);

    noTone(buzzer); //ensure buzzer is off
  }
}