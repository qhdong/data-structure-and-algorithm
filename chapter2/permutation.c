//
// Created by aaron on 10/13/16.
//

#include <stdlib.h>
#include <time.h>
#include "permutation.h"
#include "util.h"

int* getPermutation_ON2LogN(int N) {
    srand((unsigned int) time(0));

    int* A = malloc(N * sizeof(int));

    int i = 0;
    while (i < N) {
        int n = randInt(1, N);
        if (isContain(A, n, i)) {
            continue;
        } else {
            A[i++] = n;
        }
    }
    return A;
}

int* getPermutation_ONLogN(int N) {
    srand((unsigned int) time(0));

    int* A = malloc(N * sizeof(int));
    bool* used = malloc((N+1) * sizeof(bool));
    for (int j = 0; j < N + 1; ++j) {
        used[j] = false;
    }

    int i = 0;
    while (i < N) {
        int n = randInt(1, N);
        if (used[n]) continue;
        used[n] = true;
        A[i++] = n;
    }

    free(used);
    return A;
}

int* getPermutation_ON(int N) {
    srand((unsigned int) time(0));

    int* A = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        A[i] = i + 1;
    }

    for (int j = 1; j < N; ++j) {
        swap(&A[j], &A[randInt(0, j)]);
    }

    return A;
}
