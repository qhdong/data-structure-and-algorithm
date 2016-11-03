//
// Created by aaron on 16-11-3.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

struct AvlNode {
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
};

static int height(Position P) {
    if (P == NULL) {
        return -1;
    }
    return P->height;
}

static int max(int a, int b) {
    return a > b ? a : b;
}

static Position singleRotateWithLeft(Position k2) {
    Position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k2)) + 1;

    return k1;
}

static Position singleRotateWithRight(Position k2) {
    Position k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), height(k2)) + 1;

    return k1;
}

static Position doubleRotateWithLeft(Position k3) {
    k3->left = singleRotateWithRight(k3->left);
    return singleRotateWithLeft(k3);
}

static Position doubleRotateWithRight(Position k3) {
    k3->right = singleRotateWithLeft(k3->right);
    return singleRotateWithRight(k3);
}

AvlTree insert(ElementType X, AvlTree T) {
    if (T == NULL) {
        T = malloc(sizeof(struct AvlNode));
        T->element = X;
        T->height = 0;
        T->left = T->right = NULL;
    } else if (X < T->element) {
        T->left = insert(X, T->left);
        if (height(T->left) - height(T->right) == 2) {
            if (X < T->left->element) {
                T = singleRotateWithLeft(T);
            } else {
                T = doubleRotateWithLeft(T);
            }
        }
    } else if (X > T->element) {
        T->right = insert(X, T->right);
        if (height(T->right) - height(T->left) == 2) {
            if (X > T->right->element) {
                T = singleRotateWithRight(T);
            } else {
                T = doubleRotateWithRight(T);
            }
        }
    }

    T->height = max(height(T->left), height(T->right)) + 1;
    return T;
}

AvlTree makeEmpty(AvlTree T) {
    if (T != NULL) {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position find(ElementType X, AvlTree T) {
    if (T == NULL) return NULL;
    if (T->element == X) {
        return T;
    } else if (T->element > X) {
        return find(X, T->left);
    } else {
        return find(X, T->right);
    }
}

Position findMin(AvlTree T) {
    if (T == NULL) return NULL;
    else if (T->left == NULL) return T;
    else return findMin(T->left);

}
Position findMax(AvlTree T) {
    if (T != NULL) {
        while (T->right != NULL) {
            T = T->right;
        }
    }
    return T;
}

ElementType retrive(Position P) {
    return P->element;
}

void preorderTraversal(AvlTree T) {
    if (T != NULL) {
        printf("%2d, ", T->element);
        preorderTraversal(T->left);
        preorderTraversal(T->right);
    }
}

void inorderTraversal(AvlTree T) {
    if (T != NULL) {
        inorderTraversal(T->left);
        printf("%2d, ", T->element);
        inorderTraversal(T->right);
    }
}

void postorderTraversal(AvlTree T) {
    if (T != NULL) {
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        printf("%2d, ", T->element);
    }
}
