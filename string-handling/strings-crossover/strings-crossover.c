#include <string.h>
#include <common-utility.h>

int stringsCrossover(arr_string inputArray, char *result);

int check(const char *a, const char *b, const char *c);

void stringsCrossoverDemo() {
    char mergedString[512];
    int length;
    int command;
    arr_string* inputArr;
    printf(">>> Start >>>\n");
    do {
        printf("Enter length of strings array:\n");
        length = scanInt();
        inputArr = scanStringArr(length);
        printf("Enter merged string:\n");
        scanString(mergedString);
        int result = stringsCrossover(*inputArr, mergedString);
        freeStringArr(inputArr);
        printf("Result: %d\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
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

