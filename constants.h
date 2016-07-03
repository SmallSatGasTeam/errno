#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

struct Message {
  unsigned int action;
  std::string body;
  Message* next;

  Message(int action, std::string body):
    action(action), body(body), next(NULL){}
};

#endif
