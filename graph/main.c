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
            return findSquareSideDemo;
        case 2:
            return insideCircleDemo;
        case 3:
            return isRectangleDemo;
        case 4:
            return countTrianglesDemo;
        default:
            return NULL;
    }
}

