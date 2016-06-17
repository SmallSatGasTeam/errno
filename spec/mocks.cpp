#include "../controller.hpp"

class TestController: public Controller{
public:
  bool broadcast(Message* message){
    m.push_back(message);
    return 1;
  }

  std::vector<Message*> m;
};


class TestModule: public Module{
  public:
  TestModule(Controller* control): Module(control){}
  std::vector<Message*> m;

  bool receive(Message* message){
    m.push_back(message);
    return 0;
  }

};
