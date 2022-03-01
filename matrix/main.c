#include <common-utility.h>
#include "main.h"

ExDemoFuncPtr mapSelection(int selection);

int main() {
    processMenu("graph.menu.txt", mapSelection);
    return 0;
}

ExDemoFuncPtr mapSelection(const int selection) {
    switch (selection) {
        case 1:
            return checkBoardCellColorDemo;
        case 2:
            return bishopAndPawnDemo;
        case 3:
            return chessKnightDemo;
        case 4:
            return bishopDiagonalDemo;
        case 5:
            return spiralNumbersDemo;
        case 6:
            return sudokuCheckingDemo;
        case 7:
            return findPathDemo;
        default:
            return NULL;
    }
}

