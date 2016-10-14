//
// Created by 董启宏 on 2016/10/12.
//

#include <stdbool.h>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_UTIL_H
#define DATA_STRUCTURE_AND_ALGORITHM_UTIL_H

int* getSequence(int N);
int max3(int a, int b, int c);
int* getLinearSequence(int N);
void printArray(int A[], int N);
void printTestHeader(char* s);
bool isEven(long n);
bool isOdd(long n);
int randInt(int i, int j);
bool isContain(int* A, int X, int N);
void swap(int* a, int* b);
unsigned int msb(unsigned long N);
#endif //DATA_STRUCTURE_AND_ALGORITHM_UTIL_H
