#include <stdlib.h>
#include <common-utility.h>
#include <common-matrix.h>

int sudokuChecking(matrix_char grid);

void sudokuCheckingDemo() {
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter sudoku matrix:\n");
        matrix_char *matrixInt = scanCharMatrix(9, 9);
        int result = sudokuChecking(*matrixInt);
        printf("Given Sudoku matrix is %s\n", result ? "valid" : "invalid");
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int sudokuChecking(matrix_char grid) {
    if (grid.size != 9 || grid.arr[0].size != 9)
        return 0;
    // check each column
    for (int i = 0; i < 9; i++) {
        int *m = calloc(9, sizeof(int));
        for (int j = 0; j < 9; j++) {
            if (grid.arr[i].arr[j] != '.') {
                if (m[(grid.arr[i].arr[j] - '1')]) {
                    return 0;
                }
                m[(grid.arr[i].arr[j] - '1')] = 1;
            }/**/
        }
    }

    //check each row
    for (int j = 0; j < 9; j++) {
        int *m = calloc(9, sizeof(int));
        for (int i = 0; i < 9; i++) {
            if (grid.arr[i].arr[j] != '.') {
                if (m[(grid.arr[i].arr[j] - '1')]) {
                    return 0;
                }
                m[(grid.arr[i].arr[j] - '1')] = 1;
            }
        }
    }

    //check each 3*3 matrix
    for (int block = 0; block < 9; block++) {
        int *m = calloc(9, sizeof(int));
        for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++) {
            for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {
                if (grid.arr[i].arr[j] != '.') {
                    if (m[(grid.arr[i].arr[j] - '1')]) {
                        return 0;
                    }
                    m[(grid.arr[i].arr[j] - '1')] = 1;
                }
            }
        }
    }
    return 1;
}