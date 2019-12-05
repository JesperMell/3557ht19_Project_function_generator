#include <Arduino.h>
#include <menu.h>

#include <ctype.h>
#include <stdint.h>


void print_menu()
{
    Serial.printf("%c) Select the waveform\n", WAVEFORM_OPTION);
    Serial.printf("%c) Set the frequency\n", FREQUENCY_OPTION);
    Serial.printf("%c) Set the magnitude\n", MAGNITUDE_OPTION);
    Serial.printf("%c) Information\n", INFORMATION_OPTION);
    Serial.print("Enter the command: ");
}



char waveform_option()
{
    char option = 0;

    while ((option != SINE_WAVEFORM) && (option != TRIANGLE_WAVEFORM) && (option != '\n'))
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

    while ((option != FREQUENCY_OPTION) && (option != INFORMATION_OPTION) && (option != MAGNITUDE_OPTION) && (option != WAVEFORM_OPTION) && (option != '\n'))
    {
        if (Serial.available())
        {
            option = toupper(Serial.read());
        }
    }

    Serial.printf("%c\n\n", option);

    return option;
}

uint16_t set_wave_values()
{

    char buffer[BUFFER_SIZE];
    uint8_t i = 0;

    uint16_t wave_value = 0;

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

    buffer[BUFFER_SIZE - 1] = 0;

    wave_value = atoi(buffer);

    Serial.clear();

    return wave_value;
}
