#include <common-utility.h>
#include <geometry.h>
#include <main.h>

ExDemoFuncPtr geometryModuleMapper(int selection);

void geometryModule() {
    processMenu(GEOMETRY_MENU_PATH, geometryModuleMapper);
}

ExDemoFuncPtr geometryModuleMapper(const int selection) {
    switch (selection) {
        case 1:
            return findSquareSideDemo;
        case 2:
            return insideCircleDemo;
        case 3:
            return isRectangleDemo;
        case 4:
            return countTrianglesDemo;
        default:
            return NULL;
    }
}

