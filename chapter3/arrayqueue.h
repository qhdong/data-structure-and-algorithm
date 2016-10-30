//
// Created by aaron on 10/25/16.
//

#include <stdbool.h>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ARRAYQUEUE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ARRAYQUEUE_H
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

bool isEmpty(Queue Q);
bool isFull(Queue Q);
Queue createQueue(int maxElements);
void disposeQueue(Queue Q);
void makeEmpty(Queue Q);
void enqueue(ElementType X, Queue Q);
ElementType front(Queue Q);
void dequeue(Queue Q);
ElementType frontAndDequeue(Queue Q);
#endif //DATA_STRUCTURE_AND_ALGORITHM_ARRAYQUEUE_H
