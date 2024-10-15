#include "bendSensorConfig.h"
#include <Keyboard.h>
// change this to whatever pin the bend sensor is connected to. 
const int inputPin = A0; 

int bendSenseValue
int bendSensePrev = 0

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);

  // testing bend sensor configuration settings
  config::bendSenseLow[0] = 80;
  config::bendSenseHigh[0] = 120;
  config::bendSenseThreshold[0] = 100;
  // These values are just wild guesses.

  Keyboard.begin();
  Serial.begin(9600);
  Serial.println("Beginning monitoring of bend sensor!");
}

void loop() {
  // put your main code here, to run repeatedly:

  // get input of bend sensor here
  bendSenseValue = analogRead(inputPin);
  
  //bendSenseValue = debugGetValueFromSerialConsole();

  // This outputs the value of the inputPin to the serial console
  Serial.println(bendSenseValue);
  // This is what I think the code for "button presses" would look like.
  // Basically, make sure you're within the bounds of the sensing values
  // Then if the new value is above the threshold and the previous was not 
  // (aka we passed the threshold) Then we fire off a button press
  // If we are below the threshold and we weren't before we release the button
  if (bendSenseValue >= bendSenseLow[0] && bendSenseValue <= bendSenseHigh[0]) {
    if (bendSenseValue >= bendSenseThreshold[0] && bendSensePrev < bendSenseThreshold[0]) {
      Keyboard.press("a");
    }
    else if (bendSenseValue < bendSenseThreshold[0] && bendSensePrev >= bendSenseThreshold[0]) {
      Keyboard.releaseAll();
    }
  }
  // store this value to be compared to later.
  bendSensePrev = bendSenseValue
}

// used for debugging, if you don't want to set up a bend sensor
// this will read values from the serial console and then set that to
// the return value of the function.
// Ideally this will be used to replace bendSenseValue in the loop
int debugGetValueFromSerialConsole() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

    return incomingByte
  }
}