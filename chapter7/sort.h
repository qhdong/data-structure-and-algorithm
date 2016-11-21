//
// Created by aaron on 16-11-14.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_SORT_H
#define DATA_STRUCTURE_AND_ALGORITHM_SORT_H

#include <stddef.h>

typedef int ElementType;
void swap(ElementType* a, ElementType *b);
void InsertionSort(ElementType A[], size_t N);
void ShellSort(ElementType A[], size_t N);
void BubbleSort(ElementType A[], size_t N);
void SelectionSort(ElementType A[], size_t N);
void HeapSort(ElementType A[], size_t N);
void MergeSort(ElementType A[], size_t N);
void QuickSort(ElementType A[], size_t N);
#endif //DATA_STRUCTURE_AND_ALGORITHM_SORT_H
