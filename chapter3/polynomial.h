//
// Created by aaron on 10/19/16.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_POLYNOMIAL_H
#define DATA_STRUCTURE_AND_ALGORITHM_POLYNOMIAL_H

#define MAX_DEGREE 1000

typedef struct {
    int coeffArray[MAX_DEGREE + 1];
    int highPower;
} * Polynomial;

typedef struct Node* PtrToNode;

struct Node {
    int coefficient;
    int exponent;
    PtrToNode next;
};

void zeroPolynomial(Polynomial poly);
void addPolynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polySum);
void multiplyPolynomial(const Polynomial poly1, const Polynomial poly2, Polynomial polyProd);
#endif //DATA_STRUCTURE_AND_ALGORITHM_POLYNOMIAL_H
