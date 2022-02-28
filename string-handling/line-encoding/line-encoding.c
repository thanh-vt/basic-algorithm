#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

char* lineEncoding(char* s);

void convertToCharCount(char *newS, int count, char character);

char* convertNumToChar(int number);

int countDigits(int n);

void lineEncodingDemo() {
    char input[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(input);
        char *result = lineEncoding(input);
        printf("Result: %s\n", result);
        free(result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

char* lineEncoding(char* s) {
    unsigned long long strLength = strlen(s);
    char* newS = calloc(strLength, sizeof(char));
    int markForReplace = 0;
    int count = 0;
    char character = 0;
    for (int i = 0; i < strLength; ++i) {
        if (s[i] == character) {
            count++;
        } else if (i == 0) {

        } else {
            markForReplace = 1;
        }
        if (markForReplace) {
            convertToCharCount(newS, count, character);
            markForReplace = 0;
            count = 0;
        }
        character = s[i];
        if (i == strLength - 1) {
            markForReplace = 1;
        }
    }
    // last
    if (markForReplace) {
        convertToCharCount(newS, count, character);
    }
    return newS;
}

void convertToCharCount(char *newS, int count, char character) {
    char* charCount = convertNumToChar(count + 1);
    strcat(newS, charCount);
    free(charCount);
    char tmp[] = {character, TERMINATOR};
    strcat(newS, tmp);
}

char* convertNumToChar(int number) {
    if (number == 1) {
        char* numStr = calloc(1, sizeof(char));
        return numStr;
    }
    int digitCount = countDigits(number);
    char* numStr = calloc(digitCount, sizeof(char));
//    itoa(number, numStr, 10);
    sprintf(numStr, "%d", number);
    return numStr;
}

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        ++count;
    }
    return count;
}






