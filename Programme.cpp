#include "Programme.h"
#include <iostream>
#include <fstream>
#include <string>


int Programme::readFile(AVLTree& tree) {
    std::string filename =  "numbers.txt";
    std::cout << "treecheck ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return 1;
    }

    int key;
    std::cout << "Your tree will be created using these numbers: " << std::endl;
    while (file >> key) {
        //if (!tree.search(key)) {
            tree.insertInBinaryTree(key);
            tree.insertInAVLTree(key);
        //}
       std::cout << key << std::endl;
    }

    std::cout << "" << std::endl;
    file.close();

    return 0;

}
void Programme::printInformation(AVLTree &tree) {
    std::cout << "Balance factors of AVL tree: " << std::endl;
    tree.printBalancesAndHeights(tree.getRootAVL());

    std::cout << "Balance factors of binary tree: " << std::endl;
    tree.printBalancesAndHeights(tree.getRootBinary());

    tree.printDecision();

    tree.printStatistics();
}

int Programme::readSubtree(AVLTree& subtree) {
    std::cout << "Select subtree file (1 for subtree.txt, 2 for nosubtree.txt, 3 for onenode.txt): ";
    int choice;
    std::cin >> choice;

    std::string filename;
    switch(choice) {
        case 1:
            filename = "subtree.txt";
            break;
        case 2:
            filename = "nosubtree.txt";
            break;
        case 3:
            filename = "onenode.txt";
            break;
        default:
            std::cerr << "Invalid choice." << std::endl;
            return 1;
    }

    std::cout << "Loading subtree from file: " << filename << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return 1;
    }

    int key;
    std::cout << "Your tree will be created using these numbers: " << std::endl;
    while (file >> key) {
        subtree.insertInAVLTree(key);
        std::cout << key << std::endl;
    }

    std::cout << "" << std::endl;
    file.close();

    return 0;

}

void Programme::checkIfSubtree(AVLTree &tree) {
    int searchType = 0;

    while(searchType != 1 && searchType != 2){
        std::cout << "Select search type (1 for single key, 2 for subtree): ";
        std::cin >> searchType;
        if (searchType == 1) {
            std::cout << "Enter an integer key to search in the tree: ";
            int key;
            std::cin >> key;
            tree.searchPath(key);
        } else if (searchType == 2) {
            AVLTree subtree;
            readSubtree(subtree);

            std::cout << "Subtree: " << std::endl;
            subtree.printTree(subtree.getRootAVL());
            std::cout << "Maintree: " << std::endl;
            tree.printTree(tree.getRootAVL());

            bool found = tree.isSubtree(subtree);

        } else {
            std::cout << "Invalid search type selected." << std::endl;
        }
    }


}