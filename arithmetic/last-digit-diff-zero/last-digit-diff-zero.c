#include <common-utility.h>

int lastDigitDiffZero(int n);

void lastDigitDiffZeroDemo() {
    int x, command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter number:\n");
        x = scanInt();
        int result = lastDigitDiffZero(x);
        printf("The last digit which of %d is different from 0 is %d:\n", x, result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< END <<<\n\n\n");
}

int lastDigitDiffZero(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
        while (res % 10 == 0) {
            res /= 10;
        }
        res = res % 100;
    }
    return res % 10;
}