#include "AVLTreeNode.h"
int AVLTreeNode::getKey() {
    return key;
};

int AVLTreeNode::getHeight() {
    return height;
};

AVLTreeNode* AVLTreeNode::getLeftNode(){
    return left;
};

AVLTreeNode* AVLTreeNode::getRightNode(){
    return right;
};

void AVLTreeNode::setLeftNode(AVLTreeNode* node){
    left = node;
};

void AVLTreeNode::setRightNode(AVLTreeNode* node){
    right = node;
};

void AVLTreeNode::setHeight(int newHeight){
    height = newHeight;
};