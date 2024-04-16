#ifndef TREES_AVLTREE_H
#define TREES_AVLTREE_H
#include "AVLTreeNode.h"


class AVLTree {
private:
    AVLTreeNode* root;
    struct TreeStats {
        int min;
        int max;
        double avg;
    };
    TreeStats treeStats;
    void calculateStats();
    AVLTreeNode* insert(AVLTreeNode* node, int key);
    AVLTreeNode* deleteNode(AVLTreeNode* node, int key);
    AVLTreeNode* search(AVLTreeNode* node, int key);
    int getHeight(AVLTreeNode* node);
    int getBalanceFactor(AVLTreeNode* node);
    void printInOrder(AVLTreeNode* node);
    void printBalanceAndHeight(AVLTreeNode* node);
    void printDecision(AVLTreeNode* node);
    AVLTreeNode*  findMinimum(AVLTreeNode* node);
    AVLTreeNode*  findMaximum(AVLTreeNode* node);
    void sumAndCount(AVLTreeNode* node, int& sum, int& count);

public:
    AVLTree();
    void insert(int key);
    void deleteNode(int key);
    AVLTreeNode* search(int key);
    void printTree();
    void printBalancesAndHeights();
    void printDecision();
    void printStatistics();
};


#endif //TREES_AVLTREE_H
