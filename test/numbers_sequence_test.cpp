#include <gtest/gtest.h>

extern "C" {
#include <common-array.h>
#include <numbers-sequence.h>
}

namespace NumbersSequenceModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/numbers_sequence_test_data/" + fileName;
    }
}


TEST(NumbersSequenceModuleTest, IsMonotonousTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_FALSE(isMonotonous(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest4) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_4.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest5) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_5.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isArithmeticProgression(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_FALSE(isArithmeticProgression(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_FALSE(isArithmeticProgression(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest4) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_4.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isArithmeticProgression(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest5) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_5.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isArithmeticProgression(*numbersSequence));
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, PrefixSumsTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("prefix_sums_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = prefixSums(*numbersSequence);
    ASSERT_EQ(result.arr[0], 1);
    ASSERT_EQ(result.arr[1], 3);
    ASSERT_EQ(result.arr[2], 6);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, PrefixSumsTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("prefix_sums_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = prefixSums(*numbersSequence);
    ASSERT_EQ(result.arr[0], 1);
    ASSERT_EQ(result.arr[1], 3);
    ASSERT_EQ(result.arr[2], 6);
    ASSERT_EQ(result.arr[3], 0);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, PrefixSumsTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("prefix_sums_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = prefixSums(*numbersSequence);
    ASSERT_EQ(result.arr[0], 0);
    ASSERT_EQ(result.arr[1], 0);
    ASSERT_EQ(result.arr[2], 0);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, AlternatingSumsTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("alternating_sums_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = alternatingSums(*numbersSequence);
    ASSERT_EQ(result.arr[0], 180);
    ASSERT_EQ(result.arr[1], 105);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, AlternatingSumsTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("alternating_sums_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = alternatingSums(*numbersSequence);
    ASSERT_EQ(result.arr[0], 100);
    ASSERT_EQ(result.arr[1], 50);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, AlternatingSumsTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("alternating_sums_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = alternatingSums(*numbersSequence);
    ASSERT_EQ(result.arr[0], 1);
    ASSERT_EQ(result.arr[1], 0);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, MakeArrayConsecutiveTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("make_array_consecutive_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = makeArrayConsecutive(*numbersSequence);
    ASSERT_EQ(result.size, 3);
    ASSERT_EQ(result.arr[0], 4);
    ASSERT_EQ(result.arr[1], 5);
    ASSERT_EQ(result.arr[2], 7);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, MakeArrayConsecutiveTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("make_array_consecutive_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = makeArrayConsecutive(*numbersSequence);
    ASSERT_EQ(result.size, 1);
    ASSERT_EQ(result.arr[0], -2);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, MakeArrayConsecutiveTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("make_array_consecutive_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = makeArrayConsecutive(*numbersSequence);
    ASSERT_EQ(result.size, 0);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, MakeArrayConsecutiveTest4) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("make_array_consecutive_test_4.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    arr_int result = makeArrayConsecutive(*numbersSequence);
    ASSERT_EQ(result.size, 3);
    ASSERT_EQ(result.arr[0], 0);
    ASSERT_EQ(result.arr[1], 1);
    ASSERT_EQ(result.arr[2], 2);
    freeIntArr(numbersSequence);
    free(result.arr);
}

TEST(NumbersSequenceModuleTest, LongestSequenceTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("longest_sequence_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    int result = longestSequence(*numbersSequence);
    ASSERT_EQ(result, 3);
    freeIntArr(numbersSequence);
}

TEST(NumbersSequenceModuleTest, LongestSequenceTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("longest_sequence_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    int result = longestSequence(*numbersSequence);
    ASSERT_EQ(result, 4);
    freeIntArr(numbersSequence);
}


TEST(NumbersSequenceModuleTest, LongestSequenceTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("longest_sequence_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    int result = longestSequence(*numbersSequence);
    ASSERT_EQ(result, 3);
    freeIntArr(numbersSequence);
}


TEST(NumbersSequenceModuleTest, LongestSequenceTest4) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("longest_sequence_test_4.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    int result = longestSequence(*numbersSequence);
    ASSERT_EQ(result, 4);
    freeIntArr(numbersSequence);
}




