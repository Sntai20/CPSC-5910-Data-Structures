#include <iostream>
#include <vector>
#include <fstream>
#include "BST.h"

int main() {
    BST*  bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(10);
    bst->displayPreOrder();
    //bst->displayInOrder();
    //bst->displayPostOrder();

    // Try some removes.
    std::cout << std::endl;
    bst->remove(3);
    bst->displayPreOrder();

    std::cout << std::endl;
    bst->remove(5);
    bst->displayPreOrder();

    // Sort a file. Recall if you're running this inside CLion then you need to mind the working directory.
    std::vector<int> data;
    BST sortingTree;

    std::ifstream unsortedFile;
    unsortedFile.open("unsortedints.txt", std::ios::in);
    if (unsortedFile.is_open()) {
        int i;
        while (unsortedFile >> i) {
            sortingTree.insert(i);
        }
        unsortedFile.close();
    }

    std::ofstream sortedFile;
    sortedFile.open("sortedints.txt", std::ios::out);
    if (sortedFile.is_open()) {
        std::vector<int> sortedInts;
        sortingTree.dumpInOrder(sortedInts);

        for (int& i : sortedInts) {
            sortedFile << i << std::endl;
        }

        sortedFile.close();
    }

    bst->dumpInOrder(data);

    delete bst;
    return 0;
}
