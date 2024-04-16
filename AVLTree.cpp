#include "AVLTree.h"
#include <iostream>


AVLTree::AVLTree() : root(nullptr) {
    treeStats.min = 0;
    treeStats.max = 0;
    treeStats.avg = 0;
}

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

    /*
    if (balance > 1 && node->getLeftNode() != nullptr && key < node->getLeftNode()->getKey()){
        return rotateRight(node);
    }

    if (balance < -1 && node->getRightNode() != nullptr && key > node->getRightNode()->getKey()){
        return rotateLeft(node);
    }

    if (balance > 1 && node->getLeftNode() != nullptr && key > node->getLeftNode()->getKey()) {
        node->setLeftNode(rotateLeft(node->getLeftNode()));
        return rotateRight(node);
    }

    if (balance < -1 && node->getRightNode() != nullptr && key < node->getRightNode()->getKey()) {
        node->setRightNode(rotateRight(node->getRightNode()));
        return rotateLeft(node);
    }
     */

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
    return getHeight(node->getLeftNode()) - getHeight(node->getRightNode());
}

AVLTreeNode* AVLTree::rotateRight(AVLTreeNode* y) {
    if (y == nullptr || y->getLeftNode() == nullptr){
        return y;
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

void AVLTree::printBalanceAndHeight(AVLTreeNode* node) {
    if (node != nullptr) {
        printBalanceAndHeight(node->getLeftNode());
        int balance = - getBalanceFactor(node);

        if (balance < -1 || balance > 1){
            std::cout << "bal(" << node->getKey() << ") = " << balance << " (AVL violation!)" << std::endl;
        } else {
            std::cout << "bal(" << node->getKey() << ") = " << balance << std::endl;
        }
        printBalanceAndHeight(node->getRightNode());
    }
}

void AVLTree::printBalancesAndHeights() {
    printBalanceAndHeight(root);
    std::cout << " " << std::endl;
}

void AVLTree::printDecision(AVLTreeNode* node){
    if (node != nullptr) {
        int balance = getBalanceFactor(node);
        if (balance < -1 || balance > 1){
            std::cout << "AVL: no" << std::endl;
        } else {
            std::cout << "AVL: yes" << std::endl;
        }
    }
}

void AVLTree::printDecision() {
    printDecision(root);
}


AVLTreeNode* AVLTree::findMinimum(AVLTreeNode* node){
    if (node == nullptr) {
        return nullptr;
    }

    while (node->getLeftNode() != nullptr) {
        node = node->getLeftNode();
    }

    return node;
}

AVLTreeNode* AVLTree::findMaximum(AVLTreeNode* node){
    if (node == nullptr) {
        return nullptr;
    }

    while (node->getRightNode() != nullptr) {
        node = node->getRightNode();
    }

    return node;
}

void AVLTree::sumAndCount(AVLTreeNode* node, int& sum, int& count) {
    if (node != nullptr) {
        sum += node->getKey();
        count++;
        sumAndCount(node->getLeftNode(), sum, count);
        sumAndCount(node->getRightNode(), sum, count);
    }
}

void AVLTree::calculateStats() {
    int sum = 0;
    int count = 0;

    if (root != nullptr) {
        treeStats.min = findMinimum(root)->getKey();
        treeStats.max = findMaximum(root)->getKey();
        sumAndCount(root, sum, count);
        treeStats.avg = count > 0 ? (double)sum / count : 0;
    } else {
        treeStats.min = treeStats.max = 0;
        treeStats.avg = 0.0;
    }
}

void AVLTree::printStatistics() {
    calculateStats();
    std::cout << "" << std::endl;
    std::cout << "Here are some statistics:" << std::endl;
    std::cout << "Minimum: " << treeStats.min << std::endl;
    std::cout << "Maximum: " << treeStats.max << std::endl;
    std::cout << "Average: " << treeStats.avg << std::endl;
};
