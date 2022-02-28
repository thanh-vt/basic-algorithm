#include <stdio.h>
#include <common-utility.h>

int factorSum(int n);

int solve(int n);

void factorSumDemo() {
    int command;
    int x;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a number to find its factor sum:\n");
        x = scanInt();
        int result = factorSum(x);
        printf("Factor sum of %d is %d\n", x, result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< END <<<\n");
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