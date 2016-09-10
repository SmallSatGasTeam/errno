#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include<cstdint>

class Sensor {
public:
	virtual std::string read() = 0;
};
#endif
