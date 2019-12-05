#include <Arduino.h>
#include <menu.h>

char waveform = TRIANGLE_WAVEFORM;
uint16_t frequency_value = MIN_FREQUENCY;
uint16_t magnitude_value = MIN_MAGNITUDE;

void setup()
{
  Serial.begin(9600);
  while (!Serial.available())
    ;
}

void loop()
{

  print_menu();

  char selection = read_selection_menu();

  if (selection == WAVEFORM_OPTION)
  {
    //CALL FUNCTION TO SET WAVEFORM
    Serial.printf("\n Waveform options\n");
    Serial.printf("%c) Sinewave\n", SINE_WAVEFORM);
    Serial.printf("%c) Triangewave\n", TRIANGLE_WAVEFORM);

    waveform = waveform_option();

    Serial.printf("\n");
  }
  else if (selection == FREQUENCY_OPTION)
  {
    //CALL FUNCTION TO SET FREQUENCY
    Serial.printf(" Please write your desired frequency (%d - %d Hz): \n", MIN_FREQUENCY, MAX_FREQUENCY);

    frequency_value = set_wave_values();

    if (frequency_value < MIN_FREQUENCY)
    {
      frequency_value = MIN_FREQUENCY;
    }
    else if (frequency_value > MAX_FREQUENCY)
    {
      frequency_value = MAX_FREQUENCY;
    }
    Serial.printf("\n\n");
  }
  else if (selection == MAGNITUDE_OPTION)
  {
    //CALL FUNCTION TO SET MAGNITUDE
    Serial.printf(" Please write your desired magnitude (%d - %d): ", MIN_MAGNITUDE, MAX_MAGNITUDE);

    magnitude_value = set_wave_values();

    if (magnitude_value < MIN_MAGNITUDE)
    {
      magnitude_value = MIN_MAGNITUDE;
    }
    else if (magnitude_value > MAX_MAGNITUDE)
    {
      magnitude_value = MAX_MAGNITUDE;
    }

    Serial.printf("\n\n");
  }

  else if (selection == INFORMATION_OPTION)
  {
    //CALL FUNCTION TO SHOW INFORMATION
    Serial.printf("Waveform: %s, Frequency: %d Hz, Magnitude: %d\n\n", (waveform == SINE_WAVEFORM) ? "Sine" : "Triangle", frequency_value, magnitude_value);
  }
}