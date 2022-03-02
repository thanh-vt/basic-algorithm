#include <lib/c-commons/common-utility.h>
#include <lib/c-commons/common-string.h>

int chessBoardCellColor(const char *cell1, const char *cell2);

void checkBoardCellColorDemo() {
    printf("Enter cell 1:\n");
    arr_char* cell1 = scanString();
    printf("Enter cell 2:\n");
    arr_char* cell2 = scanString();
    int result = chessBoardCellColor(cell1->arr, cell2->arr);
    if (result) {
        printf("Cell %s has the same color as cell %s\n", cell1->arr, cell2->arr);
    } else {
        printf("Cell %s has the color which is different from cell %s\n", cell1->arr, cell2->arr);
    }
    deleteString(cell1);
    deleteString(cell2);
}

int chessBoardCellColor(const char *cell1, const char *cell2) {
    return ((cell1[0] + cell1[1] + cell2[0] + cell2[1]) % 2 == 0);
}

