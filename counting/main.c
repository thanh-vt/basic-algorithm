#include <common-utility.h>
#include <common-string.h>
#include "main.h"
#define EXIT_CODE 0

void mapSelection(int selection);

int main() {
    int command;
    arr_char *menu = readMenu("counting.menu.txt");
    do {
        printf("%s", menu->arr);
        command = scanInt();
        mapSelection(command);
    } while (command != EXIT_CODE);
    deleteString(menu);
    return 0;
}

void mapSelection(int selection) {
    switch (selection) {
        case 1:
            commonCharacterCountDemo();
            break;
        case 2:
            differentValuesInMultiplicationTable2Demo();
            break;
        case 3:
            checkEqualFrequencyDemo();
            break;
        case 4:
            differentSymbolsNaiveDemo();
            break;
        case 5:
            differentSubstringsTrieDemo();
            break;
        case 6:
            charactersRearrangementDemo();
            break;
        case 7:
            isPangramDemo();
            break;
        case 8:
            differentSquaresDemo();
            break;
        default:
            break;
    }
}
