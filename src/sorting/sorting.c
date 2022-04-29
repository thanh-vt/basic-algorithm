#include <common-utility.h>
#include <sorting.h>
#include <main.h>

ExDemoFuncPtr sortingModuleMapper(int selection);

void sortingModule() {
    processMenu(SORTING_MENU_PATH, sortingModuleMapper);
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

