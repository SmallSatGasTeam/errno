#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <vector>

#include "module.hpp"

bool Module::receive(Message* message){
    if(!message){return 0;}

    unsigned int action = message->action;
    std::string body = message->body;

    switch(action){
      case EXAMPLE_ACTION:
        // NOTE commented out so we don't have to include iostream just for an example
        // std::cout << "Example Action Received\n";
      break;

      default:
        // std::cout << "Unmatching Message Recieved\n";
    }
    return 1;
}

bool Module::broadcast(Message* message){
  if(!message){return 0;}
  Module::mtx.lock();
  messages.addMessage(message);
  Module::mtx.unlock();
  return 1;
}

bool Module::status(){
  return 0;
}

void Module::taskRunner(void (*task)(), Message* done){
  task();
  broadcast(done);
}

void Module::runTask(void (*task)(), Message* done){
  std::thread worker([this, task, done] { taskRunner(task, done); });
  worker.detach();
}

Message* Module::read(){
  // Lock down reading from messages vector in case
  // another thread is also trying to use it.
  mtx.lock();
  Message* temp = messages.readMessages();
  mtx.unlock();
  return temp;
}
