#include <common-utility.h>
#include "main.h"

ExDemoFuncPtr mapSelection(int selection);

int main() {
    processMenu("searching.menu.txt", mapSelection);
    return 0;
}

ExDemoFuncPtr mapSelection(const int selection) {
    switch (selection) {
        default:
            return NULL;
    }
}

