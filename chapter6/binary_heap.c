//
// Created by aaron on 16-11-9.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "binary_heap.h"

PriorityQueue initialize(int maxElements) {
    PriorityQueue H = malloc(sizeof(struct HeapStruct));
    H->capacity = maxElements;
    H->elements = malloc(sizeof(ElementType) * (maxElements+1));
    H->elements[0] = INT_MIN;
    H->size = 0;
    return H;
}

void destroy(PriorityQueue H) {
    free(H->elements);
    free(H);
}

void makeEmpty(PriorityQueue H) {
    H->size = 0;
}

void insert(ElementType X, PriorityQueue H) {
    if (isFull(H)) {
        printf("Priority Queue is full\n");
        return;
    }
    int i;
    for (i = ++H->size; H->elements[i/2] > X; i /= 2) {
        H->elements[i] = H->elements[i/2];
    }
    H->elements[i] = X;
}

ElementType deleteMin(PriorityQueue H) {
    if (isEmpty(H)) {
        printf("Priority Queue is empty!\n");
        return H->elements[0];
    }
    ElementType min = H->elements[1];
    ElementType last = H->elements[H->size--];
    int i, child;
    for (i = 1; 2*i <= H->size ; i = child) {
        child = 2*i;
        if (child != H->size && H->elements[child+1] < H->elements[child]) {
            child++;
        }
        if (last > H->elements[child]) {
            H->elements[i] = H->elements[child];
        } else {
            break;
        }
    }
    H->elements[i] = last;
    return min;

}

ElementType findMin(PriorityQueue H) {
    return H->elements[1];
}

bool isEmpty(PriorityQueue H) {
    return H->size == 0;
}

bool isFull(PriorityQueue H) {
    return H->size == H->capacity;
}