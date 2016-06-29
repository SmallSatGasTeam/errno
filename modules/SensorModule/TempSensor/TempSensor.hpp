#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "../sensor.hpp"

class TempSensor:public Sensor{
public:
	std::string read();

private:
	uint16_t swapWord(uint16_t value);
	float getTempValue();

};

#endif
