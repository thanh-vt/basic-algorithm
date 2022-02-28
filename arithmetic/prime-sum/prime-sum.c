#include <stdlib.h>
#include <common-utility.h>
#define MOD 22082018

char* isCompositeNumberArr;

int primeSum(int n);

void eratosthenes(int n);

void primeSumDemo() {
    int x, command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter number to primes sum:\n");
        x = scanInt();
        isCompositeNumberArr = calloc(x, sizeof(char));
        int result = primeSum(x);
        printf("Primes sum of %d: %d\n", x, result);
        free(isCompositeNumberArr);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int primeSum(int n) {
    eratosthenes(n);
    int d = 0;
    for (int i = 2; i <= n; i++)
        if (!isCompositeNumberArr[i]) d = (d + i % MOD) % MOD;
    return d;
}

void eratosthenes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isCompositeNumberArr[i]) continue;
        int j = i;
        while (i * j <= n) {
            isCompositeNumberArr[i * j] = 1;
            j++;
        }
    }
}
