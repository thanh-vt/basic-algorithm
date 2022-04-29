#include <common-utility.h>
#include <searching.h>
#include <main.h>

ExDemoFuncPtr searchingModuleMapper(int selection);

void searchingModule() {
    processMenu(SEARCHING_MENU_PATH, searchingModuleMapper);
}

ExDemoFuncPtr searchingModuleMapper(const int selection) {
    switch (selection) {
        default:
            return NULL;
    }
}

