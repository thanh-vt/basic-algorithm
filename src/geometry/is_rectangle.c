#include <common_matrix.h>
#include <stdio.h>
#include <main.h>

typedef struct GeoVector {
    int x, y;
} geo_vector;

int isTwoVectorsPerpendicular(geo_vector* vt1, geo_vector* vt2);

void isRectangleDemo() {
    printf("Enter coordinates of 4 points:\n");
    matrix_int* points = scanIntMatrix(4, 2);
    int result = isRectangle(*points);
    printf("Those points can%s form a rectangle.\n", result ? "" : "'t");
}

int isRectangle(matrix_int points) {
    // 4 points A, B, C, D
    geo_vector vtAB = {.x = (points.arr[1].arr[0] - points.arr[0].arr[0]), .y = (points.arr[1].arr[1] - points.arr[0].arr[1])};
    geo_vector vtBC = {.x = (points.arr[2].arr[0] - points.arr[1].arr[0]), .y = (points.arr[2].arr[1] - points.arr[1].arr[1])};
    geo_vector vtCD = {.x = (points.arr[3].arr[0] - points.arr[2].arr[0]), .y = (points.arr[3].arr[1] - points.arr[2].arr[1])};
    geo_vector vtDA = {.x = (points.arr[0].arr[0] - points.arr[3].arr[0]), .y = (points.arr[0].arr[1] - points.arr[3].arr[1])};

    if (!isTwoVectorsPerpendicular(&vtAB, &vtBC)) {
        return 0;
    }
    if (!isTwoVectorsPerpendicular(&vtBC, &vtCD)) {
        return 0;
    }
    if (!isTwoVectorsPerpendicular(&vtCD, &vtDA)) {
        return 0;
    }
    if (!isTwoVectorsPerpendicular(&vtDA, &vtAB)) {
        return 0;
    }
    return 1;
}

int isTwoVectorsPerpendicular(geo_vector* vt1, geo_vector* vt2) {
    return (vt1->x * vt2->x + vt1->y * vt2->y) == 0;
}
