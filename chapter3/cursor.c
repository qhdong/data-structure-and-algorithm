//
// Created by aaron on 10/19/16.
//

#include <stdio.h>
#include "cursor.h"

struct Node {
    ElementType element;
    Position next;
};

struct Node CursorSpace[SPACE_SIZE];

void initializeCursorSpace(void) {
    for (int i = 0; i < SPACE_SIZE-1; ++i) {
        CursorSpace[i].next = i+1;
    }
    CursorSpace[SPACE_SIZE-1].next = 0;
}

static Position cursorAlloc(void) {
    Position P = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[P].next;
    return P;
}

static void cursorFree(Position P) {
    CursorSpace[P].next = CursorSpace[0].next;
    CursorSpace[0].next = P;
}

int capacity(void) {
    int n = 0;
    Position P = CursorSpace[0].next;
    while (P != 0) {
        n++;
        P = CursorSpace[P].next;
    }
    return n;
}

bool isEmpty(const List L) {
    return CursorSpace[L].next == 0 ? true : false;
}

bool isLast(const Position P, const List L) {
    return CursorSpace[P].next == 0 ? true : false;
}

Position find(ElementType X, List L) {
    Position P = CursorSpace[L].next;
    while (P != 0 && CursorSpace[P].element != X) {
        P = CursorSpace[P].next;
    }
    return P;
}

Position findPrevious(ElementType X, List L) {
    Position P = L;
    while (CursorSpace[P].next != 0 && CursorSpace[CursorSpace[P].next].element != X) {
        P = CursorSpace[P].next;
    }
    return P;
}

void delete(ElementType X, List L) {
    Position P = findPrevious(X, L);
    if (!isLast(P, L)) {
        Position tmp = CursorSpace[P].next;
        CursorSpace[P].next = CursorSpace[tmp].next;
        cursorFree(tmp);
    }
}

void insert(ElementType X, List L, Position P) {
    Position tmp = cursorAlloc();
    if (tmp == 0) {
        fprintf(stderr, "insert(): Out of space!\n");
        return;
    }

    CursorSpace[tmp].element = X;
    CursorSpace[tmp].next = CursorSpace[P].next;
    CursorSpace[P].next = tmp;
}

void printList(List L) {
    if (isEmpty(L)) return;
    Position P = CursorSpace[L].next;
    while (P != 0 && CursorSpace[P].next != 0) {
        printf("%d->", CursorSpace[P].element);
        P = CursorSpace[P].next;
    }
    if (P != 0 && CursorSpace[P].next == 0) {
        printf("%d\n", CursorSpace[P].element);
    }
}

List fromArray(ElementType* A, size_t N) {
    List L = cursorAlloc();
    Position P = L;
    for (int i = 0; i < N; ++i) {
        insert(A[i], L, P);
        P = CursorSpace[P].next;
    }
    CursorSpace[P].next = 0;
    return L;
}

List makeEmpty(List L) {
    if (isEmpty(L)) return L;
    Position P = CursorSpace[L].next;
    Position tmp;
    while (P != 0) {
        tmp = P;
        P = CursorSpace[P].next;
        cursorFree(tmp);
    }
    return L;
}

void deleteList(List L) {
    List head = makeEmpty(L);
    cursorFree(head);
}