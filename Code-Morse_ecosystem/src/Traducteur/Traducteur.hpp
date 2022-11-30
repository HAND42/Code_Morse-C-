#ifndef TRADUCTEUR_HPP
#define TRADUCTEUR_HPP

#include <Arduino.h>
#include "LettreMorse/LettreMorse.hpp"

/*
It is in this class that I do almost all the code. I could also have condensed the code only in this class,
because the class MorseLetter is not necessary here.

The purpose of having made several classes is to learn how to manage the implementation of these classes with the arduino c++ language
*/

class Traducteur
{
private:
    LettreMorse _Message[100];
    int length_message;
    String message;
    String message_morse;

    unsigned long previous_millis = 0; // We set this variable to 0, and then to millis(), in order to count the time passing

    int unsigned short_time = 100;                           // Time LED stay on for the symbole .
    int unsigned long_time = 300;                            // Time LED stay on for the symbole -

public:
    Traducteur();
    void WriteMessage();
    void ReadMessage(String message);
    void PrintMessage();
    int ConvertCharinTimeBright(char c);
    void TraduceMessage(int pin);
    void BlinkLED(int pin);
};

#endif
