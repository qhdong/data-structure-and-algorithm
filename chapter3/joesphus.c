//
// Created by aaron on 10/30/16.
//


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node* PtrToNode;
typedef PtrToNode Circle;


Circle makeCircle(int n) {
    Circle c = malloc(sizeof(struct Node));
    c->id = 1;
    PtrToNode p = c;
    for (int i = 2; i <= n ; ++i) {
        PtrToNode tmp = malloc(sizeof(struct Node));
        tmp->id = i;

        tmp->prev = p;
        p->next = tmp;

        p = p->next;
        if (i == n) {
            p->next = c;
            c->prev = p;
        }
    }
    return c;
}

void deleteNode(PtrToNode P) {
    P->prev->next = P->next;
    P->next->prev = P->prev;
    free(P);
}

void printCircle(Circle C) {
    PtrToNode pointer = C;
    do {
        printf("%d -> ", pointer->id);
        pointer = pointer->next;
    } while (pointer != C);
    printf("\n");
}

void joesphus(int m, int n) {
    if (n < 1) {
        fprintf(stderr, "n must >= 1\n");
        return;
    }
    m = m % n;
    Circle C = makeCircle(n);
    printCircle(C);

    while (n > 1) {
        for (int i = 0; i < m; ++i) {
            C = C->next;
        }
        printf("Player %d is out\n", C->id);
        PtrToNode P = C;
        C = C->next;
        deleteNode(P);

        printCircle(C);
        n--;
    }
}

void main(void) {
    joesphus(2, 41);
}
