//
// Created by aaron on 16-11-5.
//

#include <stdio.h>
#include "hashtable.h"

int main(void) {
    const int N = 100;
    HashTable hashTable = initializeTable(N);
    for (int i = 0; i < N; ++i) {
        insert(i*i, hashTable);
    }

    for (int j = 0; j < N; ++j) {
        int x = retrive(find(j*j, hashTable));
        printf("%4d,", x);
    }
    printf("\ntableSize = %d\n", tableSize(hashTable));
    destroyTable(hashTable);
    return 0;
}