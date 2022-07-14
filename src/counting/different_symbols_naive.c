#include <stdlib.h>
#include <string.h>
#include <common_utility.h>
#include <common_string.h>

int differentSymbolsNaive(char* s);

void differentSymbolsNaiveDemo() {
    printf("Enter a string:\n");
    arr_char* str = scanString();
    int result = differentSymbolsNaive(str->arr);
    printf("Number of different characters of the given string: %d!\n", result);
    deleteString(str);
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
