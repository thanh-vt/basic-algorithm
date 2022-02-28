#include <stdio.h>
#include <common-utility.h>

int digitsProduct(int product);

void digitsProductDemo() {
    int x;
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter a number to find its digits product:\n");
        x = scanInt();
        int result = digitsProduct(x);
        printf("Digits product of %d is %d\n", x, result);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == 10);
    printf("<<< End <<<\n\n\n");
}

int digitsProduct(int product) {
    if (product == 1) return -1;
    if (product == 0) return 10;
    int ans = 0;
    for (int i = 9; i >= 2; i--){
        while(product % i == 0){
            ans = ans * 10 + i;
            product /= i;
        }
    }
    int ans2 = 0;
    while (ans > 0) {
        ans2 = ans2 * 10 + ans % 10;
        ans /= 10;
    }
    return ans2;
}
