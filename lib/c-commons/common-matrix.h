#ifndef COMMON_FUNCTIONS_COMMON_MATRIX_H
#define COMMON_FUNCTIONS_COMMON_MATRIX_H
#include "common-array.h"

typedef struct matrix_char {
    arr_char* arr;
    int size;
} matrix_char;

typedef struct matrix_bool {
    arr_bool* arr;
    int size;
} matrix_bool;

typedef struct matrix_string {
    arr_string* arr;
    int size;
} matrix_string;

typedef struct matrix_int {
    arr_int* arr;
    int size;
} matrix_int;

typedef struct matrix_long {
    arr_long* arr;
    int size;
} matrix_long;

typedef struct matrix_double {
    arr_double* arr;
    int size;
} matrix_double;

/*
 * Matrix Utility
 */

matrix_char *scanCharMatrix(int numberOfRows, int numberOfColumns);

void printCharMatrix(matrix_char *pMatrixChar);

void freeCharMatrix(matrix_char* pMatrixChar);

matrix_bool* scanBoolMatrix(int numberOfRows, int numberOfColumns);

matrix_bool *importBoolMatrix(const char *fileName);

void printBoolMatrix(matrix_bool* pMatrixBool);

void freeBoolMatrix(matrix_bool* pMatrixBool);

matrix_int* scanIntMatrix(int numberOfRows, int numberOfColumns);

matrix_int *importIntMatrix(const char *fileName);

void printIntMatrix(matrix_int* matrixInt);

void freeIntMatrix(matrix_int* matrixInt);

matrix_double* scanDoubleMatrix(int numberOfRows, int numberOfColumns);

matrix_double *importDoubleMatrix(const char *fileName);

void printDoubleMatrix(matrix_double* pMatrixDouble);

void freeDoubleMatrix(matrix_double* pMatrixDouble);

matrix_long* scanLongMatrix(int numberOfRows, int numberOfColumns);

matrix_long *importLongMatrix(const char *fileName);

void printLongMatrix(matrix_long* pMatrixLong);

void freeLongMatrix(matrix_long* pMatrixLong);

matrix_string *scanStringMatrix(int numberOfRows, int numberOfColumns);

matrix_string *importStringMatrix(const char *fileName);

void printStringMatrix(matrix_string *pMatrixString);

void freeStringMatrix(matrix_string *pMatrixString);

#endif //COMMON_FUNCTIONS_COMMON_MATRIX_H
