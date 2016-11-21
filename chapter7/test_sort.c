//
// Created by aaron on 16-11-14.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "sort.h"

int* getSequence(int N) {
    const int MAX = 100;
    srand((unsigned int) time(0));
    int* A = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        A[i] = rand() % MAX;
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

int main(void) {
    const size_t N = 30;
    int* A = getSequence(N);

    printArray(A, N);
//    InsertionSort(A, N);
//    ShellSort(A, N);
//    BubbleSort(A, N);
//    SelectionSort(A, N);
//    HeapSort(A, N);
//    MergeSort(A, N);
    QuickSort(A, N);
    printArray(A, N);


}