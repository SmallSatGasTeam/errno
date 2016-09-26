#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "controller.hpp"

#include "modules/SensorModule/SensorModule.hpp"
#include "modules/errorLoggerModule/errorLoggerModule.hpp"
//#include "modules/SensorModule/TempSensor/TempSensor.hpp"

int main(void){
	// Create controller
	Controller controller;

	// Create modules
	SensorModule sensors;
	ErrorLoggerModule errorLogger;

	// Add modules
   controller.addModule(&sensors);
	 controller.addModule(&errorLogger);

   while(true){
   	 controller.readModules();
   }
  return 0;
}
