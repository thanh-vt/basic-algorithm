#include <stdio.h>
#include <common-utility.h>
#include <common-string.h>
#include "main.h"
#define EXIT_CODE 0

void mapSelection(int selection);

int main() {
    int command;
    arr_char* menu = readMenu("string-handling.menu.txt");
    do {
        printf("%s", menu->arr);
        command = scanInt();
        mapSelection(command);
    } while (command != EXIT_CODE);
    deleteString(menu);
}

void mapSelection(const int selection) {
    switch (selection) {
        case 1:
            checkStrongPasswordDemo();
            break;
        case 2:
            amendTheSentenceDemo();
            break;
        case 3:
            checkPalindromeDemo();
            break;
        case 4:
            formatStringDemo();
            break;
        case 5:
            isTandemRepeatDemo();
            break;
        case 6:
            truncateStringDemo();
            break;
        case 7:
            stringsCrossoverDemo();
            break;
        case 8:
            questionCorrectionDemo();
            break;
        case 9:
            lineEncodingDemo();
            break;
        default:
            break;
    }
}
