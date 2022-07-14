#include <stdlib.h>
#include <string.h>
#include <common_utility.h>
#include <common_number.h>
#include <common_string.h>

int commonCharacterCount(char* s1, char* s2);

void commonCharacterCountDemo() {
    printf("Enter string 1:\n");
    arr_char* string1 = scanString();
    printf("Enter string 2:\n");
    arr_char* string2 = scanString();
    int result = commonCharacterCount(string1->arr, string2->arr);
    printf("Common character count of the 2 given strings: %d!\n", result);
    deleteString(string1);
    deleteString(string2);
}

int commonCharacterCount(char* s1, char* s2) {
    int result = 0;
    int* arr1 = calloc(128, sizeof(int));
    int* arr2 = calloc(128, sizeof(int));
    for (int i = 0; i < strlen(s1); ++i) {
        arr1[s1[i]]++;
    }
    for (int i = 0; i < strlen(s2); ++i) {
        arr2[s2[i]]++;
    }
    for (int i = 97; i <= 122; i++) {
        result += minNum(arr1[i], arr2[i]);
    }
    free(arr1);
    free(arr2);
    return result;
}