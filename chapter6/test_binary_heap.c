//
// Created by aaron on 16-11-9.
//
#include "binary_heap.h"
#include <stdio.h>

int main(void) {
    const int maxSize = 20;
    PriorityQueue H = initialize(maxSize);

    for (int i = 10; i > 0; i--) {
        insert(i, H);
    }

    for (int j = 0; j < 10; ++j) {
        printf("%d, ", deleteMin(H));
    }

    destroy(H);
}
