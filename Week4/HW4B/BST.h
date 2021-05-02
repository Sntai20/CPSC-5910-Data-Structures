//
// Created by Antonio Santana on 5/1/21.
//

#ifndef HW4B_BST_H
#define HW4B_BST_H

#include <vector>

using namespace std;

template<typename ItemType>
class BST {

public:
    BST();
    ~BST();
    bool contains(ItemType);
    void insert(ItemType);
    void remove(ItemType);

    // TODO: update traversals to avoid printing in class!
    void displayPreOrder();
    void displayInOrder();
    void displayPostOrder();

    void dumpInOrder(std::vector<ItemType>& dest);

private:
    struct Node {
        ItemType data;
        Node * left;
        Node * right;
    };
    Node * root;

    void displayPreOrder(Node *);
    void insert(Node *&, Node *&);
    void remove(Node *&, ItemType);
    void makeDeletion(Node *&);
    void destroyTree(Node *&);

    void dumpInOrderHelper(Node * root, std::vector<ItemType>& dest);
};

#include "BST.cpp"
#endif //HW4B_BST_H
