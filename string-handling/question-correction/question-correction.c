#include <stdlib.h>
#include <string.h>
#include <common-utility.h>
#include <common-string.h>

char* questionCorrection(char* s);

void replaceSpace(char* s, char* newS);

void replaceQuestionMark(char* s, char* newS);

void replaceComma(char* s, char* newS);

void replaceUppercase(char* s, char* newS);

void convertChar(char* character);

void questionCorrectionDemo() {
    char input[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a question:\n");
        scanString(input);
        char *result = questionCorrection(input);
        printf("Result: %s\n", result);
        free(result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

char* questionCorrection(char* s) {
    unsigned long long strLength = strlen(s) * 2;
    char *tempS1 = calloc(strLength, sizeof(char));
    replaceSpace(s, tempS1);
    printf("Replace space: %s\n", tempS1);
    char *tempS2 = calloc(strLength, sizeof(char));

    replaceQuestionMark(tempS1, tempS2);
    printf("Replace question mark: %s\n", tempS2);
    tempS1 = realloc(tempS1, strLength * sizeof(char));

    replaceComma(tempS2, tempS1);
    printf("Replace comma: %s\n", tempS1);
    tempS2 = realloc(tempS2, strLength * sizeof(char));

    replaceUppercase(tempS1, tempS2);
    printf("Replace uppercase: %s\n", tempS2);
    free(tempS1);
    return tempS2;
}

void replaceSpace(char* s, char* newS) {
    int markSpace = 0;
    int nonSpaceStart = 0;
    int j = 0;
    for (int i = 0; i < strlen(s); ++i) {
        convertChar(&s[i]);
        if (s[i] == SPACE) {
            markSpace++;
        } else {
            markSpace = 0;
            // mark first non-space character
            nonSpaceStart = 1;
        }
        if (markSpace > 1) {
            continue;
        } else if (nonSpaceStart) {
            // if this is the first non-space character, assign to the new string
            newS[j] = s[i];
            j++;
        }
    }
    if (markSpace >= 1) {
        newS[j - 1] = TERMINATOR;
    } else {
        newS[j] = TERMINATOR;
    }
}

void replaceQuestionMark(char* s, char* newS) {
    int j = 0;
    unsigned  long long strLength = strlen(s);
    for (int i = 0; i < strLength; ++i) {
        if (i != (strlen(s) - 1) && s[i] == QUESTION_MARK) {
            continue;
        }
        newS[j] = s[i];
        j++;
    }
    if (newS[j - 1 ] != QUESTION_MARK) {
        newS[j] = QUESTION_MARK;
        newS[j + 1] = TERMINATOR;
    } else {
        newS[j] = TERMINATOR;
    }
}

void replaceComma(char* s, char* newS) {
    unsigned long long strLength = strlen(s);
    int j = 0;
    int nonCommaStart = 0;
    int markCommaSpaceBlock = 0;
    int markForReplaceWithComma = 0;
    int markForReplaceEmpty = 0;
    int markForReplaceWithSpace = 0;
    int markForSpace = 0;
    for (int i = 0; i < strLength; ++i) {
        if (isWordOrDigit(s[i])) {
            nonCommaStart = 1;
        }
        if (!nonCommaStart) {
            continue;
        }
        if (s[i] == COMMA || s[i] == SPACE) {
            if (s[i] == SPACE) {
                markForSpace++;
            }
            markCommaSpaceBlock++;
        } else if (s[i] == QUESTION_MARK) {
            if (markCommaSpaceBlock > 0) {
                markForReplaceEmpty = 1;
                markCommaSpaceBlock = 0;
                markForSpace = 0;
            }
        } else {
            if (markCommaSpaceBlock > 0) {
                if (markForSpace != markCommaSpaceBlock) {
                    markForReplaceWithComma = 1;
                } else {
                    markForReplaceWithSpace = 1;
                }
                markCommaSpaceBlock = 0;
                markForSpace = 0;
            }
        }
        if (markForReplaceWithComma) {
            newS[j] = COMMA;
            j++;
            newS[j] = SPACE;
            j++;
            newS[j] = s[i];
            j++;
            markForReplaceWithComma = 0;
        } else if (markForReplaceEmpty) {
            newS[j] = s[i];
            j++;
            markForReplaceEmpty = 0;
        } else if (markForReplaceWithSpace) {
            newS[j] = SPACE;
            j++;
            newS[j] = s[i];
            j++;
            markForReplaceWithSpace = 0;
        } else {
            if (markCommaSpaceBlock == 0) {
                newS[j] = s[i];
                j++;
            }
        }
    }
    newS[j] = TERMINATOR;
}

void replaceUppercase(char* s, char* newS) {
    int j = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (isLowercaseCharacter(s[i]) && i == 0) {
            newS[j] = (char) (s[i] - 32);
        } else if (isUppercaseCharacter(s[i]) && i > 0) {
            newS[j] = (char) (s[i] + 32);
        } else {
            newS[j] = s[i];
        }
        j++;
    }
    newS[j] = TERMINATOR;
}

void convertChar(char* character) {
    if (isWordOrDigit(*character) && *character != COMMA && *character != SPACE && *character != QUESTION_MARK) {
    } else {
        *character = SPACE;
    }
}