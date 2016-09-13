#ifndef TEMP_SENSOR
#define TEMP_SENSOR
#include<sstream>
#include <string>
#include <cstdint>
#include "../I2CSensor.hpp"

class TempSensor: public I2CSensor{
	public: 
	TempSensor(int bus, int address):I2CSensor(bus, address){}
 
	float convertTemp(const uint8_t data[2]){
	  int temp =  ((data[0] & 0x1F) * 256 + data[1]);
		if(temp > 4095)
		{
			temp -= 8192;
		}
		float cTemp = temp * 0.0625;
		return cTemp;
	}

 	std::string readSensor(){
	  uint8_t data[2];
		read_i2c(0x05, data, 2);
    
		float cTemp = convertTemp(data);
   		
		// Convert float to string
		std::stringstream ss;
		ss << cTemp;
		return ss.str();
	}
};
#endif 


