#include <lib/c-commons/common-utility.h>
#include <geometry.h>

ExDemoFuncPtr geometryModuleMapper(int selection);

void geometryModule() {
    processMenu("geometry.menu.txt", geometryModuleMapper);
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

