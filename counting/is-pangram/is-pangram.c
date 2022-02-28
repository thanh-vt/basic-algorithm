#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <common-utility.h>

int isPangram(char* sentence);

void isPangramDemo() {
    char sentence[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter the sentence:\n");
        scanString(sentence);
        if (isPangram(sentence)) {
            printf("The sentence is a pangram!\n");
        } else {
            printf("The sentence is not a pangram!\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int isPangram(char* sentence) {
    int isPangram = 1;
    char* freqArr = calloc(26, sizeof(char));
    for (int i = 0; i < strlen(sentence); ++i) {
        if (sentence[i] >= 65 && sentence[i] <= 90) {
            freqArr[sentence[i] + 32 - 97]++;
        }
        if (sentence[i] >= 97 && sentence[i] <= 122) {
            freqArr[sentence[i] - 97]++;
        }
    }
    for (int j = 97; j <= 122; ++j) {
        if (freqArr[j - 97] == 0) {
            printf("bug: %d", j - 97);
            isPangram = 0;
            break;
        }
    }
    free(freqArr);
    return isPangram;
}

