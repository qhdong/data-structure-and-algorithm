//
// Created by aaron on 16-11-3.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_AVLTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_AVLTREE_H
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;
typedef int ElementType;

AvlTree makeEmpty(AvlTree T);
Position find(ElementType X, AvlTree T);
Position findMin(AvlTree T);
Position findMax(AvlTree T);
AvlTree insert(ElementType X, AvlTree T);
AvlTree delete(ElementType X, AvlTree T);
ElementType retrive(Position P);

void preorderTraversal(AvlTree T);
void inorderTraversal(AvlTree T);
void postorderTraversal(AvlTree T);
#endif //DATA_STRUCTURE_AND_ALGORITHM_AVLTREE_H
