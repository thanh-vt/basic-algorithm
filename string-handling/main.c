#include <common-utility.h>
#include "main.h"

ExDemoFuncPtr mapSelection(int selection);

int main() {
    processMenu("string-handling.menu.txt", mapSelection);
    return 0;
}

ExDemoFuncPtr mapSelection(const int selection) {
    switch (selection) {
        case 1:
            return checkStrongPasswordDemo;
        case 2:
            return amendTheSentenceDemo;
        case 3:
            return checkPalindromeDemo;
        case 4:
            return formatStringDemo;
        case 5:
            return isTandemRepeatDemo;
        case 6:
            return truncateStringDemo;
        case 7:
            return stringsCrossoverDemo;
        case 8:
            return questionCorrectionDemo;
        case 9:
            return lineEncodingDemo;
        default:
            return NULL;
    }
}
