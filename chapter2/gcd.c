//
// Created by aaron on 10/13/16.
//

#include "gcd.h"

unsigned int gcd(unsigned int M, unsigned int N) {
    unsigned int rem = 0;
    while (N > 0) {
        rem = M % N;
        M = N;
        N = rem;
    }

    return M;
}