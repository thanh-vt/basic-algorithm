#ifndef COMMON_FUNCTIONS_COMMON_STRING_H
#define COMMON_FUNCTIONS_COMMON_STRING_H

/*
 * String Utility
 */

int isUppercaseCharacter(char character);

int isLowercaseCharacter(char character);

int isDigit(char character);

int isWordOrDigit(char character);

int isSpecialCharacter(char character);

arr_char* createString();

void concatString(arr_char* aChar, char* characters);

void deleteString(arr_char* aChar);

#endif //COMMON_FUNCTIONS_COMMON_STRING_H
