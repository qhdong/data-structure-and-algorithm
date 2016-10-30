//
// Created by aaron on 10/19/16.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node {
    ElementType element;
    Position next;
};

bool isLast(Position P, List L);
bool isEmpty(List L);
void makeEmpty(List L);
void deleteList(List L);
Position find(ElementType X, List L);
Position findPrevious(ElementType X, List L);
void insert(ElementType X, List L, Position P);
void delete(ElementType X, List L);
void printList(List L);
List fromArray(ElementType* A, size_t N);
Position header(List L);
Position first(List L);
Position advance(Position P);

List intersect(List L1, List L2);
List Union(List L1, List L2);
List reverseList(List L);

#endif //DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
