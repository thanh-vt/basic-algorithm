#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <sorting.h>

void digitalSumSortDemo() {
    printf("Enter number of elements:\n");
    int numberOfElements = scanInt();
    arr_int *arrInt = scanIntArr(numberOfElements);
    printf("Before sorting:\n");
    printIntArr(arrInt);
    printf("\n");
    arr_int result = digitalSumSort(*arrInt);
    printf("After sorting:\n");
    printIntArr(&result);
    printf("\n");
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt);
}

arr_int digitalSumSort(arr_int a) {

}