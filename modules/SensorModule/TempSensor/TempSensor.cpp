#include<stdio.h>
#include<stdlib.h>
#include<wiringPiI2C.h>
#include<stdint.h>
#include<wiringPi.h>


uint16_t TempSensor::swapWord(uint16_t value) {
	uint16_t res = value;
	return ((res & 0xFF) <<8) | ((res>>8) & 0xFF);
}

float TempSensor::getTempValue(){

	int fd = wiringPiI2CSetup(0x18);
	uint16_t value = wiringPiI2CReadReg16(fd,0x05);

	value = ((res & 0xFF) <<8) | ((res>>8) & 0xFF);

	printf("temp: %x \n", value);
	bool neg = (value & 0x1000);
	float res = (value & 0xFFF) / 16.0;
	if (neg) res = 0-(256-res);
	return res;
}

float TempSensor::read(){return getTempValue();}
