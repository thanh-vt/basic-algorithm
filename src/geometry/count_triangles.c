#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <main.h>

void countTrianglesDemo() {
    printf("Enter number of points:\n");
    int size = scanInt();
    printf("Enter x array:\n");
    arr_int *x = scanIntArr(size);
    printf("Enter y array:\n");
    arr_int *y = scanIntArr(size);
    int result = countTriangles(*x, *y);
    printf("%d triangles can be created by those points.\n", result);
}

int countTriangles(arr_int x, arr_int y) {
    int count = 0;
    for (int i = 0; i < x.size; i++) {
        for (int j = i + 1; j < x.size; j++) {
            for (int k = j + 1; k < x.size; k++) {
                if ((x.arr[j] - x.arr[i]) * (y.arr[k] - y.arr[j]) != (y.arr[j] - y.arr[i]) * (x.arr[k] - x.arr[j]))
                    count++;
            }
        }
    }
    return count;
}