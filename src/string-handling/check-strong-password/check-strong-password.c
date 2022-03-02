#include <string.h>
#include <common-utility.h>
#include <common-string.h>

#define PSWD_MIN_LENGTH 6

int checkStrongPassword(char *password);

void checkStrongPasswordDemo() {
    printf("Enter password:\n");
    arr_char* password = scanString();
    printf("Password: %s",  password->arr);
    if (checkStrongPassword(password->arr)) {
        printf("Your password is a strong password!\n");
    } else {
        printf("Your password is a weak password!\n");
    }
    deleteString(password);
}

int checkStrongPassword(char *password) {
    int hasSpecialChar = 0;
    int hasNumericChar = 0;
    int hasLowercaseChar = 0;
    int hasUppercaseChar = 0;
    int isMinLengthReached = 0;
    for (int i = 0; i < strlen(password); ++i) {
        char character = password[i];
        if (isSpecialCharacter(character)) {
            hasSpecialChar++;
        }
        if (isDigit(character)) {
            hasNumericChar++;
        }
        if (isLowercaseCharacter(character)) {
            hasLowercaseChar++;
        }
        if (isUppercaseCharacter(character)) {
            hasUppercaseChar++;
        }
        if (strlen(password) >= PSWD_MIN_LENGTH) {
            isMinLengthReached++;
        }
    }
    return hasSpecialChar && hasLowercaseChar && hasUppercaseChar && isMinLengthReached;
}


