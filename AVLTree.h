#ifndef TREES_AVLTREE_H
#define TREES_AVLTREE_H
#include "AVLTreeNode.h"


class AVLTree {
private:
    AVLTreeNode* rootBinary;
    AVLTreeNode* rootAVL;
    struct TreeStats {
        int min;
        int max;
        double avg;
    };
    TreeStats treeStats;
    void calculateStats();
    AVLTreeNode* insertInBinaryTree(AVLTreeNode* node, int key);
    AVLTreeNode* insertInAVLTree(AVLTreeNode* node, int key);
    AVLTreeNode* rotateRight(AVLTreeNode* y);
    AVLTreeNode* rotateLeft(AVLTreeNode* x);
    AVLTreeNode* search(AVLTreeNode* node, int key);
    int getHeight(AVLTreeNode* node);
    int getBalanceFactor(AVLTreeNode* node);
    void printInOrder(AVLTreeNode* node);
    void printBalanceAndHeight(AVLTreeNode* node);
    void printDecision(AVLTreeNode* node);
    AVLTreeNode*  findMinimum(AVLTreeNode* node);
    AVLTreeNode*  findMaximum(AVLTreeNode* node);
    void sumAndCount(AVLTreeNode* node, int& sum, int& count);
    bool areIdentical(AVLTreeNode* node1, AVLTreeNode* node2) const;
    bool isSubtreeHelper(AVLTreeNode* mainRoot, AVLTreeNode* subRoot) const;
    bool checkSubtreeStructure(AVLTreeNode* mainRoot, AVLTreeNode* subRoot) const;

public:
    AVLTree();
    AVLTreeNode* getRootBinary();
    AVLTreeNode* getRootAVL();
    void insertInBinaryTree(int key);
    void insertInAVLTree(int key);
    AVLTreeNode* search(int key);
    void printTree(AVLTreeNode* root);
    void printBalancesAndHeights(AVLTreeNode* root);
    void printDecision();
    void printStatistics();
    void searchPath(int key);
    bool isSubtree(const AVLTree& subtree) const;  // Überladung hinzufügen
};



#endif //TREES_AVLTREE_H
