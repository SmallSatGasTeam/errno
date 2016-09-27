#ifndef ERROR_LOGGER_MODULE_HPP
#define ERROR_LOGGER_MODULE_HPP

#include<sqlite3.h>
#include<string>
#include "../module.hpp"

class ErrorLoggerModule:public Module{
public:

  bool receive(Message* message);
  bool status();

protected:
  bool writeToDatabase(std::string);
  static int callback(void *, int, char **, char **);

};


#endif
