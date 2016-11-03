//
// Created by aaron on 16-11-3.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "searchtree.h"

struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree makeEmpty(SearchTree T) {
    if (T != NULL) {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position find(ElementType X, SearchTree T) {
    if (T == NULL) {
        return NULL;
    } else {
        if (T->element == X) {
            return T;
        } else if (T->element > X) {
            return find(X, T->left);
        } else {
            return find(X, T->right);
        }
    }
}

Position findMax(SearchTree T) {
    if (T != NULL) {
        while (T->right != NULL) {
            T = T->right;
        }
    }
    return T;
}

Position findMin(SearchTree T) {
    if (T != NULL) {
        return findMin(T->left);
    }
    return T;
}

SearchTree insert(ElementType X, SearchTree T) {
    if (T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        T->element = X;
        T->left = T->right = NULL;
    } else if (X > T->element) {
        T->right = insert(X, T->right);
    } else if (X < T->element) {
        T->left = insert(X, T->left);
    }
    return T;
}

SearchTree delete(ElementType X, SearchTree T) {
    Position tmp;
    if (T == NULL) {
        fprintf(stderr, "can't find element\n");
    } else if (X > T->element) {
        T->right = delete(X, T->right);
    } else if (X < T->element) {
        T->left = delete(X, T->left);
    } else if (T->left && T->right) {
        tmp = findMin(T->right);
        T->element = tmp->element;
        T->right = delete(T->element, T->right);
    } else {
        tmp = T;
        if (T->left == NULL) {
            T = T->right;
        } else if (T->right == NULL) {
            T = T->left;
        }
        free(tmp);
    }
    return T;
}

void preorderTraversal(SearchTree T) {
    if (T != NULL) {
        printf("%2d, ", T->element);
        preorderTraversal(T->left);
        preorderTraversal(T->right);
    }
}

void inorderTraversal(SearchTree T) {
    if (T != NULL) {
        inorderTraversal(T->left);
        printf("%2d, ", T->element);
        inorderTraversal(T->right);
    }
}

void postorderTraversal(SearchTree T) {
    if (T != NULL) {
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        printf("%2d, ", T->element);
    }
}