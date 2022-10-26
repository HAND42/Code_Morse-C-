#ifndef LETTREMORSE_HPP
#define LETTREMORSE_HPP

#include <Arduino.h>

/*
LettreMorse class declaration:
This class allows me to create objects by associating each character with its equivalent in Morse code.
*/

class LettreMorse
{

private:
    char _lettre = 0;
    String _morse;

public:
    LettreMorse(char letter);
    LettreMorse();
    void ConvertLettertoMorse(char letter);
    String GetMorse();
};

#endif
