//
// Created by aaron on 10/13/16.
//

#include <stdlib.h>
#include "pow.h"
#include "util.h"

long Pow(long X, unsigned long N) {
    unsigned int n = msb(N);
    long* powersOfX = malloc(n * sizeof(long));
    powersOfX[0] = X;
    for (int i = 1; i < n; ++i) {
        powersOfX[i] = powersOfX[i-1] * powersOfX[i-1];
    }

    long power = 1;
    int i = 0;
    while (N > 0) {
        if (N & 1) {
            power *= powersOfX[i];
        }
        N >>= 1;
        i++;
    }

    return power;
}

long PowRecursion(long X, unsigned long N) {
    if (N == 0) {
        return 1;
    } else if (N == 1) {
        return X;
    } else if (isEven(N)) {
        return Pow(X * X, N / 2);
    } else {
        return Pow(X, N - 1) * X;
    }
}

