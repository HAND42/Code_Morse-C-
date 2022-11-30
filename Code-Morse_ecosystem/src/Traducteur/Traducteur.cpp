#include "Traducteur/Traducteur.hpp"
#include "Arduino.h"

/*
As we instantiate the translator at the beginning of main, before the setup() and loop() functions,
in order to use it in both blocks, I have not imposed any parameters, nor declared any attributes.
*/

Traducteur::Traducteur()
{
}

/*
This method sends a message to the user on the serial monitor and asks him to type a message,
which the program will record in the attributes of the class and print it if needed.
*/

void Traducteur::WriteMessage()
{
    
    String teststr = Serial.readString(); // read until timeout
    teststr.trim();                       // remove any \r \n whitespace at the end of the String
    ReadMessage(teststr);
}

/*
This method is directly called in WriteMessage(). It retrieves the message typed by the user
and transforms it into an array of Morse code letters (for the BlinkLed() method) and into a Morse code string (for the TranslateMessage() method)
*/

void Traducteur::ReadMessage(String message)
{
    this->length_message = message.length();
    this->message = message;

    for (unsigned int i = 0; i < message.length(); i++)
    {
        _Message[i] = LettreMorse(message[i]);
        for (char c : _Message[i].GetMorse())
        {
            message_morse = message_morse + c + ":"; // Separate char morse with :
        }
        message_morse += "/"; // Separate char letter with /
    }
}

/*
Displays the message and its conversion to Morse code to ensure that everything is working normally
*/

void Traducteur::PrintMessage()
{
    Serial.print(message + ": ");
    Serial.println(length_message + "(Size message)");
    Serial.println(message_morse);
}

/*
Version 2 of the method. This one does not block the program by displaying the Morse code.
The LED flashes and receives instructions over time but allows the arduino board to perform
other tasks in parallel.
*/

void Traducteur::TraduceMessage(int pin)
{

    char c = this->message_morse.charAt(0);

    switch (c)
    {
    case '-':
        if (millis() - previous_millis >= this->long_time)
        {
            digitalWrite(pin, LOW);
            Serial.print('-');
            previous_millis = millis();
            message_morse = message_morse.substring(1);
        }
        break;
    case '.':
        if (millis() - previous_millis >= this->short_time)
        {
            digitalWrite(pin, LOW);
            Serial.print('.');
            previous_millis = millis();
            message_morse = message_morse.substring(1);
        }
        break;

    case '#':
        if (millis() - previous_millis >= this->short_time*7)
        {
            digitalWrite(pin, LOW);
            Serial.print('#');
            previous_millis = millis();
            message_morse = message_morse.substring(1);
        }
        break;

    case ':':
        if (millis() - previous_millis >= this->short_time)
        {
            digitalWrite(pin, HIGH);
            Serial.print(':');
            previous_millis = millis();
            message_morse = message_morse.substring(1);
        }
        break;
    case '/':
        if (millis() - previous_millis >= this->short_time*3)
        {
            digitalWrite(pin, HIGH);
            Serial.print('/');
            previous_millis = millis();
            message_morse = message_morse.substring(1);
        }
        break;

    default:
        digitalWrite(pin, LOW);
    }
}

/*
In this method, I convert each character . or - into the time in which the LED stays on.
*/

int Traducteur::ConvertCharinTimeBright(char c)
{
    int res = 0;
    switch (c)
    {
    case '-':
        res = this->long_time;
        break;
    case '.':
        res = this->short_time;
        break;
    default:
        res = this->short_time;
    };

    return res;
}

/*
Version 1: We can see here that I force the program to stay in the while loop until the time limit is reached and until the message is sent.
This keeps the program in this function.
*/

void Traducteur::BlinkLED(int pin)
{
    String morse = "";
    bool le_printed = false;
    bool c_printed = false;
    bool tbetween_blinks = false;

    unsigned long previous_millis = millis();
    for (int i = 0; i < length_message; i++)
    {
        le_printed = false;

        while (!le_printed)
        {
            if (millis() - previous_millis >= short_time*3)
            {
                int i = 0;
                morse = _Message[i].GetMorse();
                Serial.print(millis());
                previous_millis = millis();
                Serial.print(": La led va s'allumer (commencement lettre): ");
                Serial.println(morse);

                for (int j = 0; j < morse.length(); j++)
                {
                    // set the pin to high
                    digitalWrite(pin, HIGH);
                    Serial.print(millis());
                    previous_millis = millis();
                    Serial.print(": La led s'allume : ");
                    Serial.println(morse[j]);

                    c_printed = false;
                    while (!c_printed)
                    {
                        if (millis() - previous_millis >= ConvertCharinTimeBright(morse[j]))
                        {
                            // set pin to low
                            digitalWrite(pin, LOW);
                            Serial.print(millis());
                            previous_millis = millis();
                            Serial.print(": La led s'eteint: ");
                            Serial.println(morse[j]);
                            c_printed = true;
                            tbetween_blinks = false;
                            if (j + 1 < morse.length())
                            {
                                while (!tbetween_blinks)
                                {
                                    if (millis() - previous_millis >= short_time)
                                    {
                                        // set pin to high
                                        digitalWrite(pin, HIGH);
                                        previous_millis = millis();
                                        Serial.print(millis());
                                        Serial.println(": La led s'allume ()");
                                        tbetween_blinks = true;
                                    }
                                }
                            }
                        }
                    }
                    le_printed = true;
                }
            }
        }
    }
}