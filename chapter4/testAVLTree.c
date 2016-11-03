//
// Created by aaron on 16-11-3.
//

#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main(void) {
    const int N = 16;
    AvlTree T = makeEmpty(NULL);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    for (int i = 0; i < N; ++i) {
        T = insert(a[i], T);
    }
    postorderTraversal(T);
    printf("\n");
    printf("min: %d, max: %d\n", retrive(findMin(T)), retrive(findMax(T)));
    printf("find(3) == %d\n", retrive(find(19, T)));
}