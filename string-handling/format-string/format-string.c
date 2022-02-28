#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

char* formatString(char *input);

void formatStringDemo() {
    char input[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(input);
        char *result = formatString(input);
        printf("Result: %s\n", result);
        free(result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

char* formatString(char *input) {
    unsigned long long strLength = strlen(input);
    char *newS = calloc(strLength, sizeof(char));
    int j = 0;
    int markSpace;
    int nonSpaceStart;
    for (int i = 0; i < strLength; ++i) {
        if (input[i] == SPACE) {
            markSpace++;
        } else {
            markSpace = 0;
            nonSpaceStart = 1;
        }
        if (markSpace > 1) {
            continue;
        } else if (nonSpaceStart) {
            newS[j] = input[i];
            j++;
        }
    }
    if (markSpace >= 1) {
        newS[j - 1] = TERMINATOR;
    } else {
        newS[j] = TERMINATOR;
    }
    return newS;
}