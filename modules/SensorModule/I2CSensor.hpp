#ifndef I2C_SENSOR
#define I2C_SENSOR


#include <stdio.h>
#include <cstdint>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "sensor.hpp"

class I2CSensor:public Sensor{
	public:
	I2CSensor(int i2cBus, int address):Sensor(), i2cBus(i2cBus), address(address){
 		ioctl(this->i2cBus, I2C_SLAVE, this->address);
	}

	virtual std::string readSensor() = 0;
protected:

	  void read_i2c(int reg, uint8_t* buff, const unsigned int size){

 	  char config[1];
	  config[0] = reg;	
		
		if(_write_i2c(config, 1) != 1){
		  printf("Failed to write to i2c device\n");
		}

		if(_read_i2c(buff, size) != size){
		  //TODO Log errors
			printf("Failed to read from i2c device\n");
		}
	}
	
	int _read_i2c(void* buff, unsigned int buffSize){
		return read(this->i2cBus, buff, buffSize);
	}

	int _write_i2c(void* buff, unsigned int buffSize){
		return write((int)this->i2cBus, buff, (int)buffSize);
	}
	
	int i2cBus;
	int address;
};

#endif
