#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "controller.hpp"
#include "modules/CameraModule/CameraModule.hpp"

int main(void){
	// Controller controller;
	// CameraModule mod;
	// controller.addModule(&mod);
	// mod.takePhoto();
	// sleep(10);
	
	// Create controller
	Controller controller;

	// Create modules
  CameraModule camera;
	SensorModule sensors;

	// Create sensors
	TempSensor temp_sensor;


	// Add sensors
	sensors.addSensor(&temp_sensor);

	// Add modules
  controller.addModule(&camera);

  while(true){
    controller.readModules();
		std::cout << "Howdy\n";
  }
  return 0;
}
