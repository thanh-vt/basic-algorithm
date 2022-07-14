#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <numbers_sequence.h>

void isMonotonousDemo() {
    printf("Enter numbers sequence's size:\n");
    int size = scanInt();
    printf("Enter numbers sequence:\n");
    arr_int* points = scanIntArr(size);
    int result = isMonotonous(*points);
    printf("That numbers sequence is%s a monotonous.\n", result ? "" : " not");
    freeIntArr(points);
}

int isMonotonous(arr_int sequence) {
    if (sequence.size == 1)
        return 1;
    if (sequence.size == 2)
        return (sequence.arr[0] != sequence.arr[1]);
    for (int i = 2; i < sequence.size; i++)
        if ((sequence.arr[i - 1] - sequence.arr[i - 2]) * (sequence.arr[i] - sequence.arr[i - 1]) <= 0)
            return 0;
    return 1;
}

