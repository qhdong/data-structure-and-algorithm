//
// Created by aaron on 10/25/16.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_LISTSTACK_H
#define DATA_STRUCTURE_AND_ALGORITHM_LISTSTACK_H

#include <stdbool.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

bool isEmpty(Stack S);
Stack createStack(void);
void disposeStack(Stack S);
void makeEmpty(Stack S);
void push(ElementType X, Stack S);
ElementType peek(Stack S);
void pop(Stack S);

#endif //DATA_STRUCTURE_AND_ALGORITHM_LISTSTACK_H
