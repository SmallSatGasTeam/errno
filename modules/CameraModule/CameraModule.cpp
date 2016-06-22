#include "CameraModule.hpp"

void capture(){
  system("raspistill -o test.jpg");
 // execlp("raspistill",NULL, "-o", (char*) 0);
}

CameraModule::CameraModule(){}

bool CameraModule::receive(Message* message){
  return 0;
}

bool CameraModule::takePhoto(){
  Message* message = new Message(PHOTO_TAKEN, "photo_path:/home/test.jpg");
  runTask(capture, message);
  return 0;
}
