#include <thread>
#include <unistd.h>

#include "CameraModule.hpp"

CameraModule::CameraModule(Controller* control):Module(control){}

bool CameraModule::receive(Message* message){}

bool CameraModule::takePhoto(){
  // runTask([this, task, done] { taskRunner(task, done);})


  int pid = fork();

  // Child process
  if(pid == 0){
    // We can safely execute other programs here

  }else{
    waitpid(pid); // Wait until child process finishes
    execlp('ras')
  }
  // if(!pid) execlp("ls", ".", 0);
  // // execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
  // else{
  //   wait(&pid);
  //   std::cout << "Done Yo\n";
  // }
}
