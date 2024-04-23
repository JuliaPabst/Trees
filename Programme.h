#ifndef TREES_PROGRAMME_H
#define TREES_PROGRAMME_H
#include "AVLTree.h"
#include <string>

class Programme {
public:
    int readFile(AVLTree& tree);
    int readSubtree(AVLTree& subtree);  //  Methode für Subtrees
    void printInformation(AVLTree& tree);

private:

};


#endif //TREES_PROGRAMME_H
