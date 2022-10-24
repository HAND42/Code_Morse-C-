#include "Traducteur/Traducteur.hpp"
#include "Arduino.h"

Traducteur::Traducteur()
{
}

void Traducteur::ReadMessage(String message)
{
    this->length_message = message.length();

    for (unsigned int i = 0; i < message.length(); i++)
    {
        _Message[i] = LettreMorse(message[i]);
    }
}

void Traducteur::BlinkLED(int pin)
{
    String morse = "";
    bool le_printed = false;
    bool c_printed = false;
    bool tbetween_blinks = false;

    Serial.print("Size message");
    Serial.println(length_message);
    unsigned long previous_millis = 0;
    for (int i = 0; i < length_message; i++)
    {
        le_printed = false;
        morse = _Message[i].GetMorse();

        while (!le_printed)
        {
            if (millis() - previous_millis >= between_letter)
            {
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
                                    if (millis() - previous_millis >= Time_between_blinks)
                                    {
                                        // set pin to high
                                        digitalWrite(pin, HIGH);
                                        previous_millis = millis();
                                        Serial.print(millis());
                                        Serial.println(": La led s'allume ()");
                                        tbetween_blinks = true;
                                    }
                                    else
                                    {
                                    }
                                }
                            }
                        }
                        else
                        {
                        }
                    }
                }
                le_printed = true;
            }
            else
            {
            }
        }
    }
}

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
