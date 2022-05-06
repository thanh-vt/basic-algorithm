#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <sorting.h>
#include <util.h>

void quickSort(int L, int R, arr_int a);

int getLeft(arr_int a);

int getRight(arr_int a);

void increase(int* idx, arr_int a);

void decrease(int* idx, arr_int a);

void sortByHeightDemo() {
    printf("Enter number of elements:\n");
    int numberOfElements = scanInt();
    arr_int *arrInt = scanIntArr(numberOfElements);
    printf("Before sorting:\n");
    printIntArr(arrInt);
    printf("\n");
    arr_int result = sortByHeight(*arrInt);
    printf("After sorting:\n");
    printIntArr(&result);
    printf("\n");
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt);
}

// quick sort
arr_int sortByHeight(arr_int a) {
    int L = getLeft(a);
    int R = getRight(a);
    quickSort(L, R, a);
    return a;
}

void quickSort(int L, int R, arr_int a) {
    if (L >= R) return;
    int i = L, j = R;
    int x = a.arr[L]; // assign pivot
    while (i <= j) {
        while (i < R && a.arr[i] < x) increase(&i, a);
        while (j > L && a.arr[j] > x) decrease(&j, a);
        if (i <= j) {
            swapInt(&(a.arr[i]), &(a.arr[j]));
            increase(&i, a);
            decrease(&j, a);
        }
    }
    quickSort(L, j, a);
    quickSort(i, R, a);
}

int getLeft(arr_int a) {
    int idx = 0;
    while (a.arr[idx] == -1 && idx < a.size) {
        idx++;
    }
    return idx;
}

int getRight(arr_int a) {
    int idx = a.size - 1;
    while (a.arr[idx] == -1 && idx >= 0) {
        idx--;
    }
    return idx;
}

void increase(int* idx, arr_int a) {
    do {
        (*idx)++;
    } while (a.arr[*idx] == -1);
}

void decrease(int* idx, arr_int a) {
    do {
        (*idx)--;
    } while (a.arr[*idx] == -1);
}



