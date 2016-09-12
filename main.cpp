#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "controller.hpp"

#include "modules/SensorModule/SensorModule.hpp"
#include "modules/SensorModule/TempSensor/TempSensor.hpp"

int main(void){
	// Create controller
	Controller controller;

	// Create modules
	SensorModule sensors;

  std::cout << "bus: " << sensors.i2cBus << std::endl;
  // Create sensors
	 TempSensor temp_sensor(sensors.i2cBus, 0x18);
   std::cout << temp_sensor.read(sensors.i2cBus) << std::endl;

	// Add sensors
	 //sensors.addSensor(&temp_sensor);

	// Add modules
   controller.addModule(&sensors);

//   while(true){
//   	 controller.readModules();
//   }
  return 0;
}
