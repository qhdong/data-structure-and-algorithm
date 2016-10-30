//
// Created by aaron on 10/19/16.
//

#include <stdbool.h>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CURSOR_H
#define DATA_STRUCTURE_AND_ALGORITHM_CURSOR_H

#define SPACE_SIZE 13

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;



void initializeCursorSpace(void);
static Position cursorAlloc(void);
static void cursorFree(Position P);
int capacity(void);

List makeEmpty(List L);
void deleteList(List L);
bool isEmpty(const List L);
bool isLast(const Position P, const List L);
Position find(ElementType X, List L);
Position findPrevious(ElementType X, List L);
void delete(ElementType X, List L);
void insert(ElementType X, List L, Position P);
void printList(List L);
List fromArray(ElementType* A, size_t N);


#endif //DATA_STRUCTURE_AND_ALGORITHM_CURSOR_H
