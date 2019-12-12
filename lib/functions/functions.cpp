#include <Arduino.h>
#include <menu.h>
#include <math.h>
#include "functions.h"

extern char waveform;
extern uint8_t frequency_value;

static float sineWave(float time)
{
    float radian = 2 * PI * frequency_value * time;
    return 0.5 * REFERENCE_VOLTAGE * (sin(radian) + 1);
}

static float triangleWave(float time)
{
    float radian = 2 * PI * frequency_value * time;
    return 0.5 * REFERENCE_VOLTAGE * (2 * asin(sin(radian)) / PI + 1);
}

void generateVoltage()
{
    float time = millis() * TIME_UNIT;
    float voltage = (waveform == SINE_WAVEFORM) ? sineWave(time) : triangleWave(time);
    analogWriteDAC0((uint16_t)(voltage / VOLTAGE_RESOLUTION));
}