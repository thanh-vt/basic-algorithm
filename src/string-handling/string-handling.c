#include <lib/c-commons/common-utility.h>
#include <string-handling.h>

ExDemoFuncPtr stringHandlingModuleMapper(int selection);

void stringHandlingModule() {
    processMenu("string-handling.menu.txt", stringHandlingModuleMapper);
}

ExDemoFuncPtr stringHandlingModuleMapper(const int selection) {
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
