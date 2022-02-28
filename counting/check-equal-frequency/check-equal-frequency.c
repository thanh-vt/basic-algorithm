#include <stdlib.h>
#include <math.h>
#include <common-utility.h>

int checkEqualFrequency(arr_int inputArray);

void checkEqualFrequencyDemo() {
    int arrLength;
    arr_int* arrInt;
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter array length:\n");
        arrLength = scanInt();
        arrInt = scanIntArr(arrLength);
        if (checkEqualFrequency(*arrInt)) {
            printf("All element frequencies are equal!\n");
        } else {
            printf("All element frequencies are not equal!\n");
        }
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    freeIntArr(arrInt);
    printf("<<< End <<<\n\n\n");
}

int checkEqualFrequency(arr_int inputArray) {
    int* arrFreq = calloc( (unsigned long long) (4 * pow(10, 8)), sizeof(int));
    for (int i = 0; i < inputArray.size; ++i) {
        arrFreq[inputArray.arr[i]]++;
    }
    int isEqual = 1;
    int startCount = 0;
    for (int j = 0; j < inputArray.size; ++j) {
        if (startCount && arrFreq[inputArray.arr[j]] != startCount) {
            isEqual = 0;
            break;
        }
        if (arrFreq[inputArray.arr[j]] > 0) {
            startCount = arrFreq[inputArray.arr[j]];
        }
    }
    free(arrFreq);
    return isEqual;
}