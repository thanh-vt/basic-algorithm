#include <stdlib.h>
#include <common_utility.h>
#include <common_matrix.h>

matrix_int spiralNumbers(int n);

void spiralNumbersDemo() {
    printf("Enter spiral count:\n");
    int bishop1Cell = scanInt();
    matrix_int result = spiralNumbers(bishop1Cell);
    printIntMatrix(&result);
    printf("\n");
    matrix_int *x = &result;
    freeIntMatrix(x);
}

matrix_int spiralNumbers(int n) {
    matrix_int matrixInt;
    matrixInt.arr = calloc(n, sizeof(arr_int));;
    matrixInt.size = n;
    for (int i = 0; i < n; ++i) {
        matrixInt.arr[i].arr = calloc(n, sizeof(int));
        matrixInt.arr[i].size = n;
    }
    int l = 0;
    int r = n - 1;
    int k = 0;
    while (k < n * n) {
        if (k < n * n) {
            for (int j = l; j <= r; j++) {
                k++;
                matrixInt.arr[l].arr[j] = k;
            }
        }
        if (k < n * n) {
            for (int i = l + 1; i <= r; i++) {
                k++;
                matrixInt.arr[i].arr[r] = k;
            }
        }
        if (k < n * n) {
            for (int j = r - 1; j >= l; j--) {
                k++;
                matrixInt.arr[r].arr[j] = k;
            }
        }
        if (k < n * n) {
            for (int i = r - 1; i >= l + 1; i--) {
                k++;
                matrixInt.arr[i].arr[l] = k;
            }
        }
        l++;
        r--;
    }
    return matrixInt;
}