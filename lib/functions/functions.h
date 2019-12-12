#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define TIME_UNIT 0.001f
#define DAC_RESOLUTION 12
#define REFERENCE_VOLTAGE 3.3f
#define VOLTAGE_RESOLUTION (REFERENCE_VOLTAGE / (1 << DAC_RESOLUTION))

void generateVoltage();

#endif