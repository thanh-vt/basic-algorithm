#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <sorting.h>
#include <stdlib.h>

int sum(int n);

void digitalSumSortDemo() {
    printf("Enter number of elements:\n");
    int numberOfElements = scanInt();
    arr_int *arrInt = scanIntArr(numberOfElements);
    printf("Before digital sum sorting:\n");
    printIntArr(arrInt);
    printf("\n");
    arr_int result = digitalSumSort(*arrInt);
    printf("After digital sum sorting:\n");
    printIntArr(&result);
    printf("\n");
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt);
}

arr_int digitalSumSort(arr_int a) {
    int maxVal = 27; // max = 1000 => max digital sum = 9 + 9 + 9 = 27
    int* valueCountArr = calloc(maxVal + 1, sizeof(int));
    // value - count array
    for (int i = 0; i < a.size; ++i) {
        valueCountArr[a.arr[i]]++;
    }
    // modify value count array to accumulated array
    int sum = 0;
    for (int i = 0; i <= maxVal; ++i) {
        valueCountArr[i] = sum;
        sum += valueCountArr[i];
    }
    // create result array by value index
    int* resultArr = calloc(a.size, sizeof(int));
    for (int i = 0; i < a.size; ++i) {
        int val = a.arr[i];
        int position = valueCountArr[val];
        resultArr[position - 1] = val;
        valueCountArr[val]--;
    }

    for (int i = 0; i < a.size; ++i) {
        printf("%d, ", resultArr[i]);
        a.arr[i] = resultArr[i];
    }
//    free(valueCountArr);
//    free(resultArr);
    return a;
}

int sum(int n) {
    int d = 0;
    while (n > 0) {
        d += n % 10;
        n /= 10;
    }
    return d;
}
