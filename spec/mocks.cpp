#include "../controller.hpp"
#include "../modules/SensorModule/sensor.hpp"


class TestModule: public Module{
  public:
  Message* message;
  MessageList m;

  TestModule(){
    message = new Message(1,"TestMessage");
  }

  bool receive(Message* message){
    m.addMessage(message);
    return 1;
  }

  Message* test_getBroadcastMessage(){
    return m.readMessages();
  }

  Message* read(){return message;}
};

// class TestSensor: public Sensor{
//   std::string read(){return "TestReading";}
// };

void test_task(){
  sleep(1);
  exit(0);
}
