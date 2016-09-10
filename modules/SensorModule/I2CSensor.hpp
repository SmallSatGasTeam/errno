#ifndef I2C_SENSOR
#define I2C_SENSOR

#include <cstdint>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

class I2CSensor {
	I2CSensor(const uint32_t i2cBus, const uint16_t address){
 		ioctl(i2cBus, I2C_SLAVE, address);
	}

	void read(void* buff, uint16_t buffSize){
		std::read(this->i2cBus, buff, buffSize);
	}

	void write(void* buff, uint16_t buffSize){
		std::write(this->i2cBus, buff, buffSize);
	}

protected:
	const uint32_t i2cBus;
	const uint16_t address;
};

#endif
