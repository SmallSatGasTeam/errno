#ifndef ERROR_LOGGER_MODULE_H
#define ERROR_LOGGER_MODULE_H

#include "../module.hpp"

class ErrorLoggerModule:public Module{
public:

  bool receive(Message* message);
  bool status();

protected:
  bool writeToDatabase(std::string);
};


#endif
