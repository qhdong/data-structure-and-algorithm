//
// Created by 董启宏 on 2016/10/12.
//

#include <stdbool.h>
#include "binary_search.h"

int BinarySearch(const int A[], int N, int X) {
    int low = 0;
    int high = N-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (X > A[mid]) {
            low = mid + 1;
        } else if (X < A[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int BinarySearchAi(const int A[], int N) {
    int low = 0;
    int high = N-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == A[mid]) {
            return mid;
        } else if (mid > A[mid]) {
            low  = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}