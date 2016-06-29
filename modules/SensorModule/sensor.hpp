#ifndef SENSOR_H
#define SENSOR_H
#include <string>

class Sensor{
public:
	virtual std::string read() = 0;

};

#endif
