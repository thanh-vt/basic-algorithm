#include <common_array.h>
#include <util.h>

char BASIC_ALGORITHMS_MENU_PATH[] = "menu/basic-algorithms.menu.txt";

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

// Thuat toan sap xep vun dong
// Hàm vun đống cho một đỉnh
void heapify(arr_int arrInt, int n, int i) {  // mảng arr, n - số phần tử, i - đỉnh cần vun đống
    int max = i;    // Lưu vị trí đỉnh max ban đầu
    int l = i * 2 + 1;   // Vị trí con trái
    int r = l + 1;    // Vị trí con phải
    if (l < n && arrInt.arr[l] > arrInt.arr[max]) {   // Nếu tồn tại con trái lớn hơn cha, gán max = L
        max = l;
    }

    if (r < n && arrInt.arr[r] > arrInt.arr[max]) {   // Nếu tồn tại con phải lớn hơn arr[max], gán max = r
        max = r;
    }
    if (max != i) {      // Nếu max != i, tức là cha không phải lớn nhất
        swapInt(&arrInt.arr[i], &arrInt.arr[max]);   // Đổi chỗ cho phần tử lớn nhất làm cha
        heapify(arrInt, n, max);    // Đệ quy vun các node phía dưới
    }
}

// Ham sap xep vun dong
void heapSort(arr_int arrInt) {
    int n = arrInt.size;
    // vun dong tu duoi len len de thanh heap
    for (int i = n / 2 - 1; i >= 0; i--)   // i chạy từ n/2 - 1 về 0 sẽ có n/2 đỉnh nhé!
        heapify(arrInt, n, i);   // Vun từng đỉnh

    // Vòng lặp để thực hiện vun đống và lấy phần tử
    for (int j = n - 1; j > 0; j--) {   // chạy hết j == 1 sẽ dừng
        // mỗi lần j - 1, tương đương với k xét phần tử cuối
        swapInt(&(arrInt.arr[0]), &(arrInt.arr[j]));  // đổi chỗ phần tử lớn nhất
        heapify(arrInt, j, 0);    // vun lại đống,
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