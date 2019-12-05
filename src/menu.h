#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <stdint.h>

#define MIN_FREQUENCY 1
#define MAX_FREQUENCY 100

void print_main_menu();

void print_selection_menu();

char read_option_main_menu();

char read_selection_menu();

uint16_t set_frequency();

#endif