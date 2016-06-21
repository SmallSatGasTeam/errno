#include "../module.hpp"

class CameraModule:public Module{
public:
  CameraModule(Controller* control);
  bool receive(Message* message);
private:
  bool takePhoto();
};
