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
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_FALSE(isMonotonous(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest4) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_4.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsMonotonousTest5) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_monotonous_test_5.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isMonotonous(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest1) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_1.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isArithmeticProgression(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest2) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_2.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_FALSE(isArithmeticProgression(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest3) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_3.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_FALSE(isArithmeticProgression(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest4) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_4.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isArithmeticProgression(*numbersSequence));
}

TEST(NumbersSequenceModuleTest, IsArithmeticProgressionTest5) {
    using namespace std;
    string fileName = NumbersSequenceModuleTest::getFullPath("is_arithmetic_progression_test_5.txt");
    arr_int *numbersSequence = importIntArr(fileName.c_str());
    ASSERT_TRUE(isArithmeticProgression(*numbersSequence));
}

