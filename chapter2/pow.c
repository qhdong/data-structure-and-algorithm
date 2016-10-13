//
// Created by aaron on 10/13/16.
//

#include "pow.h"
#include "util.h"

long pow(long X, unsigned long N) {
    if (N == 0) {
        return 1;
    } else if (N == 1) {
        return X;
    } else if (isEven(N)) {
        return pow(X * X, N / 2);
    } else {
        return pow(X, N-1) * X;
    }
}


