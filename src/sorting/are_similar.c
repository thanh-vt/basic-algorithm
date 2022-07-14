#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <sorting.h>

void areSimilarDemo() {
    printf("Enter number of elements of array 1:\n");
    int numberOfElements1 = scanInt();
    arr_int *arrInt1 = scanIntArr(numberOfElements1);
    printf("Enter number of elements of array 2:\n");
    int numberOfElements2 = scanInt();
    arr_int *arrInt2 = scanIntArr(numberOfElements2);
    printf("Array 1:\n");
    printIntArr(arrInt1);
    printf("\n");
    printf("Array 2:\n");
    printIntArr(arrInt2);
    printf("\n");
    int result = areSimilar(*arrInt1, *arrInt2);
    printf("Two arrays are %s.\n", result ? " similar" : " not similar");
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt1);
    freeIntArr(arrInt2);
}

int areSimilar(arr_int a, arr_int b) {
    if (a.size != b.size) return 0;
    int a1, a2, b1, b2;
    int count = 0;
    for (int i = 0; i < a.size; ++i) {
        if (a.arr[i] != b.arr[i]) {
            count++;
            if (count == 1) {
                a1 = a.arr[i];
                b1 = b.arr[i];
            } else if (count == 2) {
                a2 = a.arr[i];
                b2 = b.arr[i];
            }
        }
    }
    if (count != 0 && count != 2) return 0;
    if (count == 2) {
        return a1 == b2 && a2 == b1;
    }
    return 1;
}
