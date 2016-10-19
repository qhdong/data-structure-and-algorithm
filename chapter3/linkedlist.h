//
// Created by aaron on 10/19/16.
//

#include <stdbool.h>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

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

#endif //DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
