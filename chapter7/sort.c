//
// Created by aaron on 16-11-14.
//

#include "sort.h"

void InsertionSort(ElementType A[], size_t N) {
    for (int P = 1; P < N; ++P) {
        ElementType tmp = A[P];
        int i = P;
        while(i > 0 && A[i-1] > tmp) {
            A[i] = A[i-1];
            i--;
        }
        A[i] = tmp;
    }
}

void ShellSort(ElementType A[], size_t N) {
    int i, j, inc;
    ElementType tmp;
    for (inc = N / 2; inc > 0; inc /= 2) {
        for (i = inc; i < N; ++i) {
            tmp = A[i];
            for (j = i; j >= inc; j -= inc) {
                if (A[j-inc] > tmp) {
                    A[j] = A[j-inc];
                } else {
                    break;
                }
            }
            A[j] = tmp;
        }
    }
}

void BubbleSort(ElementType A[], size_t N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
            }
        }
    }
}

void SelectionSort(ElementType A[], size_t N) {
    for (int i = 0; i < N - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < N; ++j) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&A[i], &A[min]);
        }
    }
}

void swap(ElementType* a, ElementType *b) {
    ElementType tmp = *a;
    *a = *b;
    *b = tmp;
}

#define LeftChild(i) (2*(i) + 1)

static void PercDown(ElementType A[], int i, size_t N) {
    int child;
    ElementType tmp;
    for (tmp = A[i]; LeftChild(i) < N; i = child) {
        child = LeftChild(i);
        if (child != N-1 && A[child+1] > A[child]) {
            child++;
        }
        if (tmp < A[child]) {
            A[i] = A[child];
        } else {
            break;
        }
    }
    A[i] = tmp;
}

void HeapSort(ElementType A[], size_t N) {
    int i;

    for (i = N / 2; i >= 0; i--) {
        PercDown(A, i, N);
    }
    for (i = N-1; i > 0; i--) {
        swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}