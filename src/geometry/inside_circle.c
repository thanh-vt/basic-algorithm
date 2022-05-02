#include <common-array.h>
#include <math.h>
#include <stdio.h>
#include <common-utility.h>

int insideCircle(arr_int point, arr_int center, int radius);

void insideCircleDemo() {
    printf("Enter circle radius:\n");
    int radius = scanInt();
    printf("Enter x, y dimension of the point:\n");
    arr_int* xyPoint = scanIntArr(2);
    printf("Enter x, y dimension of the circle center:\n");
    arr_int* xyCenter = scanIntArr(2);
    int isInside = insideCircle(*xyPoint, *xyCenter, radius);
    if (isInside) {
        printf("The point is inside the given circle\n");
    } else {
        printf("The point is outside the given circle\n");
    }
    freeIntArr(xyPoint);
    freeIntArr(xyCenter);
}

int insideCircle(arr_int point, arr_int center, int radius) {
    int sqr_dist = pow(center.arr[0] - point.arr[0], 2) + pow(center.arr[1] - point.arr[1], 2);
    // binh phuong dist(A, C)
    int powRadius = pow(radius, 2);
    if (sqr_dist <= powRadius) {
        return 1; // trong hinh tron
    } else {
        return 0; // ngoai hinh tron
    }
}
