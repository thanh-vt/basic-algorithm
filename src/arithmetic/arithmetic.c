#include <stdio.h>
#include <common-utility.h>
#include <arithmetic.h>
#include <main.h>

ExDemoFuncPtr arithmeticModuleMapper(int selection);

void arithmeticModule() {
    processMenu(ARITHMETIC_MENU_PATH, arithmeticModuleMapper);
}

ExDemoFuncPtr arithmeticModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return isPrimeDemo;
        case 2:
            return factorSumDemo;
        case 3:
            return greatestCommonPrimeDivisorDemo;
        case 4:
            return maxFractionDemo;
        case 5:
            return lastDigitDiffZeroDemo;
        case 6:
            return digitsProductDemo;
        case 7:
            return pagesNumberingDemo;
        case 8:
            return primeSumDemo;
        case 9:
            return numberZeroDigitsDemo;
        default:
            return NULL;
    }
}


