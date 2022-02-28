#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

int differentSymbolsNaive(char* s);

void differentSymbolsNaiveDemo() {
    char str[512];
    int command;
    int result;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(str);
        result = differentSymbolsNaive(str);
        printf("Number of different characters of the given string: %d!\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int differentSymbolsNaive(char* s) {
    char* arrFreq = calloc(128, sizeof(char));
    unsigned long long strLength = strlen(s);
    int count = 0;
    for (int i = 0; i < strLength; ++i) {
        arrFreq[s[i]]++;
        if (arrFreq[s[i]] == 1) {
            count++;
        }
    }
    free(arrFreq);
    return count;
}
