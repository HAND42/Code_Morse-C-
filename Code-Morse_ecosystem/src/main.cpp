#include <Arduino.h>
#include <Traducteur/Traducteur.hpp>

int pin = 3;
// static unsigned long Time_between_blinks = 1000;
Traducteur traducteur = Traducteur();

void setup()
{
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter message:");
  while (Serial.available() == 0)
  {
    // wait for data available
  }
  String teststr = Serial.readString(); // read until timeout
  teststr.trim();
  traducteur.ReadMessage(teststr); // remove any \r \n whitespace at the end of the Strin
  digitalWrite(pin, LOW);
  delay(3000);
  traducteur.BlinkLED(pin);
}

void loop()
{

  // digitalWrite(pin, HIGH);
  // delay(2000);
  // digitalWrite(pin, LOW);
  // delay(2000);
}