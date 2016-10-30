//
// Created by aaron on 10/25/16.
//

#include <stdlib.h>
#include <stdio.h>
#include "arraystack.h"
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord {
    int capacity;
    int topOfStack;
    ElementType *array;
};

bool isEmpty(Stack S) {
    return S->topOfStack == EmptyTOS;
}

bool isFull(Stack S) {
    return S->topOfStack == S->capacity-1;
}

Stack createStack(int maxElements) {
    Stack S = malloc(sizeof(struct StackRecord));
    S->capacity = maxElements;
    S->topOfStack = EmptyTOS;
    S->array = malloc(maxElements * sizeof(ElementType));
    return S;
}

void disposeStack(Stack S) {
    if (S != NULL) {
        free(S->array);
        free(S);
    }
}

void makeEmpty(Stack S) {
    S->topOfStack = EmptyTOS;
}

void push(ElementType X, Stack S) {
    if (!isFull(S)) {
        S->array[S->topOfStack+1] = X;
        S->topOfStack++;
    }
}

ElementType peek(Stack S) {
    if (isEmpty(S)) {
        fprintf(stderr, "Empty Stack!");
        return EmptyTOS;
    }
    return S->array[S->topOfStack];
}

void pop(Stack S) {
    if (isEmpty(S)) {
        fprintf(stderr, "Empty Stack!");
        return;
    }
    S->topOfStack--;
}

ElementType peekAndPop(Stack S) {
    if (isEmpty(S)) {
        fprintf(stderr, "Empty Stack!");
        return EmptyTOS;
    }
    return S->array[S->topOfStack--];
}