//
// Created by aaron on 16-11-10.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_LEFT_HEAP_H
#define DATA_STRUCTURE_AND_ALGORITHM_LEFT_HEAP_H

#include <stdbool.h>

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;
PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
bool isEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
#endif //DATA_STRUCTURE_AND_ALGORITHM_LEFT_HEAP_H
