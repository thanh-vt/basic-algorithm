#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <numbers-sequence.h>
#include <stdlib.h>
#include <util.h>

void makeArrayConsecutiveDemo() {
    printf("Enter numbers sequence's size:\n");
    int size = scanInt();
    printf("Enter numbers sequence:\n");
    arr_int *points = scanIntArr(size);
    arr_int result = makeArrayConsecutive(*points);
    printf("Consecutive array of that numbers sequence is:\n");
    printIntArr(&result);
    freeIntArr(points);
    free(result.arr);
}

arr_int makeArrayConsecutive(arr_int sequence) {
    arr_int a;
    selectionSort(sequence);
    int maxLength = sequence.arr[sequence.size - 1] - sequence.arr[0];
    int tempArr[maxLength];
    int j = 0;
    int k = sequence.arr[0];
    int h = 0;
    while (k != sequence.arr[sequence.size - 1]) {
        if (k == sequence.arr[h]) {
            k++;
            h++;
        } else {
            while (k != sequence.arr[h]) {
                tempArr[j] = k;
                k++;
                j++;
            }
        }
    }
    // copy to result array
    a.arr= calloc(j, sizeof(int));
    a.size = j;
    for (int i = 0; i < j; ++i) {
        a.arr[i] = tempArr[i];
    }
    return a;
}