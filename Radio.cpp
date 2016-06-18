#include "Radio.h"
#include <wiringSerial.h>

	Radio::Radio(device,baud){
		//setup wiringPi return 0 if error
		if(wiringPiSetup()<0){
			printf("Error setting up wiringPi");
			return 0;
		}
		//open serial connection with radio return 0 if error
		if((fd = serialOpen(device,baud)) < 0){
			printf("ERROR opening Radio");
			return 0;
		}
	}
	
	Radio::~Radio(){
		serialClose(fd);
	}
	//send sentance of telemetry to the radio
	void Radio::pushTx(telem){
		serialPrintf(fd,telem);
	}

