#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "controller.hpp"

#include "modules/SensorModule/SensorModule.hpp"
//#include "modules/SensorModule/TempSensor/TempSensor.hpp"

int main(void){
	// Create controller
	Controller controller;

	// Create modules
	SensorModule sensors;
 
	// Add modules
   controller.addModule(&sensors);

   while(true){
   	 controller.readModules();
   }
  return 0;
}
