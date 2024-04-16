#include "AVLTree.h"
#include <iostream>

void AVLTree::insert(int key) {
    root = insert(root, key);
}

AVLTreeNode* AVLTree::insert(AVLTreeNode* node, int key) {
    if (node == nullptr) {
        return new AVLTreeNode(key);
    }

    if (key < node->getKey()) {
        node->setLeftNode(insert(node->getLeftNode(), key));
    } else if (key > node->getKey()) {
        node->setRightNode(insert(node->getRightNode(), key));
    } else {
        return node;
    }

    node->setHeight(1 + std::max(getHeight(node->getLeftNode()), getHeight(node->getRightNode())));

    int balance = getBalanceFactor(node);

    printBalancesAndHeights();

    if (balance > 1 && node->getLeftNode() != nullptr && key < node->getLeftNode()->getKey())
        return rotateRight(node);

    if (balance < -1 && node->getRightNode() != nullptr && key > node->getRightNode()->getKey())
        return rotateLeft(node);

    if (balance > 1 && node->getLeftNode() != nullptr && key > node->getLeftNode()->getKey()) {
        node->setLeftNode(rotateLeft(node->getLeftNode()));
        return rotateRight(node);
    }

    if (balance < -1 && node->getRightNode() != nullptr && key < node->getRightNode()->getKey()) {
        node->setRightNode(rotateRight(node->getRightNode()));
        return rotateLeft(node);
    }

    printBalancesAndHeights();

    return node;
}

int AVLTree::getHeight(AVLTreeNode* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->getHeight();
}

int AVLTree::getBalanceFactor(AVLTreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->getRightNode()) - getHeight(node->getLeftNode());
}

AVLTreeNode* AVLTree::rotateRight(AVLTreeNode* y) {
    if (y == nullptr || y->getLeftNode() == nullptr){
        return y;  // Check added to prevent dereferencing null
    }

    AVLTreeNode* x = y->getLeftNode();
    AVLTreeNode* T2 = x->getRightNode();

    // Perform rotation
    x->setRightNode(y);
    y->setLeftNode(T2);

    // Update heights
    y->setHeight(std::max(getHeight(y->getLeftNode()), getHeight(y->getRightNode())) + 1);
    x->setHeight( std::max(getHeight(x->getLeftNode()), getHeight(x->getRightNode())) + 1);

    return x;
}

AVLTreeNode* AVLTree::rotateLeft(AVLTreeNode* x) {
    if (x == nullptr || x->getRightNode() == nullptr){
        return x;
    }

    AVLTreeNode* y = x->getRightNode();
    AVLTreeNode* T2 = y->getLeftNode();

    // Perform rotation
    y->setLeftNode(x);
    x->setRightNode(T2);


    // Update heights
    x->setHeight( std::max(getHeight(x->getLeftNode()), getHeight(x->getRightNode())) + 1);
    y->setHeight(std::max(getHeight(y->getLeftNode()), getHeight(y->getRightNode())) + 1);

    return y;
}

void AVLTree::printInOrder(AVLTreeNode* node) {
    if (node != nullptr) {
        printInOrder(node->getLeftNode());
        std::cout << node->getKey() << " ";
        printInOrder(node->getRightNode());
    }
}

void AVLTree::printTree() {
    printInOrder(root);
    std::cout << std::endl;
}

void AVLTree::printTreeStructure(AVLTreeNode* node, int depth = 0) {
    if (node != nullptr) {
        printTreeStructure(node->getRightNode(), depth + 4);
        std::cout << std::string(depth, ' ') << node->getKey() << std::endl;
        printTreeStructure(node->getLeftNode(), depth + 4);
    }
}

void AVLTree::printStructure() {
    printTreeStructure(root);
}

void AVLTree::printBalanceAndHeight(AVLTreeNode* node) {
    if (node != nullptr) {
        printBalanceAndHeight(node->getLeftNode());
        int balance = getBalanceFactor(node);
        std::cout << "Key: " << node->getKey() << ", Balance: " << balance << ", Height: " << node->getHeight() << std::endl;
        printBalanceAndHeight(node->getRightNode());
    }
}

void AVLTree::printBalancesAndHeights() {
    printBalanceAndHeight(root);
    std::cout << " " << std::endl;
}