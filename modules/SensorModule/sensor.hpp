#ifndef SENSOR_H
#define SENSOR_H
#include <string>
class Sensor {
public:
	virtual std::string readSensor() = 0;
protected: 
	
};
#endif
