#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <geometry.h>
}

std::string getFullPath(const std::string &fileName) {
    return "resources/geometric_test_data/" + fileName;
}

TEST(GeometryModuleTest, IsRectangleTest1) {
    using namespace std;
    string fileName = getFullPath("is_rectangle_test_1.txt");
    matrix_int *fourPointsPtr = importIntMatrix(fileName.c_str());
    ASSERT_TRUE(isRectangle(*fourPointsPtr));
}

TEST(GeometryModuleTest, IsRectangleTest2) {
    using namespace std;
    string fileName = getFullPath("is_rectangle_test_2.txt");
    matrix_int *fourPointsPtr = importIntMatrix(fileName.c_str());
    ASSERT_TRUE(isRectangle(*fourPointsPtr));
}

TEST(GeometryModuleTest, IsRectangleTest3) {
    using namespace std;
    string fileName = getFullPath("is_rectangle_test_3.txt");
    matrix_int *fourPointsPtr = importIntMatrix(fileName.c_str());
    ASSERT_TRUE(isRectangle(*fourPointsPtr));
}

TEST(GeometryModuleTest, CountTrianglesTest1) {
    using namespace std;
    string fileName = getFullPath("count_triangle_test_1.txt");
    matrix_int *coordinates = importIntMatrix(fileName.c_str());
    ASSERT_EQ(countTriangles(coordinates->arr[0], coordinates->arr[1]), 4);
}

TEST(GeometryModuleTest, CountTrianglesTest2) {
    using namespace std;
    string fileName = getFullPath("count_triangle_test_2.txt");
    matrix_int *coordinates = importIntMatrix(fileName.c_str());
    ASSERT_EQ(countTriangles(coordinates->arr[0], coordinates->arr[1]), 0);
}

TEST(GeometryModuleTest, CountTrianglesTest3) {
    using namespace std;
    string fileName = getFullPath("count_triangle_test_3.txt");
    matrix_int *coordinates = importIntMatrix(fileName.c_str());
    ASSERT_EQ(countTriangles(coordinates->arr[0], coordinates->arr[1]), 0);
}