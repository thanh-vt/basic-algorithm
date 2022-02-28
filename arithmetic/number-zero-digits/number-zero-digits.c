#include <common-utility.h>

/*
 * Số chữ số 0 tận cùng = số lần chia hết cho 10
 * 10 = 2 x 5 , 2 và 5 nguyên tố cùng nhay => tìm min của số thừa số 2 và 5
 * từ 0 -> n số số chia hết cho 5 chắc chắn lớn hơn số số chia hết cho 2 => chỉ cần tìm số số chia hết cho 5
 */

long long numberZeroDigits(long long n);

void lastDigitDiffZero2(long long n, long long *x);

void numberZeroDigitsDemo() {
    int command;
    long long number;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a number:\n");
        number = scanLongLongInt();
        long long result = numberZeroDigits(number);
        printf("Number of digit zero is: %lld\n", result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command  == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

long long numberZeroDigits(long long n) {
    long long d = 0;
//    long long k = 5;
//    while (k <= n){
//        // n có dạng 5k + i trong đó k là số sô chia hết cho 5 trong khoảng từ 1 đến n
//        d += n / k;
//        // tiếp tục tìm số số chia hết cho 5^2, 5^3,...
//        k *= 5;
//    }
    lastDigitDiffZero2(n, &d);
    return d;
}

void lastDigitDiffZero2(long long n, long long *x) {
    long long res = 1;
    for (long long i = 2; i <= n; ++i) {
        res *= i;
        while (res % 10 == 0) {
            ++*x;
            res /= 10;
        }
//        res = res % 100;
    }
//    return res % 10;
}

