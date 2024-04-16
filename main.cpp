#include <iostream>
#include "Programme.h"
#include "AVLTree.h"

int main() {
    AVLTree tree;

    /*Programme programme;
    programme.readFile(tree);
    */

    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(10);
    tree.insert(20);

    std::cout << "Baum in sortierter Reihenfolge: ";
    tree.printTree();

    std::cout << "Baumstruktur: " << std::endl;
    tree.printStructure();

    std::cout << "Balancefaktoren und Höhen: " << std::endl;
    tree.printBalancesAndHeights();

    return 0;
}
