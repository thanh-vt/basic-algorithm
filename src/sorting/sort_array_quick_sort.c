#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <sorting_test.h>
#include <util.h>

void quickSort(int L, int R, arr_int a);

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

arr_int sortByHeight(arr_int a) {
    quickSort(0, a.size - 1, a);
    return a;
}

int count = 0;

void quickSort(int L, int R, arr_int a) {
    if (L >= R) { return; }
    int i = L, j = R, x = a.arr[(L + R) / 2];
    while (i <= j) {
        while (a.arr[i] == -1 || (i <= R && a.arr[i] < x)) ++i; // ignore if it is position of a tree
        while (a.arr[j] == -1 || (j >= L && a.arr[j] > x)) --j; // ignore if it is position of a tree
//        if (j < 0 || i >= a.size) return;
        if (i <= j) {
            swapInt(&(a.arr[i]), &(a.arr[j]));
            ++i;
            --j;
        }

    }
    count++;
    if (count >= 1000) return;

    int k = j < 0 ? L : j;
    int l = i >= a.size ? R: i;
    printf("x = %d, y = %d\n", k, l);
    quickSort(L, k, a);
    quickSort(l, R, a);
}


