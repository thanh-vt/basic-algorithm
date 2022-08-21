#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <searching.h>
#include <stdlib.h>

void beautifulArrayDemo() {
    printf("Enter array's size:\n");
    int size = scanInt();
    arr_int *arrInt = scanIntArr(size);
    printf("Array:\n");
    printIntArr(arrInt);
    printf("\n");
    printf("Enter rank number:\n");
    int result = beautifulArray(*arrInt);
    printf("The given array is %s a beautiful array.\n", result ? "" : "not");
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt);
}

int beautifulArray(arr_int arr) {
    arr_int s;
    s.size = arr.size;
    s.arr = calloc(s.size, sizeof(int));
    if (s.size == 0) return 0;
    s.arr[0] = arr.arr[0];
    for (int i = 1; i < arr.size; i++) {
        s.arr[i] = s.arr[i-1] + arr.arr[i];
    }
    for (int i = 1; i < arr.size - 1; i++) {
        if (s.arr[i-1] == s.arr[s.size - 1] - s.arr[i])
            return 1;
    }
    return 0;
}
