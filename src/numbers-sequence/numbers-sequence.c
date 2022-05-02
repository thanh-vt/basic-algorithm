#include <common-utility.h>
#include <numbers-sequence.h>
#include <main.h>

ExDemoFuncPtr numbersSequenceModuleMapper(int selection);

void numbersSequenceModule() {
    processMenu(NUMBERS_SEQUENCE_MENU_PATH, numbersSequenceModuleMapper);
}

ExDemoFuncPtr numbersSequenceModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            isMonotonousDemo();
            break;
        case 2:
            isArithmeticProgressionDemo();
            break;
        default:
            return NULL;
    }
}

