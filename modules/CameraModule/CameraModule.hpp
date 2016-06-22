#include "../module.hpp"

class CameraModule:public Module{
public:
  CameraModule();
  bool receive(Message* message);
//private:
  bool takePhoto();
};
