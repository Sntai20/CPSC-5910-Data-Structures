//
// Created by Antonio Santana on 5/3/21.
//
#include "BST.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void bstTester(BST<int> *bst) {
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
    cout << "\nContains method\n" << "bst.contains(10) returns " << bst->contains(10)
         << "; should be 1 (true)" << std::endl;

    // empty method
    cout << "\nempty method\n" << "bst->empty() returns " << bst->empty()
         << "; should be 0 (false)" << endl;

    // size method
    cout << "\nsize method\n" << "bst->size() returns " << bst->size()
         << "; should be 0 (root)" << endl;

    // getLeafCount method
    cout << "\ngetLeafCount method\n" << "bst->getLeafCount() returns " << bst->getLeafCount()
         << "; should be 0 (root)" << endl;

    // getHeight method
    cout << "\ngetHeight method\n" << "bst->getHeight() returns " << bst->getHeight()
         << "; should be 0 (root)" << endl;

    // getLevel method
    cout << "\nImplement getLevel method" << endl;
    // getAncestors method
    cout << "Implement getAncestors method" << endl;

    // cout<< "level(40): " << bst->getLevel(40) <<", ancestors(40): " << bst->getAncestors(40) << endl;
    // cout<< "level(20): " << bst->getLevel(20) <<", ancestors(20): " << bst->getAncestors(20) << endl;
    //   cout<< "level(10): " << bst->getLevel(10) <<", ancestors(10): " << bst->getAncestors(10) << endl;
    //  cout<< "level(30): " << bst->getLevel(30) <<", ancestors(30): " << bst->getAncestors(30) << endl;
    //  cout<< "level(60): " << bst->getLevel(60) <<", ancestors(60): " << bst->getAncestors(60) << endl;
    //   cout<< "level(50): " << bst->getLevel(50) <<", ancestors(50): " << bst->getAncestors(50) << endl;
    //   cout<< "level(70): " << bst->getLevel(70) <<", ancestors(70): " << bst->getAncestors(70) << endl;


    // remove method
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
        for (int &i : sortedInts) {
            cout << i << ", ";
            sortedFile << i << std::endl;
        }
        cout << endl;

        sortedFile.close();
    }

    bst->dumpInOrder(data);
    cout << "bst->dumpInOrder(data);" << endl;


} // end bstTester

