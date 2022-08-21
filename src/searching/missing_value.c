#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <searching.h>
#include <stdlib.h>
#include <util.h>

void missingValueDemo() {
    printf("Enter array 1's size:\n");
    int arr1Size = scanInt();
    printf("Enter array 2's size:\n");
    int arr2Size = scanInt();
    printf("Scan array 1:\n");
    arr_int *arrInt1 = scanIntArr(arr1Size);
    printf("Scan array 2:\n");
    arr_int *arrInt2 = scanIntArr(arr1Size);
    printf("Array 1:\n");
    printIntArr(arrInt1);
    printf("\n");
    printf("Array 2:\n");
    printIntArr(arrInt2);
    printf("\n");
    printf("Enter rank number:\n");
    arr_int result = missingValue(*arrInt1, *arrInt2);
    printf("Missing values array of the two given arrays is:\n", result);
    printIntArr(arrInt2);
    freeIntArr(arrInt1);
    freeIntArr(arrInt2);
    free(result.arr);
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
}

arr_int missingValue(arr_int a, arr_int b) {
    arr_int check;
    check.size = 100001;
    check.arr = calloc(check.size, sizeof(int));
    for (int i = 0; i < a.size; i++){
        check.arr[a.arr[i]] = 1;
    }
    arr_int ans;
    ans.arr = calloc(b.size, sizeof(int));
    int count = 0;
    for (int i = 0; i < b.size; i++){
        if (!check.arr[b.arr[i]]){
            ans.arr[count++] = b.arr[i];
        }
    }
    ans.size = count;
    ans.arr = realloc(ans.arr, count * sizeof(int));
    heapSort(ans);
    free(check.arr);
    return ans;
}