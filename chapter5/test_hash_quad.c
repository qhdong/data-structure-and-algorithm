//
// Created by aaron on 16-11-8.
//

#include <stdio.h>
#include "hashtable_quad.h"

int main(void) {
    const unsigned int tableSize = 10;
    HashTable H = initializeTable(tableSize);
    for (int i = 0; i < 6; ++i) {
        insert(i*i, H);
    }

    H = rehash(H);

    for (int j = 0; j < 6; ++j) {
        printf("%d, ", retrive(find(j*j, H), H));
    }
    destroyTable(H);
}
