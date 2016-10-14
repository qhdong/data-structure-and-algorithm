//
// Created by aaron on 10/14/16.
//

#include "prime.h"
#include "util.h"


bool isPrime(long N) {
    if (N == 2) return true;
    if (isEven(N)) return false;

    for (int i = 3; i < N; i += 2) {
        if (N % i == 0) {
            return false;
        }
    }

    return true;
}