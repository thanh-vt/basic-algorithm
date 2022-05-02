#include <common-array.h>
#include <stdlib.h>
#include <util.h>

int checkConnect(arr_int lst, int i, arr_int fromV, arr_int toV);

int isTournament(int n, arr_int fromV, arr_int toV) {
    if (fromV.size != toV.size) {
        return 0;
    }
    int status = 1;
    arr_int lst;
    lst.size = n;
    lst.arr = calloc(lst.size, sizeof(int));
    for (int i = 0; i < n; i++) {
        lst.arr[i] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        status = status && checkConnect(lst, i, fromV, toV);
    }
    free(lst.arr);
    return status;
}

int checkConnect(arr_int lst, int i, arr_int fromV, arr_int toV) {
    arr_int lst1;
    int index = 0;
    lst1.arr = calloc(fromV.size + toV.size, sizeof(int));
    lst1.arr[index++] = i; // = lst1.add() in java
    for (int j = 0; j < toV.size; j++) {
        if (toV.arr[j] == i) {
            lst1.arr[index++] = fromV.arr[j];
        }
        if (fromV.arr[j] == i) {
            lst1.arr[index++] = toV.arr[j];
        }
    }
    lst1.size = index;
    selectionSort(lst1);
    int is2ArraysEqual = compareIntArr(lst, lst1);
    free(lst1.arr);
    return is2ArraysEqual;
}