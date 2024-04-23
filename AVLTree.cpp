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

// JULES
//public method that triggers private method
void AVLTree::insertInBinaryTree(int key) {
    rootBinary = insertInBinaryTree(rootBinary, key);
}

// JULES
//private method that does actual work
AVLTreeNode* AVLTree::insertInBinaryTree(AVLTreeNode* node, int key) {
    // if no node yet, new node is made the root
    if (node == nullptr) {
        return new AVLTreeNode(key);
    }

    // if key is smaller than current node, we go left
    if (key < node->getKey()) {
        node->setLeftNode(insertInBinaryTree(node->getLeftNode(), key));
    }
    // if key is bigger than current node, we go right
    else if (key > node->getKey()) {
        node->setRightNode(insertInBinaryTree(node->getRightNode(), key));
    }
    // if they are the same, we return node, because a key is unique
    else {
        return node;
    }

    // set new height by getting max height of left node and right node and adding 1
    node->setHeight(1 + std::max(getHeight(node->getLeftNode()), getHeight(node->getRightNode())));

    return node;
}

// PETRA
void AVLTree::insertInAVLTree(int key) {
    rootAVL = insertInAVLTree(rootAVL, key);
}

// PETRA
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

// PETRA
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


// PETRA
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

// JULES
int AVLTree::getHeight(AVLTreeNode* node) {
    // if null pointer - we need to subtract one as 1 is added in the setHeight part
    if (node == nullptr) {
        return -1;
    }
    return node->getHeight();
}

// JULES
int AVLTree::getBalanceFactor(AVLTreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    // if there are more elements to the right: Balance is negative
    return getHeight(node->getLeftNode()) - getHeight(node->getRightNode());
}

// JULES
void AVLTree::printTree(AVLTreeNode* root) {
    printInOrder(root);
    std::cout << std::endl;
}

// JULES
void AVLTree::printInOrder(AVLTreeNode* node) {
    if (node != nullptr) {
        // rescursively first print left side
        printInOrder(node->getLeftNode());
        std::cout << node->getKey() << " ";
        // recursively then print right side
        printInOrder(node->getRightNode());
    }
}

// JULES
void AVLTree::printBalanceAndHeight(AVLTreeNode* node) {
    if (node != nullptr) {
        // first print balances to the left
        printBalanceAndHeight(node->getLeftNode());
        int balance = - getBalanceFactor(node);

        // if balance is exceeding a balanced node - it is a AVL violation
        if (balance < -1 || balance > 1){
            std::cout << "bal(" << node->getKey() << ") = " << balance << " (AVL violation!)" << std::endl;
        } else {
            std::cout << "bal(" << node->getKey() << ") = " << balance << std::endl;
        }

        // then print balances to the right
        printBalanceAndHeight(node->getRightNode());
    }
}

// JULES
void AVLTree::printBalancesAndHeights(AVLTreeNode* root) {
    printBalanceAndHeight(root);
    std::cout << " " << std::endl;
}

// JULES
void AVLTree::printDecision() {
    printDecision(rootBinary);
}

// JULES
void AVLTree::printDecision(AVLTreeNode* node){
    if (node != nullptr) {
        // checks if it is overall balanced
        int balance = getBalanceFactor(node);
        if (balance < -1 || balance > 1){
            std::cout << "AVL: no" << std::endl;
        } else {
            std::cout << "AVL: yes" << std::endl;
        }
    }
}

// JULES
AVLTreeNode* AVLTree::findMinimum(AVLTreeNode* node){
    if (node == nullptr) {
        return nullptr;
    }

    // gets left most node
    while (node->getLeftNode() != nullptr) {
        node = node->getLeftNode();
    }

    return node;
}

// JULES
AVLTreeNode* AVLTree::findMaximum(AVLTreeNode* node){
    if (node == nullptr) {
        return nullptr;
    }

    // gets right most node
    while (node->getRightNode() != nullptr) {
        node = node->getRightNode();
    }

    return node;
}

// JULES
void AVLTree::sumAndCount(AVLTreeNode* node, int& sum, int& count) {
    if (node != nullptr) {
        sum += node->getKey();
        count++;
        // add Nodes to the left
        sumAndCount(node->getLeftNode(), sum, count);
        // add Nodes to the right
        sumAndCount(node->getRightNode(), sum, count);
    }
}

// JULES
void AVLTree::calculateStats() {
    int sum = 0;
    int count = 0;

    if (rootBinary != nullptr) {
        treeStats.min = findMinimum(rootBinary)->getKey();
        treeStats.max = findMaximum(rootBinary)->getKey();
        sumAndCount(rootBinary, sum, count);
        // check if count is not 0 - otherwise program would crash
        treeStats.avg = count > 0 ? (double)sum / (double)count : 0;
    } else {
        treeStats.min = treeStats.max = 0;
        treeStats.avg = 0.0;
    }
}

// JULES
void AVLTree::printStatistics() {
    calculateStats();
    std::cout << "" << std::endl;
    std::cout << "Here are some statistics:" << std::endl;
    std::cout << "Minimum: " << treeStats.min << std::endl;
    std::cout << "Maximum: " << treeStats.max << std::endl;
    std::cout << "Average: " << treeStats.avg << std::endl;
};

// PETRA
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

// PETRA
bool AVLTree::areIdentical(AVLTreeNode* node1, AVLTreeNode* node2) const {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }

    return (node1->getKey() == node2->getKey() &&
            areIdentical(node1->getLeftNode(), node2->getLeftNode()) &&
            areIdentical(node1->getRightNode(), node2->getRightNode()));
}

// PETRA
bool AVLTree::isSubtreeHelper(AVLTreeNode* mainRoot, AVLTreeNode* subRoot) const {
    if (!subRoot) return true;
    if (!mainRoot) return false;

    if (mainRoot->getKey() == subRoot->getKey() && checkSubtreeStructure(mainRoot, subRoot)) {
        return true;
    }

    return isSubtreeHelper(mainRoot->getLeftNode(), subRoot) ||
           isSubtreeHelper(mainRoot->getRightNode(), subRoot);
}

// PETRA
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

// PETRA
bool AVLTree::isSubtree(const AVLTree& subtree) const {
    if (isSubtreeHelper(rootAVL, subtree.rootAVL)) {
        std::cout << "Subtree found" << std::endl;
        return true;
    } else {
        std::cout << "Subtree not found!" << std::endl;
        return false;
    }
}

