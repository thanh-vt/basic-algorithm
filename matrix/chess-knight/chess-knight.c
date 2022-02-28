#include <stdio.h>
#include <common-utility.h>

int chessKnight(const char *cell);

void chessKnightDemo() {
    char knightCell[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter knight's cell:\n");
        scanf("%s", knightCell);
        int result = chessKnight(knightCell);
        printf("Possible steps of knight's cell: %d\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int chessKnight(const char *cell) {
    int d = 0;
    if (cell[0] + 1 <= 'h' && cell[1] + 2 <= '8')
        d++;
    if (cell[0] + 2 <= 'h' && cell[1] + 1 <= '8')
        d++;
    if (cell[0] + 2 <= 'h' && cell[1] - 1 >= '1')
        d++;
    if (cell[0] + 1 <= 'h' && cell[1] - 2 >= '1')
        d++;
    if (cell[0] - 1 >= 'a' && cell[1] - 2 >= '1')
        d++;
    if (cell[0] - 2 >= 'a' && cell[1] - 1 >= '1')
        d++;
    if (cell[0] - 2 >= 'a' && cell[1] + 1 <= '8')
        d++;
    if (cell[0] - 1 >= 'a' && cell[1] + 2 <= '8')
        d++;
    return d;
}