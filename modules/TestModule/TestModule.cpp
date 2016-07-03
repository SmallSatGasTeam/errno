#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <thread>
#include <mutex>

#include "TestModule.hpp"

TestModule::TestModule(std::string data){
  shouldRead = true;
  readInterval = 1;
  testData = data;

  std::thread reader([this]{this->readWorker();});
  reader.detach();
}


bool TestModule::receive(Message* message){
    if(!message){return 0;}
    return 1;
}


void TestModule::readWorker(){
  while(shouldRead){
    Message* message = new Message(EXAMPLE_ACTION, testData);
    broadcast(message);
    sleep(readInterval);
  }
}
