#include "AVLTree.h"
#include <iostream>


AVLTree::AVLTree() : root(nullptr) {
    treeStats.min = 0;
    treeStats.max = 0;
    treeStats.avg = 0;
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

void AVLTree::searchPath(int key) {
    AVLTreeNode* current = root;
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

bool AVLTree::areIdentical(AVLTreeNode* node1, AVLTreeNode* node2) const{
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
    if (!subRoot) return true;
    if (!mainRoot) return false;
    if (areIdentical(mainRoot, subRoot)) return true;
    return isSubtreeHelper(mainRoot->getLeftNode(), subRoot) || isSubtreeHelper(mainRoot->getRightNode(), subRoot);
}

bool AVLTree::isSubtree(const AVLTree& subtree) const {
    return isSubtreeHelper(root, subtree.root);
}
