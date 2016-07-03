#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "utils/MessageList.hpp"
#include "controller.hpp"
// #include "modules/CameraModule/CameraModule.hpp"
// #include "modules/SensorModule/SensorModule.hpp"
#include "modules/TestModule/TestModule.hpp"
// #include "modules/SensorModule/TempSensor/TempSensor.hpp"

int main(void){
	// Create controller
	Controller controller;

	// Create modules
	// CameraModule camera;
	// SensorModule sensors;
	TestModule test1("Test_1");
	TestModule test2("Test_2");

	// Create sensors
	// TempSensor temp_sensor;


	// Add sensors
	// sensors.addSensor(&temp_sensor);

	// Add modules
	// controller.addModule(&camera);
	controller.addModule(&test1);
	controller.addModule(&test2);

unsigned int i = 0;
	while(true){
		controller.readModules();

		if(i % 50000000 == 0){
			Message* m = controller.getMessages();

			int k = 0;
			// while(m != NULL){
			// 	std::cout << k++ << ":"<< m->body << "\n";
			// 	m = m->next;
			// }
			for(int j=0; m; m = m->next, j++){
				std::cout << j << ":"<< m->body << "\n";
			}

			std::cout << "\n\n";
		}
		i++;
	}
  return 0;
}
