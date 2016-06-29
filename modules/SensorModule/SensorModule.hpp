
#ifndef SENSOR_MODULE_H
#define SENSOR_MODULE_H

#include "../module.hpp"
#include "sensor.hpp"

class SensorModule:public Module{
public:
  SensorModule();
  bool receive(Message* message);
  bool addSensor(Sensor* sensor);

protected:
  std::string readSensors();
  void readWorker();

  std::vector<Sensor*> sensors;
  bool shouldRead;
  unsigned int readInterval;
};


#endif
