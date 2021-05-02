//
// Created by Antonio Santana on 5/3/21.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "BST.h"

using namespace std;

void bstTester(BST<int>* bst)
{
    // Insert method
    cout << "\nInsert method" << endl;
    bst->insert(5);
    cout << "Inserted 5" << endl;
    bst->insert(3);
    cout << "Inserted 3" << endl;
    bst->insert(10);
    cout << "Inserted 10" << endl;

    // PreOrder method
    cout << "\nPreOrder method" << endl;
    bst->displayPreOrder();

    // InOrder method
    cout << "\nImplement displayInOrder" << endl;
    bst->displayInOrder();

    // PostOrder method
    cout << "Implement displayPostOrder" << endl;
    bst->displayPostOrder();

    // Contains Method
    cout << "\nContains method" << endl;
    cout << "bst.contains(10) returns " << bst->contains(10)
              << "; should be 1 (true)" << std::endl;

    // getLevel method
    cout << "\nImplement getLevel method" << endl;
    // getAncestors method
    cout << "Implement getAncestors method" << endl;


    // Try some removes.
    cout << "\nRemove method" << endl;
    bst->remove(3);
    cout << "Removed 3" << endl;
    bst->displayPreOrder();

    std::cout << std::endl;
    bst->remove(5);
    cout << "Removed 5" << endl;
    bst->displayPreOrder();


    cout << "\nValidate size and return values" << endl;
    cout << "Validate empty and return values" << endl;
    cout << "Validate getHeight and return values" << endl;
    cout << "Validate getLeafCount and return values" << endl;

    // Sort a file. Recall if you're running this inside CLion then you need to mind the working directory.
    cout << "\nSort the file" << endl;
    std::vector<int> data;
    BST<int> sortingTree;

    // Read the unsorted file containing integers.
    std::ifstream unsortedFile;
    unsortedFile.open("unsortedints.txt", std::ios::in);
    cout << "unsortedFile.open(\"unsortedints.txt\", std::ios::in)" << endl;
    if (unsortedFile.is_open()) {
        int i;
        cout << "sortingTree.insert(i) ";
        while (unsortedFile >> i) {
            cout << i << ", ";
            sortingTree.insert(i);
        }
        cout << endl;
        unsortedFile.close();
    }

    std::ofstream sortedFile;
    cout << "\nsortedFile.open(\"sortedints.txt\", std::ios::out);" << endl;
    sortedFile.open("sortedints.txt", std::ios::out);
    if (sortedFile.is_open()) {
        std::vector<int> sortedInts;
        cout << "sortingTree.dumpInOrder(sortedInts);" << endl;
        sortingTree.dumpInOrder(sortedInts);

        cout << "sortedFile ";
        for (int& i : sortedInts)
        {
            cout << i << ", ";
            sortedFile << i << std::endl;
        }
        cout << endl;

        sortedFile.close();
    }

    bst->dumpInOrder(data);
    cout << "bst->dumpInOrder(data);" << endl;


} // end bstTester

int main() {
    BST<int>*  bst = new BST<int>();
    cout << "Please provide the filenames: " << endl;

    cout << "Testing the BST Interface: \n" << endl;
    bstTester(bst);
    cout << "\nAll done testing the BST Interface!" << endl;


    delete bst;
    return 0;
} // end main
