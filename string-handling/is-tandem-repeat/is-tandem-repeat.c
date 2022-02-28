#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

int isTandemRepeat(char* inputString);

void isTandemRepeatDemo() {
    char string[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(string);
        if (isTandemRepeat(string)) {
            printf("Your string is a tandem string!\n");
        } else {
            printf("Your string is not a tandem string!\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int isTandemRepeat(char* inputString) {
    unsigned long long strLength = strlen(inputString);
    if (strLength % 2 == 1) {
        return 0;
    }
    char* firstSubStr = calloc(strLength / 2, sizeof(char));
    char* secondSubStr = calloc(strLength / 2, sizeof(char));
    strncpy(firstSubStr, inputString, strLength / 2);
    strncpy(secondSubStr, inputString + strLength / 2, strLength / 2);
    int isTandem = strcmp(firstSubStr, secondSubStr);
    free(firstSubStr);
    free(secondSubStr);
    return !isTandem;
}