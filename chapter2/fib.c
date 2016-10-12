//
// Created by 董启宏 on 2016/10/12.
//

#include "fib.h"

long fib(int N) {
    if (N <= 1) {
        return 1;
    }
    return fib(N-1) + fib(N-2);
}
