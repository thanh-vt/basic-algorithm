#include <common-utility.h>
#include <searching.h>
#include <main.h>

ExDemoFuncPtr searchingModuleMapper(int selection);

void searchingModule() {
    processMenu(SEARCHING_MENU_PATH, searchingModuleMapper);
}

ExDemoFuncPtr searchingModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return searchElementDemo;
        case 2:
            return searchElement02Demo;
        case 3:
            return countPlaceDemo;
        case 4:
            return beautifulArrayDemo;
        case 5:
            return missingValueDemo;
        default:
            return NULL;
    }
}

