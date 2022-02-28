#include <common-utility.h>
#include <common-string.h>
#include "main.h"

#define EXIT_CODE 0

void mapSelection(int selection);

int main() {
    int command;
    arr_char *menu = readMenu("sorting.menu.txt");
    do {
        printf("%s", menu->arr);
        command = scanInt();
        mapSelection(command);
    } while (command != EXIT_CODE);
    deleteString(menu);
}

void mapSelection(const int selection) {
    switch (selection) {
        case 1:
            sortArrayDemo();
            break;
        case 2:
        default:
            break;
    }
}

