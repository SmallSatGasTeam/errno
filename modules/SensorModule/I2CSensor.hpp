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
	
	int read_i2c(void* buff, unsigned int buffSize){
		return read(this->i2cBus, buff, buffSize);
	}

	int write_i2c(void* buff, unsigned int buffSize){
		return write((int)this->i2cBus, buff, (int)buffSize);
	}
	
	int i2cBus;
	int address;
};

#endif
