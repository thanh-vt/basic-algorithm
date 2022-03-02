#include <lib/c-commons/common-utility.h>
#include <searching.h>

ExDemoFuncPtr searchingModuleMapper(int selection);

void searchingModule() {
    processMenu("searching.menu.txt", searchingModuleMapper);
}

ExDemoFuncPtr searchingModuleMapper(const int selection) {
    switch (selection) {
        default:
            return NULL;
    }
}

