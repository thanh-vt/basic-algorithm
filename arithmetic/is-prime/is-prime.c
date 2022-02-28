#include <common-utility.h>

int isPrime(int x);

void isPrimeDemo(void ) {
    int x, command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter number:\n");
        x = scanInt();
        int result = isPrime(x);
        if (result) {
            printf("%d is a prime:\n", x);
        } else {
            printf("%d is not a prime\n", x);
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
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


