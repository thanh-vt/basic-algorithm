#ifndef COMMON_FUNCTIONS_COMMON_ARRAY_H
#define COMMON_FUNCTIONS_COMMON_ARRAY_H

typedef struct arr_char{
    char* arr;
    unsigned long long size;
} arr_char;

typedef struct arr_bool {
    int* arr;
    int size;
} arr_bool;

typedef struct arr_string {
    char** arr;
    int size;
} arr_string;

typedef struct arr_int {
    int* arr;
    int size;
} arr_int;

typedef struct arr_long {
    long long* arr;
    int size;
} arr_long;

typedef struct arr_double {
    double* arr;
    int size;
} arr_double;

/*
 * Array Utility
 */

arr_char* scanCharArr(int length);

void printCharArr(arr_char* arrChar);

arr_bool* scanBoolArr(int length);

arr_bool *convertToBoolArr(char *buff);

arr_bool *importBoolArr(char *fileName);

void printBoolArr(arr_bool* arrBool);

void freeBoolArr(arr_bool* arrBool);

arr_int* scanIntArr(int length);

arr_int *convertToIntArr(char *buff);

arr_int* importIntArr(char* fileName);

void printIntArr(arr_int* arrInt);

void freeIntArr(arr_int* arrInt);

arr_double* scanDoubleArr(int length);

arr_double *convertToDoubleArr(char *buff);

arr_double *importDoubleArr(char *fileName);

void printDoubleArr(arr_double* arrDouble);

void freeDoubleArr(arr_double* arrDouble);

arr_long* scanLongArr(int length);

arr_long *convertToLongArr(char *buff);

arr_long* importLongArr(char* fileName);

void printLongArr(arr_long* arrLong);

void freeLongArr(arr_long* arrLong);

arr_string* scanStringArr(int length);

arr_string *convertToStringArr(char *buff);

arr_string* importStringArr(char* fileName);

void printStringArr(arr_string* arrString);

void freeStringArr(arr_string* arrString);

#endif //COMMON_FUNCTIONS_COMMON_ARRAY_H
