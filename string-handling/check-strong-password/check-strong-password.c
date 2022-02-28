#include <string.h>
#include <stdlib.h>
#include <common-utility.h>
#define PSWD_MIN_LENGTH 6

int checkStrongPassword(char *password);

void checkStrongPasswordDemo() {
    char password[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter password:\n");
        scanString(password);
        printf("Password: %s",  password);
        if (checkStrongPassword(password)) {
            printf("Your password is a strong password!\n");
        } else {
            printf("Your password is a weak password!\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
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


