//
// Created by aaron on 10/30/16.
//

#include "linkedlist.h"
#include <stdio.h>

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    List list = fromArray(arr, 5);
    printList(list);

    List reverse = reverseList(list->next);
    printList(reverse);

    deleteList(list);
    return 0;
}