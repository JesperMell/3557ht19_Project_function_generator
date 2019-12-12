#include "voltage_util.h"

#define DAC_RESOLUTION 10  // Digital to analog resolution. 
#define SUPPLIED_VOLTAGE 3.3f
#define VOLTAGE_RESOLUTION (SUPPLIED_VOLTAGE / (1 << DAC_RESOLUTION))


void setup()
{
    Serial.begin(9600);
    analogWriteRes(DAC_RESOLUTION);
    timer.begin(generateVoltage,1000);
}

void generateVoltage()
{
float voltage = (waveform == SINE_WAVEFORM) ? sine_form() : triangle_form();
analogWriteDAC0(int(voltage / VOLTAGE_RESOLUTION));
}