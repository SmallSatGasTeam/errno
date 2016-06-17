#include <gtest/gtest.h>

#include "../modules/module.cpp"
#include "../controller.cpp"
#include "module.cpp"
#include "controller.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
