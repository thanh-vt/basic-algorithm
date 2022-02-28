#include <stdio.h>
#include "main.h"
#include <common-utility.h>
#include <common-string.h>

#define EXIT_CODE 0

void mapSelection(int selection);

int main() {
    int command;
    arr_char* menu = readMenu("arithmetic.menu.txt");
    do {
        printf("%s", menu->arr);
        command = scanInt();
        mapSelection(command);
    } while (command != EXIT_CODE);
    deleteString(menu);
    return 0;
}

void mapSelection(const int selection) {
    switch (selection) {
        case 1:
            isPrimeDemo();
            break;
        case 2:
            factorSumDemo();
            break;
        case 3:
            greatestCommonPrimeDivisorDemo();
            break;
        case 4:
            maxFractionDemo();
            break;
        case 5:
            lastDigitDiffZeroDemo();
            break;
        case 6:
            digitsProductDemo();
            break;
        case 7:
            pagesNumberingDemo();
            break;
        case 8:
            primeSumDemo();
            break;
        case 9:
            numberZeroDigitsDemo();
            break;
        default:
            break;
    }
}

