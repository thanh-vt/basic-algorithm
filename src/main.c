#include <common-utility.h>
#include <main.h>

ExDemoFuncPtr basicAlgorithmsMapper(int selection);

int main() {
    processMenu(ARITHMETIC_MENU_PATH, basicAlgorithmsMapper);
    return 0;
}

ExDemoFuncPtr basicAlgorithmsMapper(const int selection) {
    switch (selection) {
        case 1:
            return arithmeticModule;
        case 2:
            return stringHandlingModule;
        case 3:
            return countingModule;
        case 4:
            return matrixModule;
        case 5:
            return geometryModule;
        case 6:
            return numbersSequenceModule;
        case 7:
            return graphModule;
        case 8:
            return sortingModule;
        case 9:
            return searchingModule;
        default:
            return NULL;
    }
}

