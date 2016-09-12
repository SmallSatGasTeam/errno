#ifndef I2C_SENSOR
#define I2C_SENSOR


#include <stdio.h>
#include <cstdint>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

class I2CSensor {
	public:
	I2CSensor(int i2cBus, int address):i2cBus(i2cBus), address(address){
 		ioctl(this->i2cBus, I2C_SLAVE, this->address);
	}

	int read_i2c(void* buff, unsigned int buffSize){
		return read(this->i2cBus, buff, buffSize);
	}

	int write_i2c(void* buff, unsigned int buffSize){
		return write((int)this->i2cBus, buff, (int)buffSize);
	}
	
protected:
	int i2cBus;
	int address;
};

#endif
