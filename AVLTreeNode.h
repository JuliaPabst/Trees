#ifndef TREES_AVLTREENODE_H
#define TREES_AVLTREENODE_H


class AVLTreeNode {
private:
    int key;
    int height;
    AVLTreeNode *left, *right;

public:
    AVLTreeNode(int k) : key(k), height(0), left(nullptr), right(nullptr) {}
    int getKey();
    int getHeight();
    AVLTreeNode* getLeftNode();
    AVLTreeNode* getRightNode();
    void setLeftNode(AVLTreeNode* left);
    void setRightNode(AVLTreeNode* right);
    void setHeight(int newHeight);
};


#endif //TREES_AVLTREENODE_H
