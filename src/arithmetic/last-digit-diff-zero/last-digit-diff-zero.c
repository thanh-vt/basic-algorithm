#include <lib/c-commons/common-utility.h>

int lastDigitDiffZero(int n);

void lastDigitDiffZeroDemo() {
    printf("Enter number:\n");
    int x = scanInt();
    int result = lastDigitDiffZero(x);
    printf("The last digit which of %d is different from 0 is %d:\n", x, result);
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