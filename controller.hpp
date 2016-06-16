#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "constants.h"
#include "module.hpp"

/**
 * Forward declaration of Module so we can use it in this class
 */
class Module;


/**
 * Controller will handle communcations between modules, broadcast its own
 * messages when necessary, and generally handle the things
 */
class Controller{
public:
  // Controller(); TODO things? maybe?
  bool broadcast(Message* message);
  bool addModule(Module* module);
private:

  std::vector<Module*> modules;
  std::vector<Message*> messages;
};
#endif
