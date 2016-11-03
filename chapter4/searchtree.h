//
// Created by aaron on 16-11-3.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_SEARCHTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_SEARCHTREE_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree makeEmpty(SearchTree T);
Position find(ElementType X, SearchTree T);
Position findMax(SearchTree T);
Position findMin(SearchTree T);
SearchTree insert(ElementType X, SearchTree T);
SearchTree delete(ElementType X, SearchTree T);
void preorderTraversal(SearchTree T);
void inorderTraversal(SearchTree T);
void postorderTraversal(SearchTree T);
#endif //DATA_STRUCTURE_AND_ALGORITHM_SEARCHTREE_H
