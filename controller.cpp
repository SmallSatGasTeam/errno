#include "constants.h"
#include "controller.hpp"

// Controller::Controller(){}

bool Controller::broadcast(Message* message){
  if(!message){return 0;} //If message is null, forget about it

  for(int i = 0; i < modules.size(); i++){
    modules[i]->receive(message);
  }
  messages.push_back(message);
  return 1;
}

 bool Controller::addModule(Module* module){
   if(!module){return 0;}
   modules.push_back(module);
   return 1;
}

bool Controller::readModules(){
  for(int i = 0; i < modules.size(); i++){
    std::vector<Message*> temp = modules[i]->read();
    messages.insert(messages.end(), temp.begin(), temp.end());
  }
  return 1;
}
