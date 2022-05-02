#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <numbers-sequence.h>

void isArithmeticProgressionDemo() {
    printf("Enter numbers sequence's size:\n");
    int size = scanInt();
    printf("Enter numbers sequence:\n");
    arr_int* points = scanIntArr(size);
    int result = isMonotonous(*points);
    printf("That numbers sequence is%s a arithmetic progression.\n", result ? "" : " not");
}

int isArithmeticProgression(arr_int sequence) {
    if (sequence.size <= 1)
        return 1;
    int k = sequence.arr[1] - sequence.arr[0];
    for (int i = 1; i < sequence.size; i++)
        if (sequence.arr[i]-sequence.arr[i-1]!=k)
            return 0;
    return 1;
}