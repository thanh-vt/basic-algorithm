#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

int charactersRearrangement(char* string1, char* string2);

void charactersRearrangementDemo() {
    char string1[512];
    char string2[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter the first string:\n");
        scanString(string1);
        printf("Enter the second string:\n");
        scanString(string2);
        if (charactersRearrangement(string1, string2)) {
            printf("The second string can be rearranged to match the first string!\n");
        } else {
            printf("The second string cannot be rearranged to match the first string!\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int charactersRearrangement(char* string1, char* string2) {
    char* string1FreqArr = calloc(128, sizeof(char));
    char* string2FreqArr = calloc(128, sizeof(char));
    int rearrangeable = 1;
    for (int i = 0; i < strlen(string1); ++i) {
        string1FreqArr[string1[i]]++;
    }
    for (int i = 0; i < strlen(string2); ++i) {
        string2FreqArr[string2[i]]++;
    }
    for (int i = 0; i < 128; ++i) {
        if (string1FreqArr[i] != string2FreqArr[i]) {
            rearrangeable = 0;
            break;
        }
    }
    free(string1FreqArr);
    free(string2FreqArr);
    return rearrangeable;
}
