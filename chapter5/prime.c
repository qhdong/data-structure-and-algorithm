//
// Created by aaron on 16-11-5.
//

#include "prime.h"

bool isPrime(size_t x) {
    for (size_t i = 3; true; i += 2) {
        size_t q = x / i;
        if (q < i) return true;
        if (x == q * i) return false;
    }
    return true;
}

size_t nextPrime(size_t x) {
    if (x <= 2) return 2;
    if (!(x & 1)) x++;
    while (!isPrime(x)) {
        x += 2;
    }
    return x;
}