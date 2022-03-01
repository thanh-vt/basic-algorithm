#include <stdlib.h>
#include <common-utility.h>

void initFractionArr(int length, int* numeratorArr, int* denominatorArr);

int maxFraction(arr_int numerators, arr_int denominators);

int compareFraction(int a, int b, arr_int numerators, arr_int denominators);

void maxFractionDemo() {
    printf("Enter the number of fractions:\n");
    int length = scanInt();
    int* numeratorArr = calloc(length, sizeof(int));
    int* denominatorArr = calloc(length, sizeof(int));

    initFractionArr(length, numeratorArr, denominatorArr);

    arr_int numerators = { numeratorArr, length };
    arr_int denominators = { denominatorArr, length };

    int maxFractionIndex = maxFraction(numerators, denominators);

    printf("\nThe highest fraction is %d/%d at index %d\n",
           numerators.arr[maxFractionIndex], denominators.arr[maxFractionIndex], maxFractionIndex);

    free(numeratorArr);
    free(denominatorArr);
}

void initFractionArr(int length, int* numeratorArr, int* denominatorArr) {
    for (int i = 0; i < length; ++i) {
        printf("Enter the fractions #%d's numerator:\n", length);
        numeratorArr[i] = scanInt();
        printf("Enter the fractions #%d's denominator:\n", length);
        denominatorArr[i] = scanInt();
    }
}

int maxFraction(arr_int numerators, arr_int denominators) {
    if (numerators.size != denominators.size) {
        exit(1);
    }
    int maxFraction = 0;
    for (int i = 0; i < numerators.size; ++i) {
        if (i == numerators.size - 1) {
            printf("%d/%d", numerators.arr[i], denominators.arr[i]);
        } else {
            printf("%d/%d, ", numerators.arr[i], denominators.arr[i]);
        }
        if (compareFraction(i, maxFraction, numerators, denominators)) {
            maxFraction = i;
        }
    }
    return maxFraction;
}

//return 1 if a > b else 0
int compareFraction(int a, int b, arr_int numerators, arr_int denominators) {
    if (denominators.arr[a] == 0 || denominators.arr[b] == 0) {
        exit(1);
    }
    return ((numerators.arr[a] * denominators.arr[b] - denominators.arr[a] * numerators.arr[b]) * (denominators.arr[a] * denominators.arr[b])) > 0;
}






