#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Sensor.h"

class TempSensor:public Sensor{
public:
	float read();

private:
	uint16_t swapWord(uint16_t value);
	float getTempValue();

};

#endif
