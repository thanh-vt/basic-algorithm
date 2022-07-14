#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <searching.h>
#include <util.h>

void searchElementDemo() {
    printf("Enter number of elements of array:\n");
    int numberOfElements = scanInt();
    arr_int *arrInt = scanIntArr(numberOfElements);
    printf("Array:\n");
    printIntArr(arrInt);
    printf("\n");
    printf("Enter rank number:\n");
    int rank = scanInt();
    int result = searchElement(*arrInt, rank);
    printf("Number rank %d of the given array is %d.\n", result);
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt);
}

int searchElement(arr_int a, int n) {
    selectionSort(a);
    int h = 1;
    if (n == 1)
        return a.arr[a.size - 1];
    for (int i = a.size - 1; i >= 0; i--)
        if (a.arr[i] != a.arr[i + 1]) {
            h++;
            if (h == n + 1)
                return a.arr[i];
        }
    return -1;
}