#include <common-utility.h>
#include <numbers-sequence.h>

ExDemoFuncPtr numbersSequenceModuleMapper(int selection);

void numbersSequenceModule() {
    processMenu("numbers-sequence.menu.txt", numbersSequenceModuleMapper);
}

ExDemoFuncPtr numbersSequenceModuleMapper(const int selection) {
    switch (selection) {
        default:
            return NULL;
    }
}

