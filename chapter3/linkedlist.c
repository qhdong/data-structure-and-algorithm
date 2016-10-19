//
// Created by aaron on 10/19/16.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

struct Node {
    ElementType element;
    Position next;
};

bool isLast(Position P, List L) {
    return P->next == NULL ? true : false;
}

bool isEmpty(List L) {
    return L->next == NULL ? true : false;
}

void makeEmpty(List L) {
    Position P = L->next;
    Position tmp;
    L->next = NULL;
    while (P != NULL) {
        tmp = P->next;
        free(P);
        P = tmp;
    }
}

void deleteList(List L) {
    makeEmpty(L);
    free(L);
}

/*
 * 如果找不到X，则返回NULL
 */
Position find(ElementType X, List L) {
    Position P = L->next;
    while (P != NULL && P->element != X) {
        P = P->next;
    }
    return P;
}

/*
 * 寻找X的前一个元素，如果找不到，则返回最后一个元素
 */
Position findPrevious(ElementType X, List L) {
    Position P = L;
    while (P->next != NULL && P->next->element != X) {
        P = P->next;
    }
    return P;
}

void insert(ElementType X, List L, Position P) {
    Position tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL) {
        perror("insert()");
        return;
    }
    tmpCell->element = X;
    tmpCell->next = P->next;
    P->next = tmpCell;
}

void delete(ElementType X, List L) {
    Position P = findPrevious(X, L);
    Position tmpCell;
    if (!isLast(P, L)) {
        tmpCell = P->next;
        P->next = tmpCell->next;
        free(tmpCell);
    }
}

void printList(List L) {
    if (isEmpty(L)) return;
    Position P = L->next;
    while (P != NULL && P->next != NULL) {
        printf("%d -> ", P->element);
        P = P->next;
    }
    if (P != NULL && P->next == NULL) {
        printf("%d\n", P->element);
    }
}

List fromArray(ElementType* A, size_t N) {
    List L = malloc(sizeof(struct Node));
    Position P = L;
    for (int i = 0; i < N; ++i) {
        insert(A[i], L, P);
        P = P->next;
    }
    return L;
}