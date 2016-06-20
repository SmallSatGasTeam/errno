#include "module.hpp"

Module::Module(Controller* control):controller(control){}

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
  if(!controller || !message){return 0;}

  controller->broadcast(message);
  return 1;
}

bool Module::status(){
  if(controller){return 1;}
  return 0;
}

bool task(void (*task)(), Message* done){
  std::thread worker (taskRunner);
  worker.detach();
}
