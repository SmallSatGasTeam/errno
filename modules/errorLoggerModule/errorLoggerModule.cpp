#include"errorLoggerModule.hpp"

bool ErrorLoggerModule::receive(Message* message){
    if(!message){return 0;}

    unsigned int action = message->action;
    std::string body = message->body;

    switch(action){
      case ERROR:
        writeToDatabase(body);
        break;
      // default:
      //   printf("Unmatching Message Recieved By ErrorLogger\n");
    }
    return 1;
}

bool ErrorLoggerModule::status(){
  return 1; //TODO This needs to do appropriate checks
}

bool ErrorLoggerModule::writeToDatabase(std::string toWrite){
  printf("ErrorLoggerModule:PSEUDO write to database\n"); //TODO needs to actually write to database
  return 1;
}
