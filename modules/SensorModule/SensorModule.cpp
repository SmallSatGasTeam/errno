#include "SensorModule.hpp"

SensorModule::SensorModule():shouldRead(true), readInterval(5){
  if ((this->i2cBus = open(I2C_PATH, O_RDWR)) < 0)
  {
   printf("Failed to open the bus. \n");
   exit(1);
  }

  std::thread reader([this]{this->readWorker();});
  reader.detach();
};

SensorModule::~SensorModule(){
  this->i2cBus.close()
}

bool SensorModule::addSensor(Sensor* sensor){
  if(!sensor){return 0;}
  sensors.push_back(sensor);
  return 1;
}

bool SensorModule::receive(Message* message){
    if(!message){return 0;}
    unsigned int action = message->action;
    std::string body = message->body;
    return 1;
}

std::string SensorModule::readSensors(){
  std::string message = "";
  for(int i = 0; i < sensors.size(); i++){
    message += (sensors[i]->read() + ',');
  }
  return message;
}

void SensorModule::readWorker(){
  while(shouldRead){
    std::string data = readSensors();
    Message* message = new Message(PHONE_HOME, data);
    broadcast(message);
    sleep(readInterval);
  }
}
