#include "../controller.hpp"

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
  std::vector<Message*> m;

  bool receive(Message* message){
    m.push_back(message);
    return 1;
  }

  std::vector<Message*> read(){return m;}

};

void test_task(){
  sleep(1);
  exit(0);
}
