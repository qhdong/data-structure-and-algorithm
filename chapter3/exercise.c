//
// Created by aaron on 10/30/16.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void printLots(List L, List P) {
    int counter = 1;
    Position l = first(L);
    Position p = first(P);
    while(l != NULL && p != NULL) {
        if (p->element == counter++) {
            printf("%d, ", l->element);
            p = advance(p);
        }
        l = advance(l);
    }
}

void swapWithNext(Position beforeP, List L) {
    Position P = beforeP->next;
    Position afterP = P->next;
    beforeP->next = afterP;
    P->next = afterP->next;
    afterP->next = P;
}

void main(void) {
    int arrL[] = {1, 2, 4, 5, 7};
    List L = fromArray(arrL, 5);
    printList(L);

    int arrP[] = {1, 2, 3, 7, 9};
    List P = fromArray(arrP, 5);
    printList(P);

//    printLots(L, P);

//    Position p2 = find(2, L);
//    swapWithNext(p2, L);
//    printList(L);

    List L12 = intersect(L, P);
    printList(L12);

    List UnionList = Union(L, P);

    printList(UnionList);

    deleteList(L);
    deleteList(P);
    deleteList(L12);
    deleteList(UnionList);
}