#ifndef TRADUCTEUR_HPP
#define TRADUCTEUR_HPP

#include <Arduino.h>
#include "LettreMorse/LettreMorse.hpp"

class Traducteur
{
private:
    LettreMorse _Message[100];
    int length_message;
    const unsigned long Time_between_blinks = 2000;

public:
    int short_time = 500;
    int long_time = 1000;

    unsigned long between_letter = 3000;
    Traducteur();
    void ReadMessage(String message);
    int ConvertCharinTimeBright(char c);
    void BlinkLED(int pin);
};

#endif
