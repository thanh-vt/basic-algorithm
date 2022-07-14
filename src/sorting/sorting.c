#include <common_utility.h>
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
            return sortByHeightDemo;
        case 3:
            return sortByLengthDemo;
        case 4:
            return areSimilarDemo;
        case 5:
            return digitalSumSortDemo;
        default:
            return NULL;
    }
}

