#include <stdlib.h>
#include <common_utility.h>
#include <common_string.h>
#include <util.h>

arr_string bishopDiagonal(char *bishop1, char *bishop2);

void bishopDiagonalDemo() {
    printf("Enter bishop 1's cell:\n");
    arr_char* bishop1Cell = scanString();
    printf("Enter bishop 2's cell:\n");
    arr_char* bishop2Cell = scanString();
    arr_string result = bishopDiagonal(bishop1Cell->arr, bishop2Cell->arr);
    printf("Bishop 1 new position: %s\n", result.arr[0]);
    printf("Bishop 2 new position: %s\n", result.arr[1]);
    free(result.arr);
    deleteString(bishop1Cell);
    deleteString(bishop2Cell);
}

arr_string bishopDiagonal(char *bishop1, char *bishop2) {
    arr_string result;
    char **arr = (char **) malloc(2 * sizeof(char *));
    result.size = 2;
    result.arr = arr;
    result.arr[0] = bishop1;
    result.arr[1] = bishop2;
    if (arr[0][0] > arr[1][0]) swapString(&arr[0], &arr[1]); // sort by alphabet
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

