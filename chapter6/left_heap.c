//
// Created by aaron on 16-11-10.
//

#include <malloc.h>
#include "left_heap.h"

struct TreeNode {
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

PriorityQueue Initialize(void) {
    PriorityQueue H = malloc(sizeof(struct TreeNode));
    H->Left = NULL;
    H->Right = NULL;
    H->Npl = 0;
    return H;
}

ElementType FindMin(PriorityQueue H);
bool isEmpty(PriorityQueue H);

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) {
    if (H1->Left == NULL) {
        H1->Left = H2;
    } else {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl) {
            SwapChildren(H1);
        }
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
    if (H1 == NULL) {
        return H2;
    }
    if (H2 == NULL) {
        return H1;
    }
    if (H1->Element < H2->Element) {
        return Merge1(H1, H2);
    } else {
        return Merge1(H2, H1);
    }
}


PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);