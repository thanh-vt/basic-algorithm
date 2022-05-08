#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <sorting.h>
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

//TEST(SortingModuleTest, SortByHeightTest4) {
//    using namespace std;
//    string fileName = SortingModuleTest::getFullPath("sort_by_height_test_4.txt");
//    arr_int *data = importIntArr(fileName.c_str());
//    printIntArr(data);
//    printf("\n");
//    sortByHeight(*data);
//    printIntArr(data);
//    ASSERT_EQ(1, 1);
//    freeIntArr(data);
//}

TEST(SortingModuleTest, SortByLengthTest1) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_length_test_1.txt");
    arr_string *data = importStringArr(fileName.c_str());
    sortByLength(*data);
    ASSERT_FALSE(strcmp(data->arr[0], ""));
    ASSERT_FALSE(strcmp(data->arr[1], "a"));
    ASSERT_FALSE(strcmp(data->arr[2], "zz"));
    ASSERT_FALSE(strcmp(data->arr[3], "abc"));
    ASSERT_FALSE(strcmp(data->arr[4], "aaa"));
    freeStringArr(data);
}

TEST(SortingModuleTest, SortByLengthTest2) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_length_test_2.txt");
    arr_string *data = importStringArr(fileName.c_str());
    sortByLength(*data);
    ASSERT_FALSE(strcmp(data->arr[0], ""));
    ASSERT_FALSE(strcmp(data->arr[1], "zz"));
    ASSERT_FALSE(strcmp(data->arr[2], "bb"));
    ASSERT_FALSE(strcmp(data->arr[3], "cc"));
    ASSERT_FALSE(strcmp(data->arr[4], "ccc"));
    freeStringArr(data);
}

TEST(SortingModuleTest, SortByLengthTest3) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("sort_by_length_test_3.txt");
    arr_string *data = importStringArr(fileName.c_str());
    sortByLength(*data);
    ASSERT_FALSE(strcmp(data->arr[0], "e"));
    ASSERT_FALSE(strcmp(data->arr[1], "abc"));
    ASSERT_FALSE(strcmp(data->arr[2], "abcd"));
    freeStringArr(data);
}


TEST(SortingModuleTest, AreSimilarTest1) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("are_similar_test_1.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_TRUE(areSimilar(data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(SortingModuleTest, AreSimilarTest2) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("are_similar_test_2.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_TRUE(areSimilar(data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(SortingModuleTest, AreSimilarTest3) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("are_similar_test_3.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(areSimilar(data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(SortingModuleTest, AreSimilarTest4) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("are_similar_test_4.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(areSimilar(data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(SortingModuleTest, DigitalSumSortTest1) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("digital_sum_sort_test_1.txt");
    arr_int *data = importIntArr(fileName.c_str());
    printIntArr(data);
    digitalSumSort(*data);
    printIntArr(data);
    ASSERT_EQ(data->arr[0], 20);
    ASSERT_EQ(data->arr[1], 4);
    ASSERT_EQ(data->arr[2], 13);
    ASSERT_EQ(data->arr[3], 7);
    freeIntArr(data);
}

TEST(SortingModuleTest, DigitalSumSortTest2) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("digital_sum_sort_test_2.txt");
    arr_int *data = importIntArr(fileName.c_str());
    digitalSumSort(*data);
    ASSERT_EQ(data->arr[0], 100);
    ASSERT_EQ(data->arr[1], 11);
    ASSERT_EQ(data->arr[2], 4);
    ASSERT_EQ(data->arr[3], 22);
    ASSERT_EQ(data->arr[4], 31);
    ASSERT_EQ(data->arr[5], 103);
    freeIntArr(data);
}

TEST(SortingModuleTest, DigitalSumSortTest3) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("digital_sum_sort_test_3.txt");
    arr_int *data = importIntArr(fileName.c_str());
    digitalSumSort(*data);
    ASSERT_EQ(data->arr[0], 13);
    ASSERT_EQ(data->arr[1], 22);
    ASSERT_EQ(data->arr[2], 400);
    ASSERT_EQ(data->arr[3], 8);
    ASSERT_EQ(data->arr[4], 404);
    ASSERT_EQ(data->arr[5], 701);
    freeIntArr(data);
}

TEST(SortingModuleTest, DigitalSumSortTest4) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("digital_sum_sort_test_4.txt");
    arr_int *data = importIntArr(fileName.c_str());
    digitalSumSort(*data);
    ASSERT_EQ(data->arr[0], 20);
    ASSERT_EQ(data->arr[1], 21);
    ASSERT_EQ(data->arr[2], 21);
    ASSERT_EQ(data->arr[3], 31);
    ASSERT_EQ(data->arr[4], 23);
    ASSERT_EQ(data->arr[5], 33);
    ASSERT_EQ(data->arr[6], 25);
    ASSERT_EQ(data->arr[7], 17);
    ASSERT_EQ(data->arr[8], 17);
    ASSERT_EQ(data->arr[9], 26);
    ASSERT_EQ(data->arr[10], 26);
    ASSERT_EQ(data->arr[11], 44);
    ASSERT_EQ(data->arr[12], 18);
    ASSERT_EQ(data->arr[13], 19);
    ASSERT_EQ(data->arr[14], 39);
    freeIntArr(data);
}
