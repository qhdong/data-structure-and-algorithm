//
// Created by aaron on 10/25/16.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedstack.h"

struct Node {
    PtrToNode next;
    ElementType element;
};

bool isEmpty(Stack S) {
    return S->next == NULL ? true : false;
}

Stack createStack(void) {
    Stack S = malloc(sizeof(struct Node));
    if (S == NULL) {
        perror("createStack()");
        return NULL;
    }

    S->next = NULL;
    makeEmpty(S);
    return S;
}

void disposeStack(Stack S) {
    makeEmpty(S);
    free(S);
}

void makeEmpty(Stack S) {
    while (!isEmpty(S)) {
        pop(S);
    }
}

void push(ElementType X, Stack S) {
    PtrToNode tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        perror("push()");
        return;
    }
    tmp->element = X;
    tmp->next = S->next;
    S->next = tmp;
}

ElementType peek(Stack S) {
    if (isEmpty(S)) {
        fprintf(stderr, "Error! Empty Stack!\n");
        return -1;
    }
    return S->next->element;
}

void pop(Stack S) {
    if (isEmpty(S)) {
        fprintf(stderr, "Error! Empty Stack!\n");
        return;
    }
    PtrToNode tmp = S->next;
    S->next = S->next->next;
    free(tmp);
}