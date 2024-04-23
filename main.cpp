#include <iostream>
#include "Programme.h"
#include "AVLTree.h"

int main() {
    AVLTree mainTree;
    Programme programme;

    // Einlesen und Aufbau des Hauptbaums
    programme.readFile(mainTree);
    programme.printInformation(mainTree);
    programme.checkIfSubtree(mainTree);


    return 0;
}
