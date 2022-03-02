#include <string.h>
#include <lib/c-commons/common-utility.h>
#include <lib/c-commons/common-string.h>

int stringsCrossover(arr_string inputArray, char *result);

int check(const char *a, const char *b, const char *c);

void stringsCrossoverDemo() {
    printf("Enter length of strings array:\n");
    int length = scanInt();
    arr_string* inputArr = scanStringArr(length);
    printf("Enter merged string:\n");
    arr_char* mergedString = scanString();
    int result = stringsCrossover(*inputArr, mergedString->arr);
    freeStringArr(inputArr);
    printf("Result: %d\n", result);
    deleteString(mergedString);
}

int stringsCrossover(arr_string inputArray, char *result) {
    int count = 0;
    for (int i = 0; i < inputArray.size; ++i) {
        for (int j = i + 1; j < inputArray.size; ++j) {
            if (check(inputArray.arr[i], inputArray.arr[j], result)) {
                count++;
            }
        }
    }
    return count;
}

int check(const char *a, const char *b, const char *c) {
    for (int i = 0; i < strlen(c); i++) {
        if (a[i] != c[i] && b[i] != c[i])
            return 0;
    }
    return 1;
}

