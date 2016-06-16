#ifndef CONSTANTS_H
#define CONSTANTS_H

struct Message {
  unsigned int action;
  std::string body;

  Message(int action, std::string body):action(action), body(body){}
};

#endif
