#include <common_array.h>
#include <stdio.h>
#include <math.h>

int findSquareSide(arr_int x, arr_int y);

void findSquareSideDemo() {
    printf("Enter x dimension array:\n");
    arr_int* xArrInt = scanIntArr(4);
    printf("Enter y dimension array:\n");
    arr_int* yArrInt = scanIntArr(4);
    int result = findSquareSide(*xArrInt, *yArrInt);
    printf("Area of the given square is: %d\n", result);
    freeIntArr(xArrInt);
    freeIntArr(yArrInt);
}

int findSquareSide(arr_int x, arr_int y) {
    // lấy tọa độ điểm đầu tiên làm gốc
    // so sánh các đường nối = so sánh bình phương các đường nối nên ko cần khai căn
    // tính đường nối 1 (^2)
    double c1, c2, c;
    c1 = pow(x.arr[1] - x.arr[0], 2);
    c2 = pow(y.arr[1] - y.arr[0], 2);
    c = ((c1 + c2));

    // tính đường nối 2 (^2)
    double c12, c22, c3;
    c12 = pow(x.arr[2] - x.arr[0], 2);
    c22 = pow(y.arr[2] - y.arr[0], 2);
    c3 = ((c12 + c22));

    // tính đường nối 3 (^2)
    double c122, c222, c32;
    c122 = pow(x.arr[3] - x.arr[0], 2);
    c222 = pow(y.arr[3] - y.arr[0], 2);
    c32 = ((c122 + c222));

    // diện tích = bình phương cạnh hình vuông
    if (c == c3) {
        // nếu đường nối 1 = đường nối 2 => đường nối 1 và 2 là 2 cạnh hình vuông
        return (int) c;
    } else {
        // nếu đường nối 1 và đường nối 2 khác nhau
        // => 1 đường nối là cạnh hình vuông và 1 đường nối là đường chéo
        // => đường nối còn lại là cạnh hình vuông
        return (int) c32;
    }
}

