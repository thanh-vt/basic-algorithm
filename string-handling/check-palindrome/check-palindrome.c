#include <string.h>
#include <common-utility.h>

int checkPalindrome(char *inputString);

void checkPalindromeDemo() {
    char inputString[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a string:\n");
        scanString(inputString);
        if (checkPalindrome(inputString)) {
            printf("Your string is a palindrome string!\n");
        } else {
            printf("Your string is not a palindrome string!\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int checkPalindrome(char *inputString) {
    int isPalindrome = 1;
    unsigned long long strLength = strlen(inputString);
    for (int i = 0; i < strLength; ++i) {
        if (inputString[i] != inputString[strLength - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    return isPalindrome;
}
