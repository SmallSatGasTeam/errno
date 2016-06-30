#include "constants.h"
#include "controller.hpp"


bool Controller::broadcast(Message* message){
  if(!message){return 0;} //If message is null, forget about it
  for(int i = 0; i < modules.size(); i++){
    modules[i]->receive(message);
  }
  return 1;
}

 bool Controller::addModule(Module* module){
   if(!module){return 0;}
   modules.push_back(module);
   return 1;
}

bool Controller::readModules(){
  for(int i = 0; i < modules.size(); i++){
    Message* temp = modules[i]->read();
    for(int j = 0; j < temp.size(); j++){this->broadcast(temp[j]);}
    messages.addMessage(temp);
  }
  return 1;
}

Message* Controller::getMessages(){
  return messages.readMessages();
}
