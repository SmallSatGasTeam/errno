#include "../module.hpp"
#include "../Sensor.hpp"

class SensorModule:public Module{
public:
  bool receive(Message* message);

protected:
  bool readSensors();
  std::vector<Sensor*> sensors;
};
