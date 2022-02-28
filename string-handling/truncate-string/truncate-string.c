#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

char* truncateString(char* s);

void truncateStringDemo() {
    char input[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(input);
        char *result = truncateString(input);
        printf("Result: %s\n", result);
        free(result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

char* truncateString(char* s) {
    int leftIndex = 0;
    int rightIndex = (int) strlen(s) - 1;
    int isCheck = 1;
    while (isCheck && leftIndex <= rightIndex) {
        isCheck = 0;
        if (s[leftIndex] % 3 == 0) {
            leftIndex++;
            isCheck = 1;
        } else if (s[rightIndex] % 3 == 0) {
            rightIndex--;
            isCheck = 1;
        } else if ((s[leftIndex] + s[rightIndex]) % 3 == 0) {
            leftIndex++;
            rightIndex--;
            isCheck = 1;
        }
    }
    int size = rightIndex - leftIndex + 1;
    char* newS = calloc(size + 1, sizeof(char));
    strncpy(newS, s + leftIndex, size);
    newS[size + 1] = TERMINATOR;
    return newS;
}