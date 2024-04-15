#ifndef TREES_AVLTREENODE_H
#define TREES_AVLTREENODE_H


class AVLTreeNode {
private:
    int key;
    int height;
    AVLTreeNode *left, *right;

public:
    AVLTreeNode(int k) : key(k), height(0), left(nullptr), right(nullptr) {}
};


#endif //TREES_AVLTREENODE_H
