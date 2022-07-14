#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <searching.h>
#include <common_matrix.h>
#include <util.h>
#include <stdlib.h>

void searchElement02Demo() {
    printf("Enter number of rows of matrix:\n");
    int numberOfRows = scanInt();
    printf("Enter number of columns of matrix:\n");
    int numberOfColumns = scanInt();
    matrix_int *matrixInt = scanIntMatrix(numberOfRows, numberOfColumns);
    printf("Matrix:\n");
    printIntMatrix(matrixInt);
    printf("\n");
    printf("Enter rank number:\n");
    int rank = scanInt();
    int result = searchElement02(*matrixInt, rank);
    printf("Number rank %d of the given matrix is %d.\n", result);
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntMatrix(matrixInt);
}

int searchElement02(matrix_int a, int k) {
    arr_int b;
    int m = a.size;
    int n = a.arr[0].size;
    b.size = m * n;
    b.arr = calloc(b.size, sizeof(int));
    int l = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b.arr[l] = (a.arr[i].arr[j]);
            l++;
        }
    }
    selectionSort(b);
    int h = 1;
    if (k == 1)
        return b.arr[0];
    for (int i = 1; i < b.size; i++)
        if (b.arr[i] != b.arr[i - 1]) {
            h++;
            if (h == k)
                return b.arr[i];
        }
    free(b.arr);
    return -1;
}

