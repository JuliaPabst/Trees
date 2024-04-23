#include <iostream>
#include "Programme.h"
#include "AVLTree.h"

int main() {
    AVLTree mainTree;
    Programme programme;

    programme.readFile(mainTree);
    programme.printInformation(mainTree);
    programme.checkIfSubtree(mainTree);

    return 0;
}
