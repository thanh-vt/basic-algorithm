#include <common-utility.h>
#include <sorting.h>

ExDemoFuncPtr sortingModuleMapper(int selection);

void sortingModule() {
    processMenu("sorting.menu.txt", sortingModuleMapper);
}

ExDemoFuncPtr sortingModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return sortArrayDemo;
        case 2:
        default:
            return NULL;
    }
}

