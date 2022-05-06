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

TEST(SortingModuleTest, AreSimilarTest5) {
    using namespace std;
    string fileName = SortingModuleTest::getFullPath("are_similar_test_5.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(areSimilar(data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

