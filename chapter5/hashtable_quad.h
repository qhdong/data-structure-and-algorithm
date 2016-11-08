//
// Created by aaron on 16-11-8.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_HASHTABLE_QUAD_H
#define DATA_STRUCTURE_AND_ALGORITHM_HASHTABLE_QUAD_H

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;

enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry {
    ElementType element;
    enum KindOfEntry info;
};
typedef struct HashEntry Cell;

struct HashTbl {
    unsigned int tableSize;
    Cell *theCells;
};
typedef struct HashTbl* HashTable;

HashTable initializeTable(unsigned int tableSize);
void destroyTable(HashTable H);
Position find(ElementType Key, HashTable H);
void insert(ElementType Key, HashTable H);
ElementType retrive(Position P, HashTable H);
HashTable rehash(HashTable H);


#endif //DATA_STRUCTURE_AND_ALGORITHM_HASHTABLE_QUAD_H
