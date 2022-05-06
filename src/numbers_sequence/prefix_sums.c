#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <numbers_sequence.h>
#include <stdlib.h>

void prefixSumsDemo() {
    printf("Enter numbers sequence's size:\n");
    int size = scanInt();
    printf("Enter numbers sequence:\n");
    arr_int *points = scanIntArr(size);
    arr_int result = prefixSums(*points);
    printf("Prefix sums of that numbers sequence is:\n");
    printIntArr(&result);
    freeIntArr(points);
    free(result.arr);
}

arr_int prefixSums(arr_int a) {
    arr_int b;
    b.arr = calloc(a.size, sizeof(int));
    b.size = a.size;
    b.arr[0] = a.arr[0];
    for (int i = 1; i < a.size; i++)
        b.arr[i] = (b.arr[i - 1] + a.arr[i]);
    return b;
}