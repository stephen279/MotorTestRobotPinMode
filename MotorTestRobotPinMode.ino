// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#define trigPin 12 // define the pins of your sensor
#define echoPin 13 


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
    pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
    pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
    pinMode(9, OUTPUT);   //lhs motor forward
    pinMode(11, OUTPUT);   // backways  right motor
    pinMode(8, OUTPUT);  // backways  left motor
    pinMode(10, OUTPUT);   // rhs mtor forward
     

}

void loop() {
  long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);



 delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.

  if (distance < 30)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
    Serial.println ("Close Obstacle detected!" );
    Serial.println ("Obstacle Details:");
    Serial.print ("Distance From Robot is " );
    Serial.print ( distance);
    Serial.print ( " CM!");// print out the distance in centimeters.

    Serial.println (" The obstacle is declared a threat due to close distance. ");
    Serial.println (" Turning !");
    //need to reinitialise all pinds are in right state
     digitalWrite(10, LOW);   // turn the rhs motor to low
     digitalWrite(9, HIGH);   // turn the lhs motor to high
     digitalWrite(11, HIGH);   // turn the rhs motor backways

}
  else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
     //need to reinitialise all pinds are in right state
     digitalWrite(9, HIGH);   // turn the lhs high
     digitalWrite(11, LOW);   // turn the lhs low
     digitalWrite(10, HIGH);   // turn the rhs motor high

  }  
  
 
}
