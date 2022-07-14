#include <stdlib.h>
#include <string.h>
#include <common_utility.h>
#include <common_string.h>

int isTandemRepeat(char* inputString);

void isTandemRepeatDemo() {
    printf("Enter a string:\n");
    arr_char* string = scanString();
    if (isTandemRepeat(string->arr)) {
        printf("Your string is a tandem string!\n");
    } else {
        printf("Your string is not a tandem string!\n");
    }
    deleteString(string);
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