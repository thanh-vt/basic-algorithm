#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <sorting.h>
#include <util.h>
#include <string.h>

void sortByLengthDemo() {
    printf("Enter number of elements:\n");
    int numberOfElements = scanInt();
    arr_string *arrString = scanStringArr(numberOfElements);
    printf("Before sorting:\n");
    printStringArr(arrString);
    printf("\n");
    arr_string result = sortByLength(*arrString);
    printf("After sorting:\n");
    printStringArr(&result);
    printf("\n");
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeStringArr(arrString);
}

// bubble sort
arr_string sortByLength(arr_string inputArray) {
    int n = inputArray.size;
    int swapped = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (strlen(inputArray.arr[j]) > strlen(inputArray.arr[j+1])) {
                swapString(&inputArray.arr[j], &inputArray.arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            return inputArray;
        }
    }
    return inputArray;
}
