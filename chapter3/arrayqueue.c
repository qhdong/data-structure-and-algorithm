//
// Created by aaron on 10/25/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

bool isEmpty(Queue Q) {
    return Q->Size == 0;
}

bool isFull(Queue Q) {
    return Q->Size == Q->Capacity;
}

Queue createQueue(int maxElements) {
    Queue Q = malloc(sizeof(struct QueueRecord));
    Q->Capacity = maxElements;
    Q->Array = malloc(maxElements * sizeof(ElementType));
    makeEmpty(Q);
    return Q;
}

void disposeQueue(Queue Q) {
    free(Q->Array);
    free(Q);
}

void makeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int succ(int val, Queue Q) {
    if (++val == Q->Capacity) {
        val = 0;
    }
    return val;
}

void enqueue(ElementType X, Queue Q) {
    if (isFull(Q)) {
        fprintf(stderr, "Queue is full!\n");
        return;
    }
    Q->Size++;
    Q->Rear = succ(Q->Rear, Q);
    Q->Array[Q->Rear] = X;
}

ElementType front(Queue Q) {
    if (isEmpty(Q)) {
        fprintf(stderr, "Queue is empty!\n");
        return -1;
    }
    return Q->Array[Q->Front];
}

void dequeue(Queue Q) {
    if (isEmpty(Q)) {
        fprintf(stderr, "Queue is empty!\n");
        return;
    }
    Q->Size--;
    Q->Front = succ(Q->Front, Q);
}

ElementType frontAndDequeue(Queue Q) {
    if (isEmpty(Q)) {
        fprintf(stderr, "Queue is empty!\n");
        return -1;
    }
    Q->Size--;
    ElementType front = Q->Array[Q->Front];
    Q->Front = succ(Q->Front, Q);
    return front;
}