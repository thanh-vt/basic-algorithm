#include <common-utility.h>
#include <common-string.h>
#include "main.h"

#define EXIT_CODE 0

void mapSelection(int selection);

int main() {
    int command;
    arr_char *menu = readMenu("graph.menu.txt");
    do {
        printf("%s", menu->arr);
        command = scanInt();
        mapSelection(command);
    } while (command != EXIT_CODE);
    deleteString(menu);
}

void mapSelection(const int selection) {
    switch (selection) {
        default:
            break;
    }
}

