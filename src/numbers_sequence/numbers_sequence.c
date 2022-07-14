#include <common_utility.h>
#include <numbers_sequence.h>
#include <main.h>

ExDemoFuncPtr numbersSequenceModuleMapper(int selection);

void numbersSequenceModule() {
    processMenu(NUMBERS_SEQUENCE_MENU_PATH, numbersSequenceModuleMapper);
}

ExDemoFuncPtr numbersSequenceModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return isMonotonousDemo;
        case 2:
            return isArithmeticProgressionDemo;
        case 3:
            return prefixSumsDemo;
        case 4:
            return alternatingSumsDemo;
        case 5:
            return makeArrayConsecutiveDemo;
        case 6:
            return longestSequenceDemo;
        default:
            return NULL;
    }
}

