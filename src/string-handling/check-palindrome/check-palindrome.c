#include <string.h>
#include <lib/c-commons/common-utility.h>
#include <lib/c-commons/common-string.h>

int checkPalindrome(char *inputString);

void checkPalindromeDemo() {
    printf("Enter a string:\n");
    arr_char* inputString = scanString();
    if (checkPalindrome(inputString->arr)) {
        printf("Your string is a palindrome string!\n");
    } else {
        printf("Your string is not a palindrome string!\n");
    }
    deleteString(inputString);
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
