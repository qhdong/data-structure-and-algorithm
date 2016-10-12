//
// Created by 董启宏 on 2016/10/12.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

int max3(int a, int b, int c) {
    int temp = a > b ? a : b;
    return temp > c ? temp : c;
}

int* getSequence(int N) {
    const int MAX = 1000;
    srand((unsigned int) time(0));
    int* A = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        A[i] = (rand() - RAND_MAX / 2) % MAX;
    }
    return A;
}

int* getLinearSequence(int N) {
    const int MAX = 1000;
    srand((unsigned int) time(0));
    int* A = malloc(N * sizeof(int));
    int n = (rand() - RAND_MAX / 2) % MAX;
    int step = 1 + rand() % 10;
    for (int i = 0; i < N; ++i) {
        n += step;
        A[i] = n;
    }
    return A;
}

void printArray(int A[], int N) {
    const int LINE = 10;
    for (int i = 0; i < N; ++i) {
        if (i % LINE == 0) {
            printf("\n");
        }
        printf("%4d, ", A[i]);
    }
    printf("\n\n");
}

void printTestHeader(char* s) {
    printf("\n=====================================\n");
    printf("%s\n", s);
    printf("=====================================\n");
}