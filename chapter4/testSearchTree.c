//
// Created by aaron on 16-11-3.
//

#include <stdio.h>
#include "searchtree.h"

void main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SearchTree T = makeEmpty(NULL);
    for (int i = 0; i < 10; ++i) {
        T = insert(a[i], T);
    }
    delete(10, T);
    preorderTraversal(T);
    printf("\n");
    inorderTraversal(T);
    printf("\n");
    postorderTraversal(T);
}
