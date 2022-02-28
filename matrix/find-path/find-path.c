#include <common-matrix.h>
#include <stdio.h>

int findPath(matrix_int matrix);

void findPathDemo() {
    matrix_int *matrixInt = importIntMatrix("matrix.txt");
    printIntMatrix(matrixInt);
    printf("\n");
    int found = findPath(*matrixInt);
    if (found) {
        printf("Found a path!");
    } else {
        printf("Path not found!");
    }
    freeIntMatrix(matrixInt);
    printf("\n");
}

int findPath(matrix_int matrix) {
    int column = matrix.arr[0].size;
    int row = matrix.size;
    int columnPosition = -1;
    int rowPosition = -1;
    int count = 2;
    // find start position (value = 1)
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix.arr[i].arr[j] == 1) {
                columnPosition = j;
                rowPosition = i;
            }
        }
    }
    // check if start position is invalid
    if (columnPosition == -1 && rowPosition == -1) {
        return 0;
    }
    // try step by step
    while (count <= column * row) {
        if (rowPosition + 1 >= 0 && rowPosition + 1 < row && matrix.arr[rowPosition + 1].arr[columnPosition] == count) {
            count++;
            rowPosition++;
        } else if (rowPosition - 1 >= 0 && rowPosition - 1 < row && matrix.arr[rowPosition - 1].arr[columnPosition] == count) {
            count++;
            rowPosition--;
        } else if (columnPosition - 1 >= 0 && columnPosition - 1 < column && matrix.arr[rowPosition].arr[columnPosition - 1] == count) {
            count++;
            columnPosition--;
        } else if (columnPosition + 1 >= 0 && columnPosition + 1 < column && matrix.arr[rowPosition].arr[columnPosition + 1] == count) {
            count++;
            columnPosition++;
        } else {
            return 0;
        }
    }
    return 1;
}