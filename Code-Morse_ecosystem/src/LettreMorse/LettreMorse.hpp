#ifndef LETTREMORSE_HPP
#define LETTREMORSE_HPP

#include <Arduino.h>

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
