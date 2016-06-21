// #include <iostream>
//
// #include "controller.hpp"
// #include "modules/module.hpp"
//
// int main(void){
//
//   std::cout << "howdy\n";
//
//   return 0;
// }

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <thread>

// #include "controller.hpp"
// #include "modules/module.hpp"

void do_thing(/*lambda, doneMessage*/){
  sleep(2);
  std::cout << "howdy\n";
  int pid = fork();
  if(!pid){
    sleep(3);
    execlp("ls", ".", 0);
  }
  // execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
  else{
    waitpid(pid, 0, 0);
    std::cout << "Done Yo\n";
  }
}

int main(void){
  std::thread t1 (do_thing);
  t1.detach();
  std::cout << "Done main\n";
  sleep(7);
  return 0;
}
