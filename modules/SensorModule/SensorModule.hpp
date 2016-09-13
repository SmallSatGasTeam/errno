
#ifndef SENSOR_MODULE_H
#define SENSOR_MODULE_H

#define I2C_PATH
#include <cstdint>
#include "../module.hpp"
#include "sensor.hpp"

class SensorModule:public Module{
public:
  SensorModule();
  ~SensorModule();

  bool receive(Message* message);
  bool addSensor(Sensor* sensor);

protected:
  std::string readSensors();
  void readWorker();
	void initializeSensors();

  std::vector<Sensor*> sensors;
  bool shouldRead;
  const uint32_t readInterval;
  uint32_t i2cBus;
};


#endif
