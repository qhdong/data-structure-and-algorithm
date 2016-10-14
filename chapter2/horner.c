//
// Created by aaron on 10/14/16.
//

#include "horner.h"

double polynomial(double* A, int N, double X) {
    double poly = 0;
    for (int i = N-1; i >= 0; i--) {
        poly = poly * X + A[i];
    }
    return poly;
}