#include <iostream>
#include "Programme.h"
#include "AVLTree.h"

int main() {
    AVLTree tree;

    Programme programme;
    programme.readFile(tree);


    std::cout << "Baum in sortierter Reihenfolge: ";
    tree.printTree();

    std::cout << "Balancefaktoren und Höhen: " << std::endl;
    tree.printBalancesAndHeights();

    return 0;
}
