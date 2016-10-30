//
// Created by aaron on 10/19/16.
//

#include <stdio.h>
#include "polynomial.h"
#include "util.h"

void zeroPolynomial(Polynomial poly) {
    for (int i = 0; i < MAX_DEGREE; ++i) {
        poly->coeffArray[i] = 0;
    }

    poly->highPower = 0;
}

void addPolynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polySum) {
    zeroPolynomial(polySum);
    polySum->highPower = max(poly1->highPower, poly2->highPower);
    for (int i = polySum->highPower; i >= 0; i--) {
        polySum->coeffArray[i] = poly1->coeffArray[i] + poly2->coeffArray[i];
    }
}

void multiplyPolynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polyProd) {
    zeroPolynomial(polyProd);
    polyProd->highPower = poly1->highPower + poly2->highPower;
    if (polyProd->highPower > MAX_DEGREE) {
        perror("multiplyPolynomial()");
        return;
    } else {
        for (int i = 0; i < poly1->highPower; ++i) {
            for (int j = 0; j < poly2->highPower; ++j) {
                polyProd->coeffArray[i + j] += poly1->coeffArray[i] * poly2->coeffArray[j];
            }
        }
    }
}