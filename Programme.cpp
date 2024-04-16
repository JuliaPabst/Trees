#include "Programme.h"
#include <fstream>
#include <iostream>

int Programme::readFile(AVLTree& tree) {
    std::string filename =  "numbers.txt";
    std::cout << "Please enter the filename: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return 1;
    }

    int key;
    while (file >> key) {
        //if (!tree.search(key)) {
            tree.insert(key);
        //}
       std::cout << key << std::endl;
    }

    file.close();

    return 0;

}