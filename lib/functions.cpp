
#include <menu.h>
#include <functions.h>
#include <math.h>

extern uint16_t frequency_value;
extern char waveform;

static float TriangleWave()
{
    float radian = 2 * PI * frequency * millis() * 0.001;
    return 0.5 * SUPPLIED_VOLTAGE * ((2 / PI) * asin(sin(radian)) + 1);
}