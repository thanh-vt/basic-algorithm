#ifndef BASIC_ALGORITHMS_UTIL_H
#define BASIC_ALGORITHMS_UTIL_H

extern char ARITHMETIC_MENU_PATH[];

extern char COUNTING_MENU_PATH[];

extern char GEOMETRY_MENU_PATH[];

extern char GRAPH_MENU_PATH[];

extern char MATRIX_MENU_PATH[];

extern char NUMBERS_SEQUENCE_MENU_PATH[];

extern char SEARCHING_MENU_PATH[];

extern char SORTING_MENU_PATH[];

extern char STRING_HANDLING_MENU_PATH[];

void swapString(char **bishop1_ptr, char **bishop2_ptr);

void swapInt(int *xp, int *yp);

int compareIntArr(arr_int arrInt1, arr_int arrInt2);

void selectionSort(arr_int arrInt);

#endif //BASIC_ALGORITHMS_UTIL_H
