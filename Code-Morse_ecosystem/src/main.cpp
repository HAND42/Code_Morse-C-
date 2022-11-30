#include <Arduino.h>
#include <Traducteur/Traducteur.hpp>

int pin = 3; // Pin to connect the led to

Traducteur traducteur = Traducteur();

void setup()
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW); // Set first the LED to LOW

  Serial.begin(9600);
  Serial.println("Enter message:");
  
  delay(3000);

  // traducteur.BlinkLED(pin);     (old method)
}

void loop()
{
  traducteur.WriteMessage(); // This method ask the user a message to be transmitted
  traducteur.TraduceMessage(pin); // Traduce your message in Morse code through the flashing of a LED
}