#include "../controller.hpp"
#include "../modules/SensorModule/sensor.hpp"


class TestModule: public Module{
  public:
  Message* m;

  TestModule(){
    m = NULL;
  }

  bool receive(Message* message){
    m = message;
    return 1;
  }

  Message* read(){return m;}
};

// class TestSensor: public Sensor{
//   std::string read(){return "TestReading";}
// };

void test_task(){
  sleep(1);
  exit(0);
}
