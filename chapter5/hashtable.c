//
// Created by aaron on 16-11-5.
//

#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "prime.h"

struct ListNode {
    ElementType element;
    Node next;
};

struct HashTbl {
    int tableSize;
    List *theLists;
};

static void printError(char* func, char* s) {
    fprintf(stderr, "%s: %s\n", func, s);
}

int hash(int key, int tableSize) {
    return key % tableSize;
}


HashTable initializeTable(int tableSize) {
    HashTable hashTable = malloc(sizeof(struct HashTbl));
    if (hashTable == NULL) {
        printError("initializeTable","out of space!");
        return NULL;
    }
    hashTable->tableSize = nextPrime(tableSize);
    hashTable->theLists = malloc(hashTable->tableSize * sizeof(List));
    if (hashTable->theLists == NULL) {
        printError("initializeTable","out of space!");
        return NULL;
    }

    for (int i = 0; i < hashTable->tableSize; ++i) {
        hashTable->theLists[i] = malloc(sizeof(struct ListNode));
        if (hashTable->theLists[i] == NULL) {
            printError("initializeTable","out of space!");
            return NULL;
        } else {
            hashTable->theLists[i]->next = NULL;
        }

    }

    return hashTable;
}

void destroyTable(HashTable hashTable) {
    for (int i = 0; i < hashTable->tableSize; ++i) {
        destroyList(hashTable->theLists[i]);
    }
    free(hashTable);
}

Position find(ElementType X, HashTable hashTable) {
    List L = hashTable->theLists[hash(X, hashTable->tableSize)];
    Position P = L->next;
    while (P != NULL && P->element != X) {
        P = P->next;
    }
    return P;
}

void insert(ElementType X, HashTable hashTable) {
    if (find(X, hashTable) == NULL) {
        List L = hashTable->theLists[hash(X, hashTable->tableSize)];
        Node tmp = malloc(sizeof(struct ListNode));
        tmp->element = X;
        tmp->next = L->next;
        L->next = tmp;
    }
}

ElementType retrive(Position P) {
    if (P != NULL) return P->element;
    else return -1;
}

static void destroyList(List L) {
    Position P;
    while (L != NULL) {
        P = L;
        L = L->next;
        free(P);
    }
}

int tableSize(HashTable hashTable) {
    if (hashTable != NULL) {
        return hashTable->tableSize;
    }
    return 0;
}