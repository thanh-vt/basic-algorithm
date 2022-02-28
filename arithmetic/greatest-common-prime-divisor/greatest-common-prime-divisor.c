#include <stdlib.h>
#include <common-utility.h>
#include <common-number.h>

char *compositeNumberArr;

int greatestCommonPrimeDivisor(int a, int b);

void markAllPrimes(int x);

void greatestCommonPrimeDivisorDemo() {
    int a, b, command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a:\n");
        a = scanInt();
        printf("Enter b:\n");
        b = scanInt();
        printf("The greatest common prime divisor of %d and %d is: %d\n", a, b, greatestCommonPrimeDivisor(a, b));
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int greatestCommonPrimeDivisor(int a, int b) {
    int min = minNum(a, b);
    compositeNumberArr = calloc(min + 1, sizeof(char));
    markAllPrimes(min);
    int iterator = 2;
    int result = -1;
    while (iterator <= min) {
        if (a % iterator == 0 && b % iterator == 0 && !compositeNumberArr[iterator]) {
            result = iterator;
        }
        iterator++;
    }
    free(compositeNumberArr);
    return result;
}

void markAllPrimes(int x) {
    int a = 2;
    while (a <= x) {
        int b = a;
        while (a * b <= x) {
            compositeNumberArr[a * b] = 1;
            b++;
        }
        a++;
        while (compositeNumberArr[a]) {
            a++;
        }
    }
}





