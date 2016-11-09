//
// Created by aaron on 16-11-9.
//

#include <stdbool.h>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_BINARY_HEAP_H
#define DATA_STRUCTURE_AND_ALGORITHM_BINARY_HEAP_H

typedef int ElementType;

struct HeapStruct {
    int capacity;
    int size;
    ElementType *elements;
};

typedef struct HeapStruct* PriorityQueue;

PriorityQueue initialize(int maxElements);
void destroy(PriorityQueue H);
void makeEmpty(PriorityQueue H);
void insert(ElementType X, PriorityQueue H);
ElementType deleteMin(PriorityQueue H);
ElementType findMin(PriorityQueue H);
bool isEmpty(PriorityQueue H);
bool isFull(PriorityQueue H);
#endif //DATA_STRUCTURE_AND_ALGORITHM_BINARY_HEAP_H
