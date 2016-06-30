#ifndef MESSAGE_LIST_H
#define MESSAGE_LIST_H

#include "../constants.h"

class MessageList{
public:
  MessageList():head(NULL), tail(NULL){};
  void addMessage(Message* message);

  /**
   * Returns reference to head message, and sets head to NULL
   * @return Pointer to first message
   */
  Message* readMessages();


private:
  Message* head;
  Message* tail;
};

#endif
