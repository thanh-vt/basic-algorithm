#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <sorting_test.h>
}

namespace SortingModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/sorting_test_data/" + fileName;
    }
}

TEST(SortingModuleTest, SortByHeightTest1) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_height_test_1.txt");
    arr_int *data = importIntArr(fileName.c_str());
    sortByHeight(*data);
    ASSERT_EQ(data->arr[0], -1);
    ASSERT_EQ(data->arr[1], 150);
    ASSERT_EQ(data->arr[2], 160);
    ASSERT_EQ(data->arr[3], 170);
    ASSERT_EQ(data->arr[4], -1);
    ASSERT_EQ(data->arr[5], -1);
    ASSERT_EQ(data->arr[6], 180);
    ASSERT_EQ(data->arr[7], 190);
    freeIntArr(data);
}

TEST(SortingModuleTest, SortByHeightTest2) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_height_test_2.txt");
    arr_int *data = importIntArr(fileName.c_str());
    sortByHeight(*data);
    ASSERT_EQ(data->arr[0], -1);
    ASSERT_EQ(data->arr[1], -1);
    ASSERT_EQ(data->arr[2], -1);
    ASSERT_EQ(data->arr[3], -1);
    ASSERT_EQ(data->arr[4], -1);
    freeIntArr(data);
}

TEST(SortingModuleTest, SortByHeightTest3) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_height_test_3.txt");
    arr_int *data = importIntArr(fileName.c_str());
    sortByHeight(*data);
    ASSERT_EQ(data->arr[0], -1);
    ASSERT_EQ(data->arr[1], 2);
    freeIntArr(data);
}

TEST(SortingModuleTest, SortByHeightTest4) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_height_test_4.txt");
    arr_int *data = importIntArr(fileName.c_str());
    printIntArr(data);
    sortByHeight(*data);
    printIntArr(data);
    ASSERT_EQ(1, 1);
    freeIntArr(data);
}
