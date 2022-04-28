#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <geometry.h>
}

TEST(GeometryModuleTest, IsRectangleTest1) {
    using namespace std;
    char *fileName = (char*) "4_points.txt";
    matrix_int* fourPointsPtr = importIntMatrix(fileName);
    ASSERT_TRUE(isRectangle(*fourPointsPtr));
}