#include "Programme.h"
#include <fstream>
#include <iostream>

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
            tree.insert(key);
        //}
       std::cout << key << std::endl;
    }

    std::cout << "" << std::endl;
    file.close();

    return 0;

}

void Programme::printInformation(AVLTree &tree) {
    std::cout << "Sorted tree: ";
    tree.printTree();
    std::cout << "" << std::endl;

    std::cout << "Balance factors of tree: " << std::endl;
    tree.printBalancesAndHeights();

    tree.printDecision();

    tree.printStatistics();
}