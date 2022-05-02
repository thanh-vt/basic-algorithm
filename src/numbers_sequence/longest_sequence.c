#include <common-array.h>
#include <stdio.h>
#include <common-utility.h>
#include <numbers-sequence.h>
#include <common-number.h>

void longestSequenceDemo() {
    printf("Enter numbers sequence's size:\n");
    int size = scanInt();
    printf("Enter numbers sequence:\n");
    arr_int* points = scanIntArr(size);
    int result = longestSequence(*points);
    printf("Longest sequence of that numbers sequence is %d.\n", result);
    freeIntArr(points);
}

int longestSequence(arr_int a) {
    int n = a.size;
    if (n <= 2)
        return n;
    int maxLength = 0;
    int currentLength;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int list[a.size];
            int index = 0;
            int cDiff = a.arr[j] - a.arr[i];
            if (cDiff == 0) {
                continue;
            }
            list[index++] = a.arr[i]; // = list.add() in Java
            list[index++] = a.arr[j];
            for (int k = j; k < n; k++) {
                if (a.arr[k] - list[index - 1] != cDiff) {
                    continue;
                }
                list[index++] = a.arr[k];
                currentLength = index;
                maxLength = maxNum(maxLength, currentLength);
            }
        }
    }
    return maxLength;
}