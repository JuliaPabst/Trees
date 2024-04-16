#include <iostream>
#include "Programme.h"
#include "AVLTree.h"

int main() {
    AVLTree tree;

    Programme programme;
    programme.readFile(tree);
    programme.printInformation(tree);

    return 0;
}
