#g++ main.cpp -std=c++11 -lpthread controller.cpp modules/module.cpp modules/CameraModule/CameraModule.cpp

cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(
  GAS
  controller.cpp
  modules/module.cpp
  modules/CameraModule/CameraModule.cpp
  main.cpp
)

target_link_libraries(GAS  pthread)
