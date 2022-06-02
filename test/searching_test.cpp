#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <searching.h>
}

namespace SearchingModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/searching_test_data/" + fileName;
    }
}

TEST(SearchingModuleTest, SearchElementTest1) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_test_1.txt");
    arr_int *data = importIntArr(fileName.c_str());
    int result = searchElement(*data, 7);
    ASSERT_EQ(result, -325);
    freeIntArr(data);
}

TEST(SearchingModuleTest, SearchElementTest2) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_test_2.txt");
    arr_int *data = importIntArr(fileName.c_str());
    int result = searchElement(*data, 3);
    ASSERT_EQ(result, -449);
    freeIntArr(data);
}

TEST(SearchingModuleTest, SearchElementTest3) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_test_3.txt");
    arr_int *data = importIntArr(fileName.c_str());
    int result = searchElement(*data, 4);
    ASSERT_EQ(result, 99);
    freeIntArr(data);
}

TEST(SearchingModuleTest, SearchElementTest4) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_test_4.txt");
    arr_int *data = importIntArr(fileName.c_str());
    int result = searchElement(*data, 6);
    ASSERT_EQ(result, 1088266);
    freeIntArr(data);
}

TEST(SearchingModuleTest, SearchElement02Test1) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_02_test_1.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    int result = searchElement02(*data, 4);
    ASSERT_EQ(result, 4);
    freeIntMatrix(data);
}

TEST(SearchingModuleTest, SearchElement02Test2) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_02_test_2.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    int result = searchElement02(*data, 3);
    ASSERT_EQ(result, 178);
    freeIntMatrix(data);
}

TEST(SearchingModuleTest, SearchElement02Test3) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_02_test_3.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    int result = searchElement02(*data, 7);
    ASSERT_EQ(result, 481);
    freeIntMatrix(data);
}

TEST(SearchingModuleTest, SearchElement02Test4) {
    using namespace std;
    string fileName = SearchingModuleTest::getFullPath("search_element_02_test_4.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    int result = searchElement02(*data, 18);
    ASSERT_EQ(result, 742);
    freeIntMatrix(data);
}

