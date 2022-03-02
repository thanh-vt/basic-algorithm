#include <stdlib.h>
#include <string.h>
#include <common-utility.h>
#include <common-string.h>

char* truncateString(char* s);

void truncateStringDemo() {
    printf("Enter a string:\n");
    arr_char* input = scanString();
    char *result = truncateString(input->arr);
    printf("Result: %s\n", result);
    free(result);
    deleteString(input);
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