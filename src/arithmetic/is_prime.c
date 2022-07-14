#include <common_utility.h>
#include <arithmetic.h>

void isPrimeDemo(void) {
    printf("Enter a number to check:");
    int x = scanInt();
    int result = isPrime(x);
    if (result) {
        printf("%d is a prime!\n", x);
    } else {
        printf("%d is not a prime!\n", x);
    }
}

int isPrime(int x) {
    if (x == 2) return 1;
    if (x <= 1 || x % 2 == 0) {
        return 0;
    }
    int isPrime = 1;
    for (int i = 3; i < x; i += 2) {
        if (x % i == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}


