#ifndef TEMP_SENSOR
#define TEMP_SENSOR
#include<sstream>
#include <string>
#include "../I2CSensor.hpp"

class TempSensor: public I2CSensor{
	public: 
	TempSensor(int bus, int address):I2CSensor(bus, address){}
 
 	std::string read(int bus){
		char reg[1] = {0x05};
		write_i2c(reg, 1);
		char data[2] = {0};
		if(read_i2c(data, 2) != 2)
		{
			return "";
		}
		// Convert the data to 13-bits
		int temp = ((data[0] & 0x1F) * 256 + data[1]);
		if(temp > 4095)
		{
			temp -= 8192;
		}
		float cTemp = temp * 0.0625;
		float fTemp = cTemp * 1.8 + 32;
		
		// Convert float to string
		std::stringstream ss;
		ss << cTemp;
		return ss.str();
	}
};
#endif 


