
#include "LettreMorse/LettreMorse.hpp"
#include <Arduino.h>

/*
The initializer allows at the time of the creation of the objects to call directly the necessary associated methods.
It defines two attributes : _lettre and _morse.
*/
LettreMorse::LettreMorse(char letter)
{

    _lettre = letter;
    _morse = "";
    ConvertLettertoMorse(_lettre);
}

LettreMorse::LettreMorse()
{
}

/*
This method gives the set of Morse code equivalents listed in this function
*/

void LettreMorse::ConvertLettertoMorse(char letter)
{

    switch (letter)
    {
    case ' ':
        this->_morse = "#"; //Seperate word
        break;
    case 'a':
        this->_morse = ".-";
        break;
    case 'b':
        this->_morse = "-...";
        break;
    case 'c':
        this->_morse = "-.-.";
        break;
    case 'd':
        this->_morse = "-..";
        break;
    case 'e':
        this->_morse = ".";
        break;
    case 'f':
        this->_morse = "..-.";
        break;
    case 'g':
        this->_morse = "--.";
        break;
    case 'h':
        this->_morse = "....";
        break;
    case 'i':
        this->_morse = "..";
        break;
    case 'j':
        this->_morse = ".---";
        break;
    case 'k':
        this->_morse = "-.-";
        break;
    case 'l':
        this->_morse = ".-..";
        break;
    case 'm':
        this->_morse = "--";
        break;
    case 'n':
        this->_morse = "-.";
        break;
    case 'o':
        this->_morse = "---";
        break;
    case 'p':
        this->_morse = ".--.";
        break;
    case 'q':
        this->_morse = "--.-";
        break;
    case 'r':
        this->_morse = ".-.";
        break;
    case 's':
        this->_morse = "...";
        break;
    case 't':
        this->_morse = "-";
        break;
    case 'u':
        this->_morse = "..-";
        break;
    case 'v':
        this->_morse = "...-";
        break;
    case 'w':
        this->_morse = ".--";
        break;
    case 'x':
        this->_morse = "-..-";
        break;
    case 'y':
        this->_morse = "-.--";
        break;
    case 'z':
        this->_morse = "--..";
        break;
    case '1':
        this->_morse = ".----";
        break;
    case '2':
        this->_morse = "..---";
        break;
    case '3':
        this->_morse = "...--";
        break;
    case '4':
        this->_morse = "....-";
        break;
    case '5':
        this->_morse = ".....";
        break;
    case '6':
        this->_morse = "-....";
        break;
    case '7':
        this->_morse = "--...";
        break;
    case '8':
        this->_morse = "---..";
        break;
    case '9':
        this->_morse = "----.";
        break;
    case '0':
        this->_morse = "-----";
        break;
    default:
        this->_morse = "";
        break;
    }
}

String LettreMorse::GetMorse()
{
    return _morse;
}
