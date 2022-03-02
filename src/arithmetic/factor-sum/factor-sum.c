#include <stdio.h>
#include <lib/c-commons/common-utility.h>

int factorSum(int n);

int solve(int n);

void factorSumDemo() {
    printf("Enter a number to find its factor sum:\n");
    int x = scanInt();
    int result = factorSum(x);
    printf("Factor sum of %d is %d\n", x, result);
}

int factorSum(int n) {
    while (n != solve(n)) {
        n = solve(n);
    }
    return n;
}

int solve(int n) {
    int sum = 0;
    int i = 2;
    while (i <= n) {
        if (n % i == 0) {
            sum += i;
            n /= i;
        } else {
            i++;
        }
    }
    return sum;
}