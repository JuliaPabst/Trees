#ifndef TREES_AVLTREE_H
#define TREES_AVLTREE_H
#include "AVLTreeNode.h"


class AVLTree {
private:
    AVLTreeNode* root;
    AVLTreeNode* insert(AVLTreeNode* node, int key);
    AVLTreeNode* deleteNode(AVLTreeNode* node, int key);
    AVLTreeNode* search(AVLTreeNode* node, int key);
    AVLTreeNode* rotateRight(AVLTreeNode* y);
    AVLTreeNode* rotateLeft(AVLTreeNode* x);
    AVLTreeNode* rebalance(AVLTreeNode* node);
    int getHeight(AVLTreeNode* node);
    int getBalanceFactor(AVLTreeNode* node);
    void updateHeight(AVLTreeNode* node);
    void printInOrder(AVLTreeNode* node);
    void printTreeStructure(AVLTreeNode* node, int depth);
    void printBalanceAndHeight(AVLTreeNode* node);

public:
    AVLTree() : root(nullptr) {}

    void insert(int key);
    void deleteNode(int key);
    AVLTreeNode* search(int key);
    void printTree();
    void printStructure();
    void printBalancesAndHeights();

};


#endif //TREES_AVLTREE_H
