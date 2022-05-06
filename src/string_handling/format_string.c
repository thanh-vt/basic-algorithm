#include <stdlib.h>
#include <string.h>
#include <common-utility.h>
#include <common-string.h>

char* formatString(char *input);

void formatStringDemo() {
    printf("Enter a string:\n");
    arr_char* input = scanString();
    char *result = formatString(input->arr);
    printf("Result: %s\n", result);
    free(result);
    deleteString(input);
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