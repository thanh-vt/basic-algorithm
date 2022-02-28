#include <math.h>
#include <common-utility.h>

int pagesNumbering(int n);

int countNumberOfDigits(int n);

int countDigitsSumOfNumbersHavingXDigits(int x);

void pagesNumberingDemo() {
    int x, command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter the number of pages of the book:\n");
        x = scanInt();
        int result = pagesNumbering(x);
        printf("Total number can be used to numbering pages of the book: %d\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

int pagesNumbering(int n) {
    int digitsCount = countNumberOfDigits(n);
    int totalDigits = 0;
    for (int i = 1; i <= digitsCount; ++i) {
        if (i == digitsCount) {
            totalDigits += (n - (int) pow(10, i - 1) + 1) * i;
        } else {
            totalDigits += countDigitsSumOfNumbersHavingXDigits(i);
        }
    }
    return totalDigits;
}

int countNumberOfDigits(int n) {
    int counter = 0;
    while (n != 0) {
        n = n / 10;
        counter++;
    }
    return counter;
}

int countDigitsSumOfNumbersHavingXDigits(int x) {
    return x * (int) (pow(10, x) - pow(10, x - 1));
}


