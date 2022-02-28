#include <stdio.h>
#include <stdlib.h>
#include <common-utility.h>

int bishopAndPawn(char *bishop, char *pawn);

void bishopAndPawnDemo() {
    char bishopCell[512];
    char pawnCell[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter bishop's cell:\n");
        scanString(bishopCell);
        printf("Enter pawn's cell:\n");
        scanString(pawnCell);
        int result = bishopAndPawn(bishopCell, pawnCell);
        if (result) {
            printf("Bishop can eliminate pawn in 1 turn\n");
        } else {
            printf("Bishop cannot eliminate pawn in 1 turn\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int bishopAndPawn(char *bishop, char *pawn) {
    return (abs(bishop[0] - pawn[0]) == abs(bishop[1] - pawn[1]) && bishop[0] - pawn[0] != 0);
}
