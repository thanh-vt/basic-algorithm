#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <numbers_sequence.h>
#include <stdlib.h>

void alternatingSumsDemo() {
    printf("Enter numbers sequence's size:\n");
    int size = scanInt();
    printf("Enter numbers sequence:\n");
    arr_int *points = scanIntArr(size);
    arr_int result = prefixSums(*points);
    printf("Alternating sums of that numbers sequence is:\n");
    printIntArr(&result);
    freeIntArr(points);
    free(result.arr);
}

arr_int alternatingSums(arr_int a) {
    int x = 0;
    int y = 0;
    arr_int b;
    b.arr = calloc(2, sizeof(int));
    b.size = 2;
    for (int i = 0; i < a.size; i += 2) x += a.arr[i];
    for (int i = 1; i < a.size; i += 2) y += a.arr[i];
    b.arr[0] = x;
    b.arr[1] = y;
    return b;
}