#ifndef SENSOR_H
#define SENSOR_H
#include <string>

/*
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
*/
/*
oid main() 

 // Create I2C bus
 int file;
 char *bus = "/dev/i2c-1";
 if ((file = open(bus, O_RDWR)) < 0) 
 {
 	printf("Failed to open the bus. \n");
 	exit(1);
 }
 // Get I2C device, MCP9808 I2C address is 0x18(24)
 ioctl(file, I2C_SLAVE, 0x18);
*/

/*
class I2CSensor {
};
*/

class Sensor{
public:
	virtual std::string read() = 0;
  
};

#endif
