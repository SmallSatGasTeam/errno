#include <thread>
#include <stdlib.h>
#include <chrono>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "SensorModule.hpp"
#include "TempSensor/TempSensor.hpp"
#include "SensorAddress.h"
#include "sensor.hpp"

SensorModule::SensorModule():shouldRead(true), readInterval(5){
  if ((this->i2cBus = open("/dev/i2c-1", O_RDWR)) < 0)
  {
	 //TODO log in error log
    printf("Failed to open the bus. \n");
  }
	
	initializeSensors();
  std::thread reader([this]{this->readWorker();});
  reader.detach();
};

SensorModule::~SensorModule(){
	if(this->i2cBus >=0) close(this->i2cBus);
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
    message += (sensors[i]->readSensor() + ',');
  }
  return message;
}

void SensorModule::readWorker(){
  while(shouldRead){
    std::string data = readSensors();
    Message* message = new Message(PHONE_HOME, data);
    broadcast(message);
    sleep(readInterval); //TODO find sleep solution
  }
}

void SensorModule::initializeSensors(){
  TempSensor* temp_sensor = new TempSensor(this->i2cBus, TEMP_ADDRESS);
	addSensor(temp_sensor);
}
