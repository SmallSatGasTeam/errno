#ifndef MODULE_H
#define MODULE_H

#include <mutex>

#include "../actions.h"
#include "../constants.h"
#include "../controller.hpp"
#include "../utils/MessageList.hpp"


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

  /**
   * Receive should be implemented by every module that is a child class of
   * Module. If message needs to be used asynchronously it should be copied
   * as there is no guarantee that message will exist after the function
   * exits. Recieve will be called with all messages that are passed to
   * controller. If your module needs to take a special action when it recieves
   * a certain message, it should decide to do that in receive.
   *
   * @param  message - Message that has been passed from another module
   * @return - True if successful, false otherwise
   */
  virtual bool receive(Message* message);

  /**
   * Should be implemented by child classes of Module to test whether a Module
   * is functional or not
   *
   * @return - True if module is correctly functioning, false otherwise.
   */
  virtual bool status();


  virtual Message* read();

  /**
   * Pass a long running task off to another thread, and add done message to
   * message queue when long running task is completed. This should be done
   * on any task that could potentially block other time sensitive messages
   * from being passed.
   *
   * @param  task - function containing work to be done
   */
  void runTask(void (*task)(), Message* done);
protected:

  /**
   * Adds a message to interal message queue to be read by controller on next
   * iteration of the event loop.
   *
   * @param  message to be added to queue
   * @return True if successful, false otherwise
   */
  bool broadcast(Message* message);

  /**
   * Function to run task internally. This is utilized by the implementation of
   * runTask
   *
   * @param task Function pointer to task to be run
   * @param done Message to be passed when task is done
   */
  void taskRunner(void (*task)(), Message* done);

  MessageList messages;
  std::mutex mtx;
};

#endif
