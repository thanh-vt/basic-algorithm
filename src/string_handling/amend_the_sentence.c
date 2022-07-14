#include <stdlib.h>
#include <string.h>
#include <common_utility.h>
#include <common_string.h>

char* amendTheSentence(char *s);

void amendTheSentenceDemo() {
    printf("Enter a sentence:\n");
    arr_char* sentence = scanString();
    char *result = amendTheSentence(sentence->arr);
    printf("Result: %s\n", result);
    free(result);
    deleteString(sentence);
}

char* amendTheSentence(char *s) {
    char *newS = calloc(2 * strlen(s) + 1, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (i != 0) {
                newS[j] = ' ';
                j++;
            }
            newS[j] = (char) (s[i] + 32);
            j++;
        } else {
            newS[j] = (char) s[i];
            j++;
        }
    }
    return newS;
}