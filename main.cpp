#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h"
#include "controller.hpp"
#include "modules/CameraModule/CameraModule.hpp"

int main(void){
	Controller controller;
	CameraModule mod;
	control.addModule(&mod);
	mod.takePhoto();
	sleep(10);

  // C
  return 0;
}
