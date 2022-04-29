#include <common-utility.h>
#include <counting.h>
#include <main.h>

ExDemoFuncPtr countingModuleMapper(int selection);

void countingModule() {
    processMenu(COUNTING_MENU_PATH, countingModuleMapper);
}

ExDemoFuncPtr countingModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return commonCharacterCountDemo;
        case 2:
            return differentValuesInMultiplicationTable2Demo;
        case 3:
            return checkEqualFrequencyDemo;
        case 4:
            return differentSymbolsNaiveDemo;
        case 5:
            return differentSubstringsTrieDemo;
        case 6:
            return charactersRearrangementDemo;
        case 7:
            return isPangramDemo;
        case 8:
            return differentSquaresDemo;
        default:
            return NULL;
    }
}
