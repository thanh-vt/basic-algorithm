#include <stdlib.h>
#include <common-utility.h>

int differentValuesInMultiplicationTable2(int n, int m);

void differentValuesInMultiplicationTable2Demo() {
    int n1, n2, result;
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter first number:\n");
        n1 = scanInt();
        printf("Enter second number:\n");
        n2 = scanInt();
        result = differentValuesInMultiplicationTable2(n1, n2);
        printf("Common character count of the 2 given strings: %d!\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int differentValuesInMultiplicationTable2(int n, int m) {
    int result = 0;
    int* arr = calloc(n * m + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i * j] = 1;
        }
    }
    for (int i = 1; i <= m * n; i++) {
        result += arr[i];
    }
    free(arr);
    return result;
}