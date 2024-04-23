#include "AVLTree.h"
#include <iostream>


AVLTree::AVLTree() : rootBinary(nullptr), rootAVL(nullptr) {
    treeStats.min = 0;
    treeStats.max = 0;
    treeStats.avg = 0;
}

AVLTreeNode* AVLTree::getRootBinary(){
    return rootBinary;
}
AVLTreeNode* AVLTree::getRootAVL(){
    return rootAVL;
}

void AVLTree::insertInBinaryTree(int key) {
    rootBinary = insertInBinaryTree(rootBinary, key);
}

AVLTreeNode* AVLTree::insertInBinaryTree(AVLTreeNode* node, int key) {
    if (node == nullptr) {
        return new AVLTreeNode(key);
    }

    if (key < node->getKey()) {
        node->setLeftNode(insertInBinaryTree(node->getLeftNode(), key));
    } else if (key > node->getKey()) {
        node->setRightNode(insertInBinaryTree(node->getRightNode(), key));
    } else {
        return node;
    }

    node->setHeight(1 + std::max(getHeight(node->getLeftNode()), getHeight(node->getRightNode())));

    return node;
}

void AVLTree::insertInAVLTree(int key) {
    rootAVL = insertInAVLTree(rootAVL, key);
}

AVLTreeNode* AVLTree::insertInAVLTree(AVLTreeNode* node, int key) {
    if (node == nullptr) {
        return new AVLTreeNode(key);
    }

    if (key < node->getKey()) {
        node->setLeftNode(insertInAVLTree(node->getLeftNode(), key));
    } else if (key > node->getKey()) {
        node->setRightNode(insertInAVLTree(node->getRightNode(), key));
    } else {
        return node;
    }

    node->setHeight(1 + std::max(getHeight(node->getLeftNode()), getHeight(node->getRightNode())));

    int balance = getBalanceFactor(node);

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

    return node;
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

void AVLTree::printInOrder(AVLTreeNode* node) {
    if (node != nullptr) {
        printInOrder(node->getLeftNode());
        std::cout << node->getKey() << " ";
        printInOrder(node->getRightNode());
    }
}

void AVLTree::printTree(AVLTreeNode* root) {
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

void AVLTree::printBalancesAndHeights(AVLTreeNode* root) {
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
    printDecision(rootBinary);
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

    if (rootBinary != nullptr) {
        treeStats.min = findMinimum(rootBinary)->getKey();
        treeStats.max = findMaximum(rootBinary)->getKey();
        sumAndCount(rootBinary, sum, count);
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

void AVLTree::searchPath(int key) {
    AVLTreeNode* current = rootAVL;
    std::vector<int> path;
    while (current != nullptr) {
        path.push_back(current->getKey());
        if (key == current->getKey()) {
            std::cout << key << " found ";
            for (int k : path) {
                std::cout << k << ", ";
            }
            std::cout << std::endl;
            return;
        } else if (key < current->getKey()) {
            current = current->getLeftNode();
        } else {
            current = current->getRightNode();
        }
    }
    std::cout << key << " not found!" << std::endl;
}

bool AVLTree::areIdentical(AVLTreeNode* node1, AVLTreeNode* node2) const {
    // both nodes empty
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }
    // one node is empty
    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }
    // compare current node and recursively its children
    return (node1->getKey() == node2->getKey() &&
            areIdentical(node1->getLeftNode(), node2->getLeftNode()) &&
            areIdentical(node1->getRightNode(), node2->getRightNode()));
}


bool AVLTree::isSubtreeHelper(AVLTreeNode* mainRoot, AVLTreeNode* subRoot) const {
    if (!subRoot) return true;  // If subRoot is exhausted, match found.
    if (!mainRoot) return false;  // If mainRoot exhausts first, no match.

    // Start the comparison if the current nodes match.
    if (mainRoot->getKey() == subRoot->getKey() && checkSubtreeStructure(mainRoot, subRoot)) {
        return true;
    }

    // Continue to search in both left and right subtrees of the current node.
    return isSubtreeHelper(mainRoot->getLeftNode(), subRoot) ||
           isSubtreeHelper(mainRoot->getRightNode(), subRoot);
}


bool AVLTree::checkSubtreeStructure(AVLTreeNode* mainRoot, AVLTreeNode* subRoot) const {
    if (!subRoot) return true;
    if (!mainRoot) return false;

    if (mainRoot->getKey() == subRoot->getKey()) {
        if (checkSubtreeStructure(mainRoot->getLeftNode(), subRoot->getLeftNode()) ||
            checkSubtreeStructure(mainRoot->getRightNode(), subRoot->getLeftNode())) {
            return true;
        }
    }

    return false;
}


bool AVLTree::isSubtree(const AVLTree& subtree) const {
    if (isSubtreeHelper(rootAVL, subtree.rootAVL)) {
        std::cout << "Subtree found" << std::endl;
        return true;
    } else {
        std::cout << "Subtree not found!" << std::endl;
        return false;
    }
}

