#include <stdlib.h>
#include <string.h>
#include <lib/c-commons/common-utility.h>
#include <lib/c-commons/common-string.h>

int charactersRearrangement(char* string1, char* string2);

void charactersRearrangementDemo() {
    printf("Enter the first string:\n");
    arr_char * string1 = scanString();
    printf("Enter the second string:\n");
    arr_char* string2 = scanString();
    if (charactersRearrangement(string1->arr, string2->arr)) {
        printf("The second string can be rearranged to match the first string!\n");
    } else {
        printf("The second string cannot be rearranged to match the first string!\n");
    }
    deleteString(string1);
    deleteString(string2);
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
