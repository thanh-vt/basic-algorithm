#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

char* amendTheSentence(char *s);

void amendTheSentenceDemo() {
    char sentence[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a sentence:\n");
        scanString(sentence);
        char *result = amendTheSentence(sentence);
        printf("Result: %s\n", result);
        free(result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
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