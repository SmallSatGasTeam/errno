#include "SensorModule.hpp"

bool SensorModule::receive(Message* message){
    if(!message){return 0;}

    unsigned int action = message->action;
    std::string body = message->body;

    switch(action){
    }
    return 1;
}

bool SensorModule::readSensors(){
  std::string message = "";
  for(int i = 0; i < sensors.size(); i++){
    message += (sensors[i].read() + ',');
  }
  broadcast(BROADCAST, message);
}
