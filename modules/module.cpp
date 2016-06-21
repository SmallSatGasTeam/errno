#include "module.hpp"

std::mutex Module::mtx;

Module::Module(){}

bool Module::receive(Message* message){
    if(!message){return 0;}

    unsigned int action = message->action;
    std::string body = message->body;

    switch(action){
      case EXAMPLE_ACTION:
        std::cout << "Example Action Received\n";
      break;

      default:
        std::cout << "Unmatching Message Recieved\n";
    }
    return 1;
}

bool Module::broadcast(Message* message){
  if(!message){return 0;}
  messages.push_back(message);
  return 1;
}

bool Module::status(){
  return 0;
}

void Module::taskRunner(void (*task)(), Message* done){
  int pid = fork();
  int status;
  if(!pid){
    task();
  }
  else{
    waitpid(pid, &status, 0);
    Module::mtx.lock();
    messages.push_back(done);
    Module::mtx.unlock();
  }
}

void Module::runTask(void (*task)(), Message* done){
  std::thread worker([this, task, done] { taskRunner(task, done); });
  worker.detach();
}

std::vector<Message*> Module::read(){
  // Lock down reading from messages vector in case
  // another thread is also trying to use it. 
  mtx.lock();
  std::vector<Message*> temp = messages;
  mtx.unlock();
  messages.erase(messages.begin(), messages.end());
  return temp;
}
