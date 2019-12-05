#include <Arduino.h>
#include <menu.h>

#include <ctype.h>
#include <stdint.h>

#define BUFFER_SIZE 4

void print_main_menu()
{
    Serial.print("\n\n Options \n\n");
    Serial.print(" (S) Sine waveform\n");
    Serial.print(" (T) Triangle waveform \n");
    Serial.print(" Select option: ");
}

void print_selection_menu()
{
    Serial.print("\n Options \n");
    Serial.print(" (F) Select frequency\n");
    Serial.print(" (M) Select magnitude\n");
    Serial.print(" (I) Show information\n");
    Serial.print(" (B) Back\n");
    Serial.print(" Selection option: ");
}

char read_option_main_menu()
{
    char option = 0;

    while ((option != 'S') && (option != 'T') && (option != '\n'))
    {
        if (Serial.available())
        {
            option = toupper(Serial.read());
        }
    }

    Serial.printf("%c\n\n", option);

    return option;
}

char read_selection_menu()
{
    char option = 0;

    while ((option != 'F') && (option != 'I') && (option != 'M') && (option != 'B') && (option != '\n'))
    {
        if (Serial.available())
        {
            option = toupper(Serial.read());
        }
    }

    Serial.printf("%c\n\n", option);

    return option;
}

uint16_t set_frequency()
{

    char buffer[BUFFER_SIZE];
    uint8_t i = 0;

    uint16_t frequency_value = 0;

    while (i < BUFFER_SIZE)
    {
        if (Serial.available())
        {
            char temp = Serial.read();
            if (temp == '\n')
            {
                break;
            }
            else if (isdigit(temp))
            {
                Serial.print(temp);
                buffer[i] = temp;
                i++;
            }
        }
    }

    buffer[BUFFER_SIZE - 1] = '\0';

    frequency_value = atoi(buffer);

    Serial.clear();

    return frequency_value;
}