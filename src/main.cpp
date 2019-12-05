#include <Arduino.h>
#include <menu.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial.available())
    ;
}

void loop()
{

  print_main_menu();

  char selection;

  char menu_select = read_option_main_menu();

  if (menu_select == 'S')
  {
    do
    {

      print_selection_menu();

      selection = read_selection_menu();

      if (selection == 'F')
      {
        //CALL FUNCTION TO SET FREQUENCY
        Serial.printf(" Please write your desired frequency (%d - %d): \n", MIN_FREQUENCY, MAX_FREQUENCY);

        uint16_t frequency_value = set_frequency();

        if (frequency_value < MIN_FREQUENCY)
        {
          frequency_value = MIN_FREQUENCY;
        }
        else if (frequency_value > MAX_FREQUENCY)
        {
          frequency_value = MAX_FREQUENCY;
        }
      }
      else if (selection == 'M')
      {
        //CALL FUNCTION TO SET MAGNITUDE
      }
      else if (selection == 'I')
      {
        //CALL FUNCTION TO SHOW INFORMATION ABOUT SET FREQUENCY AND MAGNITUDE
      }
    } while (selection != 'B');
  }

  else if (menu_select == 'T')
  {
    print_selection_menu();

    selection = read_selection_menu();

    if (selection == 'F')
    {
      //CALL FUNCTION TO SET FREQUENCY
      Serial.printf(" Please write your desired frequency (%d - %d): \n", MIN_FREQUENCY, MAX_FREQUENCY);

      uint16_t frequency_value = set_frequency();

      if (frequency_value < MIN_FREQUENCY)
      {
        frequency_value = MIN_FREQUENCY;
      }
      else if (frequency_value > MAX_FREQUENCY)
      {
        frequency_value = MAX_FREQUENCY;
      }
    }
    else if (selection == 'M')
    {
      //CALL FUNCTION TO SET MAGNITUDE
    }
    else if (selection == 'I')
    {
      //CALL FUNCTION TO SHOW INFORMATION ABOUT SET FREQUENCY AND MAGNITUDE
    }
  }
}