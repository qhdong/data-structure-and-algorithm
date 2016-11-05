//
// Created by aaron on 16-11-5.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_HASHMAP_H
#define DATA_STRUCTURE_AND_ALGORITHM_HASHMAP_H
struct ListNode;
typedef struct ListNode *Position;
typedef Position Node;
typedef Position List;

struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;

HashTable initializeTable(int tableSize);
void destroyTable(HashTable hashTable);
Position find(ElementType X, HashTable hashTable);
void insert(ElementType X, HashTable hashTable);
ElementType retrive(Position P);
int hash(int key, int tableSize);
static void destroyList(List L);
int tableSize(HashTable hashTable);
#endif //DATA_STRUCTURE_AND_ALGORITHM_HASHMAP_H
