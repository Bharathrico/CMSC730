#include <Arduino.h>
// constants definition
const int ledPin = 2; 
const int sensorPin = 15; 
// The setup() method runs once, when the sketch starts
void setup()
{
  // initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{
  // for (int brightness = 0; brightness <= 255; brightness++)
  // {
  //   analogWrite(ledPin, brightness); 
  //   delay(20);       
  // }

  // for (int brightness = 255; brightness >=0; brightness--)
  // {
  //   analogWrite(ledPin, brightness); 
  //   delay(20);        
  // }


  int sensorValue = analogRead(sensorPin);
  int brightness=map(sensorValue,1000,4000,0,255);
  Serial.println(sensorValue);
  // Serial.println("brightness:",brightness);
  analogWrite(ledPin,brightness);
  delay(100);
}

