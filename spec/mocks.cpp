#include "../controller.hpp"
#include "../modules/SensorModule/sensor.hpp"

class TestController: public Controller{
public:
  bool broadcast(Message* message){
    m.push_back(message);
    std::cout << m.size() << "\n";
    return 1;
  }

  std::vector<Message*> m;
};


class TestModule: public Module{
  public:
  Message* m;

  TestModule(){
    m = NULL;
  }

  bool receive(Message* message){
    return 1;
  }

  Message* read(){return m;}
};

class TestSensor: public Sensor{
  std::string read(){return "TestReading";}
};

void test_task(){
  sleep(1);
  exit(0);
}
