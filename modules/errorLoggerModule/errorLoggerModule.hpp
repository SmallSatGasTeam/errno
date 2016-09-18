#ifndef ERROR_LOGGER_MODULE_H
#define ERROR_LOGGER_MODULE_H

#define I2C_PATH
#include <cstdint>
#include "../module.hpp"

class ErrorLoggerModule:public Module{
public:
  ErrorLoggerModule();
  ~ErrorLoggerModule();

  bool receive(Message* message);
  //bool addSensor(Sensor* sensor);

protected:
  // std::string readSensors();
  // void readWorker();
	// void initializeSensors();
  //
  // std::vector<Sensor*> sensors;
  // bool shouldRead;
  // const uint32_t readInterval;
  // uint32_t i2cBus;
};


#endif
