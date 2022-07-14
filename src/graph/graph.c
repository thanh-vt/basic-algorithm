#include <common_utility.h>
#include <graph.h>
#include <main.h>

ExDemoFuncPtr graphModuleMapper(int selection);

void graphModule() {
    processMenu(GRAPH_MENU_PATH, graphModuleMapper);
}

ExDemoFuncPtr graphModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return isTournamentDemo;
        case 2:
            return componentSizeDemo;
        case 3:
            return bfsDistancesUnweightedGraphDemo;
        default:
            return NULL;
    }
}

