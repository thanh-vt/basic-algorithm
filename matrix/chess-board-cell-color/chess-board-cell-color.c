#include <common-utility.h>

int chessBoardCellColor(const char *cell1, const char *cell2);

void checkBoardCellColorDemo() {
    char cell1[512];
    char cell2[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter cell 1:\n");
        scanString(cell1);
        printf("Enter cell 2:\n");
        scanString(cell2);
        int result = chessBoardCellColor(cell1, cell2);
        if (result) {
            printf("Cell %s has the same color as cell %s\n", cell1, cell2);
        } else {
            printf("Cell %s has the color which is different from cell %s\n", cell1, cell2);
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int chessBoardCellColor(const char *cell1, const char *cell2) {
    return ((cell1[0] + cell1[1] + cell2[0] + cell2[1]) % 2 == 0);
}

