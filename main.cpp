#include <iostream>

//Knoten Struktur festgelegt
class AVLTreeNode {
private:
    int key;
    int height;
    AVLTreeNode *left, *right;

public:
    AVLTreeNode(int k) : key(k), height(0), left(nullptr), right(nullptr) {}
};


//Baumstruktur
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

public:
    AVLTree() : root(nullptr) {}

    void insert(int key);
    void deleteNode(int key);
    AVLTreeNode* search(int key);
    void printTree();

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
