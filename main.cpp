#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "controller.hpp"
// #include "modules/CameraModule/CameraModule.hpp"
// #include "modules/SensorModule/SensorModule.hpp"
// #include "modules/SensorModule/TempSensor/TempSensor.hpp"

int main(void){
	// Create controller
	Controller controller;

	// Create modules
	// SensorModule sensors;

	// Create sensors
	// TempSensor temp_sensor;


	// Add sensors
	// sensors.addSensor(&temp_sensor);

	// Add modules
  // controller.addModule(&camera);

   while(true){
   		controller.readModules();
   }
  return 0;
}
