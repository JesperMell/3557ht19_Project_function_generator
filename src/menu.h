#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <stdint.h>


#define BUFFER_SIZE 3
#define WAVEFORM_OPTION 'W'
#define FREQUENCY_OPTION 'F'
#define MAGNITUDE_OPTION 'M'
#define INFORMATION_OPTION 'I'
#define SINE_WAVEFORM 'S'
#define TRIANGLE_WAVEFORM 'T'
#define MIN_MAGNITUDE 1
#define MAX_MAGNITUDE 10
#define MIN_FREQUENCY 1
#define MAX_FREQUENCY 10


void print_menu();

char waveform_option();

char read_selection_menu();

uint16_t set_wave_values();

#endif