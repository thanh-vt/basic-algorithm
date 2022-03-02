#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <arithmetic.h>
}

TEST(ArithmeticModuleTest, IsPrimeTest1) {
    int result = isPrime(47);
    ASSERT_EQ(result, 1);
}

TEST(ArithmeticModuleTest, IsPrimeTest2) {
    int result = isPrime(4);
    ASSERT_EQ(result, 0);
}

TEST(ArithmeticModuleTest, IsPrimeTest3) {
    int result = isPrime(133);
    ASSERT_EQ(result, 0);
}

TEST(ArithmeticModuleTest, IsPrimeTest4) {
    int result = isPrime(0);
    ASSERT_EQ(result, 0);
}

TEST(ArithmeticModuleTest, IsPrimeTest5) {
    int result = isPrime(120);
    ASSERT_EQ(result, 0);
}