#include <gtest/gtest.h>

// Add custom main so we test independently
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}