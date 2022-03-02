#include <lib/c-commons/common-utility.h>
#include <graph.h>

ExDemoFuncPtr graphModuleMapper(int selection);

void graphModule() {
    processMenu("graph.menu.txt", graphModuleMapper);
}

ExDemoFuncPtr graphModuleMapper(const int selection) {
    switch (selection) {
        default:
            return NULL;
    }
}

