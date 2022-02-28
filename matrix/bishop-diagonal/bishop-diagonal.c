#include <stdlib.h>
#include <common-utility.h>

arr_string bishopDiagonal(char *bishop1, char *bishop2);

void swap(char **bishop1_ptr, char **bishop2_ptr);

void bishopDiagonalDemo() {
    char bishop1Cell[512];
    char bishop2Cell[512];
    int command;
    printf(">>> Start >>>\n");
    do {
        printf("Enter bishop 1's cell:\n");
        scanString(bishop1Cell);
        printf("Enter bishop 2's cell:\n");
        scanString(bishop2Cell);
        arr_string result = bishopDiagonal(bishop1Cell, bishop2Cell);
        printf("Bishop 1 new position: %s\n", result.arr[0]);
        printf("Bishop 2 new position: %s\n", result.arr[1]);
        free(result.arr);
        printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
        command = getc(stdin);
    } while (command == NEWLINE);
    printf("<<< End <<<\n\n\n");
}

arr_string bishopDiagonal(char *bishop1, char *bishop2) {
    arr_string result;
    char **arr = (char **) malloc(2 * sizeof(char *));
    result.size = 2;
    result.arr = arr;
    result.arr[0] = bishop1;
    result.arr[1] = bishop2;
    if (arr[0][0] > arr[1][0]) swap(&arr[0], &arr[1]); // sort by alphabet
    if (abs(arr[0][0] - arr[1][0]) != abs(arr[0][1] - arr[1][1])) {
        return result;
    }
    if (arr[0][1] < arr[1][1]) {
        while (arr[0][0] != 'a' && arr[0][1] != '1') {
            arr[0][0]--;
            arr[0][1]--;
        }
        while (arr[1][0] != 'h' && arr[1][1] != '8') {
            arr[1][0]++;
            arr[1][1]++;
        }
        return result;
    } else {
        while (arr[0][0] != 'a' && arr[0][1] != '8') {
            arr[0][0]--;
            arr[0][1]++;
        }
        while (arr[1][0] != 'h' && arr[1][1] != '1') {
            arr[1][0]++;
            arr[1][1]--;
        }
        return result;
    }
}

void swap(char **bishop1_ptr, char **bishop2_ptr) {
    char *temp = *bishop1_ptr;
    *bishop1_ptr = *bishop2_ptr;
    *bishop2_ptr = temp;
}