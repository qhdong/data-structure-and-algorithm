//
// Created by aaron on 10/25/16.
//

#include <stdbool.h>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ARRAYSTACK_H
#define DATA_STRUCTURE_AND_ALGORITHM_ARRAYSTACK_H
struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

bool isEmpty(Stack S);
bool isFull(Stack S);
Stack createStack(int maxElements);
void disposeStack(Stack S);
void makeEmpty(Stack S);
void push(ElementType X, Stack S);
ElementType peek(Stack S);
void pop(Stack S);
ElementType peekAndPop(Stack S);
#endif //DATA_STRUCTURE_AND_ALGORITHM_ARRAYSTACK_H
