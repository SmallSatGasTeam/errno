#include <string>
#include <iostream>
#include "actions.h"
#include "constants.h" 
#include "controller.hpp"
#include "modules/CameraModule/CameraModule.hpp"
 
int main(void){
  	Controller control; 
	CameraModule mod;
	control.addModule(&mod);
	mod.takePhoto();
	sleep(10);	
return 0;
}
