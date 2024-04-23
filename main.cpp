#include <iostream>
#include "Programme.h"
#include "AVLTree.h"

int main() {
    AVLTree mainTree;
    Programme programme;

    // Einlesen und Aufbau des Hauptbaums
    programme.readFile(mainTree);
    programme.printInformation(mainTree);

    // Benutzereingabe für die Art der Suche
    std::cout << "Select search type (1 for single key, 2 for subtree): ";
    int searchType;
    std::cin >> searchType;

    if (searchType == 1) {
        // Benutzereingabe für die einfache Suche
        std::cout << "Enter an integer key to search in the tree: ";
        int key;
        std::cin >> key;
        // Suche nach dem Schlüsselwert und Ausgabe des Pfades
        mainTree.searchPath(key);

    } else if (searchType == 2) {
        // Suche nach einem Subtree
        AVLTree subtree;
        programme.readSubtree(subtree); // Aufruf der Methode

        if (mainTree.isSubtree(subtree)) {
            std::cout << "Subtree found!" << std::endl;
        } else {
            std::cout << "Subtree not found!" << std::endl;
        }
    } else {
        std::cout << "Invalid search type selected." << std::endl;
    }

    return 0;
}
