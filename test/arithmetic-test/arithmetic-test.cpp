#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
}

TEST(CommonMatrix, BoolMatrixTest) {
    char fileName[] = "arithmetic-test/bool-matrix.txt";
    matrix_bool *pMatrixBool = importBoolMatrix(fileName);
    ASSERT_NO_THROW(printBoolMatrix(pMatrixBool));
    ASSERT_EQ(pMatrixBool->size, 20);
    ASSERT_EQ(pMatrixBool->arr[2].size, 35);
    printf("\n");
}