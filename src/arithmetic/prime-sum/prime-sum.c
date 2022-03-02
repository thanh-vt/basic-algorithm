#include <stdlib.h>
#include <lib/c-commons/common-utility.h>
#define MOD 22082018

char* isCompositeNumberArr;

int primeSum(int n);

void eratosthenes(int n);

void primeSumDemo() {
    printf("Enter number to count primes sum:\n");
    int x = scanInt();
    isCompositeNumberArr = calloc(x, sizeof(char));
    int result = primeSum(x);
    printf("Primes sum of %d: %d\n", x, result);
    free(isCompositeNumberArr);
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
