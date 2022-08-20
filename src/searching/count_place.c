#include <common_array.h>
#include <stdio.h>
#include <common_utility.h>
#include <searching.h>

void countPlaceDemo() {
    printf("Enter number of buildings:\n");
    int numberOfBuildings = scanInt();
    printf("Enter building distance from start array:\n");
    arr_int *arrInt = scanIntArr(numberOfBuildings);
    printf("Array:\n");
    printIntArr(arrInt);
    printf("\n");
    printf("Enter maximum distance for a wireless router to take effect:\n");
    int effectiveDistance = scanInt();
    int result = countPlace(*arrInt, effectiveDistance);
    printf("Minimum number of wireless routers to setup is %d.\n", result);
    printf("Press ENTER to continue, or any other key to get back to the main menu:\n");
    freeIntArr(arrInt);
}

int countPlace(arr_int a, int k) {
    int count = 0;
    int i = 0;
    while (i < a.size) {
        int ht = i;
        if (ht == a.size - 1) {
            count++;
            break;
        }
        int vt = i + 1;
        while (vt < a.size && a.arr[vt] - a.arr[ht] <= k) {
            vt++;
        }
        if (vt < a.size) {
            i = vt - 1;
            int j = i + 1;
            while (j < a.size && a.arr[j] - a.arr[i] <= k) {
                j++;
            }
            i = j;
            count++;
        } else {
            count++;
            break;
        }
    }
    return count;
}