#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

/*
 * dùng vòng lặp đếm số chuỗi có độ dài 1, 2, ..., n ký tự
 */

int differentSubstringsTrie(char* inputString);

void differentSubstringsTrieDemo() {
    char str[512];
    int command;
    int result;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(str);
        result = differentSubstringsTrie(str);
        printf("Number of different substrings of the given string: %d!\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int differentSubstringsTrie(char* inputString) {
    int result = 0;
    unsigned long long totalSubStr;
    unsigned long long totalSpace;
    unsigned long long totalMem;
    char* wholeString = calloc(1, sizeof(char));
    char* tmpStr = calloc(1, sizeof(char));
    for (int length = 1; length <= strlen(inputString); ++length) {
        totalSubStr = strlen(inputString) - length + 1;
        totalSpace = totalSubStr + 1;
        totalMem = totalSubStr * length + totalSpace + 1;
        wholeString = realloc(wholeString, totalMem);
        memset(wholeString, 0, totalMem);
        for (int i = 0; i < totalSubStr; ++i) {
            tmpStr = realloc(tmpStr, (length + 3) * sizeof(char));
            memset(tmpStr, 0, (length + 3) * sizeof(char));
            strcat(tmpStr, "_");
            strncat(tmpStr, inputString + i, length);
            strcat(tmpStr, "_");
            if (i == 0) {
                strcat(wholeString, "_");
                strncat(wholeString, inputString + i, length);
                strcat(wholeString, "_");
                result++;
            }
            if (strstr(wholeString, tmpStr)) {
                continue;
            } else {
                strncat(wholeString, inputString + i, length);
                strcat(wholeString, "_");
                result++;
            }
        }
    }
    free(tmpStr);
    free(wholeString);
    return result;
}

