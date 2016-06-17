#ifndef MODULE_H
#define MODULE_H

#include <string>

#include "../actions.h"
#include "../constants.h"
#include "../controller.hpp"

/**
 * Forward declaration of Controller class so we can use it in this class
 */
class Controller;

/**
 * Module class is a base class for abstracing one specific functionality
 * I.E. Reading sensors, taking photos, trasmitting data
 *
 * Usage: a subclass should be made, that will implement at least
 * the receive method. The receive message will receive all messages
 * broadcast from any other module. The receive method will decide how
 * to react to any given message, if at all.
 *
 * Example action: BOOM_DEPLOYED -> defined in actions.h
 * Example body: 'status:successful, deployTime:10'
 *
 * A Module can also broadcast a message to all other users by calling
 * broadcast(action, body) with both a action and body
 *
 */
class Module{
public:
  Module(Controller* control);
  virtual bool receive(Message* message);
private:
  bool broadcast(Message* message);

  Controller* controller;
};

#endif
