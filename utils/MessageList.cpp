#include "MessageList.hpp"

void MessageList::addMessage(Message* message){
  if(!head){
    head = message;
    tail = head;
  }

  tail->next = message;
  tail = message;
}

Message* MessageList::readMessages(){
  Message* temp = head;
  head = NULL;
  tail = NULL;
  return temp;
}
