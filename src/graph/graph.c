#include <common-utility.h>
#include <graph.h>
#include <main.h>

ExDemoFuncPtr graphModuleMapper(int selection);

void graphModule() {
    processMenu(GRAPH_MENU_PATH, graphModuleMapper);
}

ExDemoFuncPtr graphModuleMapper(const int selection) {
    switch (selection) {
        default:
            return NULL;
    }
}