void stringBstTester(BST<std::string> *bst) {
    cout << "\n\n* INTEGER BINARY SEARCH TREE * \n"
         << "******************************\n\n" << endl;

    cout << "** CREATE BST **" << endl;
    cout << "bst->size() returns number of nodes : " << bst->size()
         << "Should be 0" << endl;
    cout << "bst->getLeafCount() number of leaves : " << bst->getLeafCount()
         << "Should be 0 a" << endl;
    cout << "BST Height : " << bst->getHeight() << endl;
    cout << "BST empty : " << bst->empty() << endl;
    cout << "\n" << endl;

    cout << "Enter string file: ";
    std::string stringFileName;
    cin >> stringFileName;
    std::ifstream inFile;
    inFile.open(stringFileName);

    if (!inFile) {
        throw std::runtime_error("invalid input!");
    }
    cout << "** TEST INSERT**" << endl << "Inserting in this order: ";
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        std::string n;
        ss >> n;
        cout << n << " ";
        bst->insert(n);
    }
    cout << endl;

    cout << "# of nodes: " << bst->size() << endl;
    cout << "# of leaves: " << bst->getLeafCount() << endl;
    cout << "BST height: " << bst->getHeight() << endl;
    cout << "BST empty? " << bst->empty() << " (1 is true, 0 is false)" << endl;

    cout << "\n** TEST TRAVERSALS **" << endl;
    cout << "pre-order: " << bst->PreOrderTraversal() << endl;
    cout << "in-order: " << bst->InOrderTraversal() << endl;
    cout << "post-order: " << bst->PostOrderTraversal() << endl;
    cout << endl;

    cout << "** TEST LEVEL & ANCESTORS **" << endl;
    cout << "level(mary): " << bst->getLevel("mary") << " ancestors(mary): " << bst->getAncestors("mary") << endl;
    cout << "level(gene): " << bst->getLevel("gene") << " ancestors(gene): " << bst->getAncestors("gene") << endl;
    cout << "level(bea): " << bst->getLevel("bea") << " ancestors(bea): " << bst->getAncestors("bea") << endl;
    cout << "level(jen): " << bst->getLevel("jen") << " ancestors(jen): " << bst->getAncestors("jen") << endl;
    cout << "level(sue): " << bst->getLevel("sue") << " ancestors(sue): " << bst->getAncestors("sue") << endl;
    cout << "level(pat): " << bst->getLevel("pat") << " ancestors(pat): " << bst->getAncestors("pat") << endl;
    cout << "level(uma): " << bst->getLevel("uma") << " ancestors(uma): " << bst->getAncestors("uma") << endl;


    cout << "\n** TEST CONTAINS **" << endl;
    cout << "For all tests below: 1 is true, 0 is false" << endl;
    cout << "contains(gene): " << bst->contains("gene") << endl;
    cout << "contains(mary): " << bst->contains("mary") << endl;
    cout << "contains(bea): " << bst->contains("bea") << endl;
    cout << "contains(uma): " << bst->contains("uma") << endl;
    cout << "contains(yan): " << bst->contains("yan") << endl;
    cout << "contains(amy): " << bst->contains("amy") << endl;
    cout << "contains(ron): " << bst->contains("ron") << endl;
    cout << "contains(opal): " << bst->contains("opal") << endl;
    cout << endl;

    cout << "\n** TEST REMOVE **" << endl << "Inserting in this order: 20 40 10 70 99 -2 59 43";
    bst->remove("20");
    bst->remove("40");
    bst->remove("10");
    bst->remove("70");
    cout << "\n# of nodes: " << bst->size() << endl;
    cout << "# of leaves: " << bst->getLeafCount() << endl;
    cout << "BST height: " << bst->getHeight() << endl;
    cout << "BST empty? " << bst->empty() << " (1 is true, 0 is false)" << endl;
    cout << "pre-order: " << bst->PreOrderTraversal() << endl;
    cout << "in-order: " << bst->InOrderTraversal() << endl;
    cout << "post-order: " << bst->PostOrderTraversal() << endl;
    cout << endl;

    cout << "** TEST INSERT** (again)" << "Inserting in this order: 20 40 10 70 99 -2 59 43" << endl;
//    bst->insert("20");
//    bst->insert("40");
//    bst->insert("10");
//    bst->insert("70");
//    bst->insert("99");
//    bst->insert("-2");
//    bst->insert("59");
//    bst->insert("43");
    cout << "# of nodes: " << bst->size() << endl;
    cout << "# of leaves: " << bst->getLeafCount() << endl;
    cout << "BST height: " << bst->getHeight() << endl;
    cout << "BST empty? " << bst->empty() << " (1 is true, 0 is false)" << endl;
    cout << "pre-order: " << bst->PreOrderTraversal() << endl;
    cout << "in-order: " << bst->InOrderTraversal() << endl;
    cout << "post-order: " << bst->PostOrderTraversal() << endl;
    cout << endl;

    delete bst;
    inFile.close();
}

void integerBstTester(BST<int> *bst) {
    cout << "\n\n* INTEGER BINARY SEARCH TREE * \n"
         << "******************************\n\n" << endl;

    cout << "** CREATE BST **" << endl;
    cout << "bst->size() returns number of nodes : " << bst->size()
         << "Should be 0" << endl;
    cout << "bst->getLeafCount() number of leaves : " << bst->getLeafCount()
         << "Should be 0 a" << endl;
    cout << "BST Height : " << bst->getHeight() << endl;
    cout << "BST empty : " << bst->empty() << endl;
    cout << "\n" << endl;

    cout << "Enter integer file: ";
    std::string integerInput;
    cin >> integerInput;
    std::ifstream inFile;
    inFile.open(integerInput);
    if (!inFile) {
        throw std::runtime_error("invalid input!");
    }
    cout << "** TEST INSERT**" << endl << "Inserting in this order: ";
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        int n;
        ss >> n;
        cout << n << " ";
        bst->insert(n);
    }
    cout << endl;

    cout << "# of nodes: " << bst->size() << endl;
    cout << "# of leaves: " << bst->getLeafCount() << endl;
    cout << "BST height: " << bst->getHeight() << endl;
    cout << "BST empty? " << bst->empty() << " (1 is true, 0 is false)" << endl;

    cout << "\n** TEST TRAVERSALS **" << endl;
    cout << "pre-order: " << bst->PreOrderTraversal() << endl;
    cout << "in-order: " << bst->InOrderTraversal() << endl;
    cout << "post-order: " << bst->PostOrderTraversal() << endl;
    cout << endl;
