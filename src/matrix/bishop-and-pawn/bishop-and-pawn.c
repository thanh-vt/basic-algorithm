#include <stdio.h>
#include <stdlib.h>
#include <lib/c-commons/common-utility.h>
#include <lib/c-commons/common-string.h>

int bishopAndPawn(char *bishop, char *pawn);

void bishopAndPawnDemo() {
    printf("Enter bishop's cell:\n");
    arr_char* bishopCell = scanString();
    printf("Enter pawn's cell:\n");
    arr_char* pawnCell = scanString();
    int result = bishopAndPawn(bishopCell->arr, pawnCell->arr);
    if (result) {
        printf("Bishop can eliminate pawn in 1 turn\n");
    } else {
        printf("Bishop cannot eliminate pawn in 1 turn\n");
    }
    deleteString(bishopCell);
    deleteString(pawnCell);
}

int bishopAndPawn(char *bishop, char *pawn) {
    return (abs(bishop[0] - pawn[0]) == abs(bishop[1] - pawn[1]) && bishop[0] - pawn[0] != 0);
}
