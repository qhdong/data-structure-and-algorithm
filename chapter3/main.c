//
// Created by aaron on 10/18/16.
//

#include <stdio.h>
#include "linkedlist.h"

int main(void) {
    int arr[] = {1, 2, 3, 4 ,5};
    List list = fromArray(arr, 5);
    printList(list);

    Position P = find(3, list);
    insert(0, list, P);
    printList(list);

    delete(1, list);
    printList(list);

    delete(-1, list);
    printList(list);

    deleteList(list);
}