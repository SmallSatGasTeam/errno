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

	Controller controller;
  CameraModule camera;

  controller.addModule(&camera);

  while(true){
    controller.readModules();
  }
  return 0;
}
