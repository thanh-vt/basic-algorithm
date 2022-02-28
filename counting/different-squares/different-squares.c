#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <common-utility.h>
#include <common-matrix.h>
#include <common-string.h>

int differentSquares(matrix_int matrix);

void differentSquaresDemo() {

//    matrix_int *matrixInt = calloc(1, sizeof(matrix_int));
//    matrixInt->size = 5;
//    matrixInt->arr = calloc(5, sizeof(arr_int));
//    (matrixInt->arr)[0].arr = (int *) calloc(3, sizeof(int));
//    (matrixInt->arr)[0].size = 3;
//    (matrixInt->arr)[0].arr[0] = 1;
//    (matrixInt->arr)[0].arr[1] = 2;
//    (matrixInt->arr)[0].arr[2] = 1;
//    (matrixInt->arr)[1].arr = (int *) calloc(3, sizeof(int));
//    (matrixInt->arr)[1].size = 3;
//    (matrixInt->arr)[1].arr[0] = 2;
//    (matrixInt->arr)[1].arr[1] = 2;
//    (matrixInt->arr)[1].arr[2] = 2;
//    (matrixInt->arr)[2].arr = (int *) calloc(3, sizeof(int));
//    (matrixInt->arr)[2].size = 3;
//    (matrixInt->arr)[2].arr[0] = 2;
//    (matrixInt->arr)[2].arr[1] = 2;
//    (matrixInt->arr)[2].arr[2] = 2;
//    (matrixInt->arr)[3].arr = (int *) calloc(3, sizeof(int));
//    (matrixInt->arr)[3].size = 3;
//    (matrixInt->arr)[3].arr[0] = 1;
//    (matrixInt->arr)[3].arr[1] = 2;
//    (matrixInt->arr)[3].arr[2] = 3;
//    (matrixInt->arr)[4].arr = (int *) calloc(3, sizeof(int));
//    (matrixInt->arr)[4].size = 3;
//    (matrixInt->arr)[4].arr[0] = 2;
//    (matrixInt->arr)[4].arr[1] = 2;
//    (matrixInt->arr)[4].arr[2] = 1;
    int result, command;
    matrix_int *matrixInt;
    printf(">>> Start >>>\n");
    do {
        printf("Enter number of rows:\n");
        int numberOfRows = scanInt();
        printf("Enter number of columns:\n");
        int numberOfColumns = scanInt();
        matrixInt = scanIntMatrix(numberOfRows, numberOfColumns);
        printIntMatrix(matrixInt);
        printf("\n");
        result = differentSquares(*matrixInt);
        printf("Different squares of the given matrix: %d!\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        freeIntMatrix(matrixInt);
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int differentSquares(matrix_int matrix) {
    arr_char *wholeStr = createString();
    int sum = 0;
    for (int i = 0; i < matrix.size - 1; ++i) {
        arr_int *arrInt = &matrix.arr[i];
        arr_int *arrInt2 = &matrix.arr[i + 1];
        for (int j = 0; j < arrInt->size - 1; ++j) {
            arr_char *string = createString();
            concatString(string, "@");
            char *str = calloc(4, sizeof(char));
            str[0] = arrInt->arr[j] + '0';
            str[1] = arrInt->arr[j + 1] + '0';
            str[2] = arrInt2->arr[j] + '0';
            str[3] = arrInt2->arr[j + 1] + '0';
            concatString(string, str);
            concatString(string, "@");
            if (!strstr(wholeStr->arr, string->arr)) {
                concatString(wholeStr, string->arr);
                sum++;
            }
            free(str);
            deleteString(string);
        }
    }
    deleteString(wholeStr);
    return sum;
}