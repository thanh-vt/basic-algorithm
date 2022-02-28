#include <stdlib.h>
#include <common-utility.h>

arr_int sortArray(arr_int arr);

arr_int *merge(arr_int *arrInt1, arr_int *arrInt2);

arr_int *subIntArr(arr_int *source, int start, int end);

void sortArrayDemo() {
    int command;
    arr_int *arrInt;
    arr_int result;
    printf(">>> Start >>>\n");
    do {
        printf("Enter number of elements:\n");
        int numberOfElements = scanInt();
        arrInt = scanIntArr(numberOfElements);
        printf("Before sorting:\n");
        printIntArr(arrInt);
        printf("\n");
        result = sortArray(*arrInt);
        printf("After sorting:\n");
        printIntArr(&result);
        printf("\n");
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        freeIntArr(arrInt);
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

arr_int sortArray(arr_int arr) {
    int mid = arr.size / 2;
    arr_int *sub1 = subIntArr(&arr, 0, mid - 1);
    arr_int *sub2 = subIntArr(&arr, mid, arr.size - 1);
    if (sub1->size > 1) {
        *sub1 = sortArray(*sub1);
    }
    if (sub2->size > 1) {
        *sub2 = sortArray(*sub2);
    }
    arr = *merge(sub1, sub2);
    freeIntArr(sub1);
    freeIntArr(sub2);
    return arr;
}

arr_int *merge(arr_int *arrInt1, arr_int *arrInt2) {
    arr_int *arrInt = calloc(1, sizeof(arr_int));
    arrInt->size = arrInt1->size + arrInt2->size;
    arrInt->arr = calloc(arrInt->size, sizeof(int));
//    printf("Before Merged:\n");
//    printIntArr(arrInt1);
//    printf("\n");
//    printIntArr(arrInt2);
//    printf("\nMerged size: %d\n", arrInt->size);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < arrInt->size) {
//        printf("i = %d, j = %d, k = %d, size arr1 = %d, size arr2 = %d, size arr = %d\n", i, j, k, arrInt1->size, arrInt2->size, arrInt->size);
        if (j >= arrInt1->size && k >= arrInt2->size) {
            break;
        }
        if (k >= arrInt2->size) {
            arrInt->arr[i] = arrInt1->arr[j];
            j++;
            i++;
            continue;
        } else if (j >= arrInt1->size) {
            arrInt->arr[i] = arrInt2->arr[k];
            k++;
            i++;
            continue;
        }
        if (arrInt1->arr[j] <= arrInt2->arr[k]) {
            arrInt->arr[i] = arrInt1->arr[j];
            j++;
            i++;
        } else if (arrInt1->arr[j] >= arrInt2->arr[k]) {
            arrInt->arr[i] = arrInt2->arr[k];
            k++;
            i++;
        }
    }
    printIntArr(arrInt);
//    printf("\nEnd Merged i = %d:\n", i);
    return arrInt;
}

arr_int *subIntArr(arr_int *source, int start, int end) {
    arr_int *dest = calloc(1, sizeof(arr_int));
    dest->size = end - start + 1;
    dest->arr = calloc(dest->size, sizeof(int));
    int j = start;
    for (int i = 0; i < dest->size; ++i) {
        dest->arr[i] = source->arr[j];
        j++;
    }
    return dest;
}

