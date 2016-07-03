#ifndef TEST_MODULE_H
#define TEST_MODULE_H

#include "../module.hpp"

class TestModule:public Module{
public:
  TestModule(std::string testData);
  bool receive(Message* message);

protected:
  void readWorker();

  unsigned int readInterval;
  bool shouldRead;
  std::string testData;
};


#endif
