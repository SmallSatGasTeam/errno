#include <gtest/gtest.h>


// Import Mocks
// #include "mocks.cpp"

// Import Source
#include "../controller.cpp"
// #include "../modules/module.cpp"
// #include "../modules/CameraModule/CameraModule.cpp"
// #include "../modules/SensorModule/SensorModule.cpp"
#include "../utils/MessageList.cpp"

// Import Tests
#include "controller.cpp"
// #include "module.cpp"
// #include "modules/CameraModule/CameraModule.cpp"
// #include "modules/SensorModule/SensorModule.cpp"
#include "utils/MessageList.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
