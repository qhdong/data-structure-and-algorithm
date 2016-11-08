//
// Created by aaron on 16-11-8.
//

#include <malloc.h>
#include "hashtable_quad.h"
#include "prime.h"

HashTable initializeTable(unsigned int tableSize) {
    HashTable H = malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        printf("Error, out of space!\n");
        return NULL;
    }
    H->tableSize = nextPrime(tableSize);
    H->theCells = malloc(sizeof(struct HashEntry) * H->tableSize);
    if (H->theCells == NULL) {
        printf("Error, out of space!\n");
        return NULL;
    }
    for (int i = 0; i < H->tableSize; ++i) {
        H->theCells[i].info = Empty;
    }

    return H;
}

void destroyTable(HashTable H) {
    if (H != NULL) {
        if (H->theCells != NULL) {
            free(H->theCells);
        }
        free(H);
    }
}

static Index hash(ElementType key, unsigned int tableSize) {
    return key % tableSize;
}

Position find(ElementType Key, HashTable H) {
    Position currentPos = hash(Key, H->tableSize);
    int collisionNum = 0;
    while (H->theCells[currentPos].info != Empty
            && H->theCells[currentPos].element != Key) {
        currentPos += 2 * ++collisionNum + 1;
        if (currentPos >= H->tableSize) {
            currentPos -= H->tableSize;
        }
    }
    return currentPos;
}

void insert(ElementType Key, HashTable H) {
    Position pos = find(Key, H);
    if (H->theCells[pos].info != Legitimate) {
        H->theCells[pos].element = Key;
        H->theCells[pos].info = Legitimate;
    }
}

ElementType retrive(Position P, HashTable H) {
    if (H != NULL) {
        return H->theCells[P].element;
    }
    return -1;
}

HashTable rehash(HashTable H) {
    unsigned int oldSize = H->tableSize;
    Cell *oldCells = H->theCells;
    H = initializeTable(2 * oldSize);
    for (int i = 0; i < oldSize; ++i) {
        if (oldCells[i].info == Legitimate) {
            insert(oldCells[i].element, H);
        }
    }
    free(oldCells);
    return H;
}