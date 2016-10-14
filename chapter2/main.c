//
// Created by 董启宏 on 2016/10/12.
//
// 算法的威力！真的是厉害了！

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MaxSubsequenceSum.h"
#include "util.h"
#include "fib.h"
#include "binary_search.h"
#include "gcd.h"
#include "pow.h"
#include "permutation.h"
#include "horner.h"
#include "prime.h"

void testMaxSubsequence() {
    printTestHeader("Test MaxSubsequence");
    const int N = 1000;
    int* A = getSequence(N);


    printf("O(N^3): %d\n", MaxSubsequenceSum_ON3(A, N));
    printf("O(N^2): %d\n", MaxSubsequenceSum_ON2(A, N));
    printf("O(NLogN): %d\n", MaxSubsequenceSum_ONLogN(A, N));
    printf("O(N): %d\n", MaxSubsequenceSum_ON(A, N));

    free(A);
}

void testFib() {
    printTestHeader("Test Fib");

    const int N = 20;
    for (int i = 0; i < N; ++i) {
        printf("Fib(%d) = %ld\n", i, fib(i));
    }
}

void testBinarySearch() {
    printTestHeader("Test BinarySearch");

    const int N = 20;
    int* A = getLinearSequence(N);

    int n = rand() % N;
    printArray(A, N);
    printf("Find A[%d] = %d in A\n", n, A[n]);
    printf("BinarySearch(%d) = %d\n", A[n], BinarySearch(A, N, A[n]));

    free(A);
}

void testBinarySearchAi() {
    printTestHeader("Test BinarySearchAi");

    const int N = 7;
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    printArray(A, N);
    printf("BinarySearchAi: %d\n", BinarySearchAi(A, N));

}

void testGCD() {
    printTestHeader("Test GCD");

    const unsigned M = (unsigned) rand();
    const unsigned N = (unsigned) rand();
    printf("GCD(%u, %u) = %u\n", M, N, gcd(M, N));
}

void testPow() {
    printTestHeader("Test Pow");
    long X = 2;
    unsigned long N = 11;
//    Pow(2, 4);
    for (unsigned long i = 0; i < N; i++) {
        printf("Pow(%ld, %lu) = %lu\n", X, i, Pow(X, i));
        printf("PowRecursion(%ld, %lu) = %lu\n", X, i, PowRecursion(X, i));
        if (Pow(X, i) != PowRecursion(X, i)) {
            printf("Break! Pow");
        }
    }
}

void testGetRand() {
    printTestHeader("Test randInt");

    int N = 10;
    for (int i = 0; i < N; ++i) {
        printf("randInt(1, %d) = %d\n", N, randInt(1, N));
    }
}

void testSwap(int a, int b) {
    printTestHeader("Test Swap");

    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

void testPermutation() {
    printTestHeader("Test getPermutation");

    const int N = 12000;
    printf("getPermutation(%d):\n", N);

//    int *A = getPermutation_ON2LogN(N);
//    int *A = getPermutation_ONLogN(N);
    int *A = getPermutation_ON(N);
    printArray(A, N);

    printf("Testing...\n");
    for (int i = 0; i < N; ++i) {
        if (! isContain(A, i+1, N)) {
            printf("Break! %d is missing\n", i+1);
        }
    }
    printf("OK!\n");

    free(A);
}

void testPolynomial() {
    printTestHeader("Test Polynomial");

    double X = 3;
    double A[] = {2, 1, 0, 8, 4};
    int N = 5;
    printf("polynomial(A, N=%d, X=%f) = %f\n", N, X, polynomial(A, N, X));
}

void testPrime() {
    printTestHeader("Test isPrime()");

    srand((unsigned int) time(0));
//    long N = rand();
    long N = 37;
    printf("isPrime(%ld) = %d\n", N, isPrime(N));
}

void testMSB() {
    printTestHeader("Test MostSignifictBit()");
    unsigned long N = 0xAA;
    printf("msb(0x%x) = %d\n", N, msb(N));
}

int main(void) {
//    testMaxSubsequence();
//    testBinarySearch();
//    testFib();
//    testGCD();
    testPow();
//    testGetRand();
//    testSwap(5, -1);
//    testPermutation();
//    testPolynomial();
//    testBinarySearchAi();
//    testPrime();
//    testMSB();
}

