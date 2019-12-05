#include<functions.h>
#include<Math.h>

extern char waveform;
extern uint8_t frequency_value;

static float sineWave()
{
  float radian = 2 * PI * frequency * millis() * 0.001;
  return 0.5 * SUPPLIED_VOLTAGE * (sin(radian) + 1);
}