/*
    cout << "\n ** TEST LEVEL & ANCESTORS **" << endl;
    cout<< "level(40): " << bst->getLevel(40) <<", ancestors(40): " << bst->getAncestors(40) << endl;
    cout<< "level(20): " << bst->getLevel(20) <<", ancestors(20): " << bst->getAncestors(20) << endl;
    cout<< "level(10): " << bst->getLevel(10) <<", ancestors(10): " << bst->getAncestors(10) << endl;
    cout<< "level(30): " << bst->getLevel(30) <<", ancestors(30): " << bst->getAncestors(30) << endl;
    cout<< "level(60): " << bst->getLevel(60) <<", ancestors(60): " << bst->getAncestors(60) << endl;
    cout<< "level(50): " << bst->getLevel(50) <<", ancestors(50): " << bst->getAncestors(50) << endl;
    cout<< "level(70): " << bst->getLevel(70) <<", ancestors(70): " << bst->getAncestors(70) << endl;
    cout << endl;
*/
    cout << "\n** TEST CONTAINS **" << endl;
    cout << "For all tests below: 1 is true, 0 is false" << endl;
    cout << "contains(20): " << bst->contains(20) << endl;
    cout << "contains(40): " << bst->contains(40) << endl;
    cout << "contains(10): " << bst->contains(10) << endl;
    cout << "contains(70): " << bst->contains(70) << endl;
    cout << "contains(99): " << bst->contains(99) << endl;
    cout << "contains(-2): " << bst->contains(-2) << endl;
    cout << "contains(59): " << bst->contains(59) << endl;
    cout << "contains(43): " << bst->contains(43) << endl;
    cout << endl;

    cout << "\n** TEST REMOVE **" << endl << "Inserting in this order: 20 40 10 70 99 -2 59 43";
    bst->remove(20);
    bst->remove(40);
    bst->remove(10);
    bst->remove(70);
    cout << "\n# of nodes: " << bst->size() << endl;
    cout << "# of leaves: " << bst->getLeafCount() << endl;
    cout << "BST height: " << bst->getHeight() << endl;
    cout << "BST empty? " << bst->empty() << " (1 is true, 0 is false)" << endl;
    cout << "pre-order: " << bst->PreOrderTraversal() << endl;
    cout << "in-order: " << bst->InOrderTraversal() << endl;
    cout << "post-order: " << bst->PostOrderTraversal() << endl;
    cout << endl;

    cout << "** TEST INSERT** (again)" << "Inserting in this order: 20 40 10 70 99 -2 59 43" << endl;
    bst->insert(20);
    bst->insert(40);
    bst->insert(10);
    bst->insert(70);
    bst->insert(99);
    bst->insert(-2);
    bst->insert(59);
    bst->insert(43);
    cout << "# of nodes: " << bst->size() << endl;
    cout << "# of leaves: " << bst->getLeafCount() << endl;
    cout << "BST height: " << bst->getHeight() << endl;
    cout << "BST empty? " << bst->empty() << " (1 is true, 0 is false)" << endl;
    cout << "pre-order: " << bst->PreOrderTraversal() << endl;
    cout << "in-order: " << bst->InOrderTraversal() << endl;
    cout << "post-order: " << bst->PostOrderTraversal() << endl;
    cout << endl;

    delete bst;
    inFile.close();
}

int main() {
    BST<std::string> *bstString = new BST<std::string>();

    cout << "Please provide the filename: " << endl;

    stringBstTester(bstString);

    cout << "Testing the BST Interface: \n" << endl;
    //bstTester(bst);
    BST<int> *bst = new BST<int>();
    integerBstTester(bst);
    cout << "\nAll done testing the BST Interface!" << endl;

    delete bst;
    delete bstString;
    return 0;
} // end main
