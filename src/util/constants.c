#include <common-array.h>
#include <util.h>

char ARITHMETIC_MENU_PATH[] = "menu/arithmetic.menu.txt";

char COUNTING_MENU_PATH[] = "menu/counting.menu.txt";

char GEOMETRY_MENU_PATH[] = "menu/geometry.menu.txt";

char GRAPH_MENU_PATH[] = "menu/graph.menu.txt";

char MATRIX_MENU_PATH[] = "menu/matrix.menu.txt";

char NUMBERS_SEQUENCE_MENU_PATH[] = "menu/numbers-sequence.menu.txt";

char SEARCHING_MENU_PATH[] = "menu/searching.menu.txt";

char SORTING_MENU_PATH[] = "menu/sorting.menu.txt";

char STRING_HANDLING_MENU_PATH[] = "menu/string-handling.menu.txt";

int compareIntArr(arr_int arrInt1, arr_int arrInt2) {
    if (arrInt1.size != arrInt2.size) return 0;
    for (int i = 0; i < arrInt1.size; ++i) {
        if (arrInt1.arr[i] != arrInt2.arr[i]) return 0;
    }
    return 1;
}

void selectionSort(arr_int arrInt) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < arrInt.size - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < arrInt.size; j++)
            if (arrInt.arr[j] < arrInt.arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swapInt(&(arrInt.arr[min_idx]), &(arrInt.arr[i]));
    }
}

void swapString(char **bishop1_ptr, char **bishop2_ptr) {
    char *temp = *bishop1_ptr;
    *bishop1_ptr = *bishop2_ptr;
    *bishop2_ptr = temp;
}

void swapInt(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}