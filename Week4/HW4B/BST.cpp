//
// Created by Antonio Santana on 5/1/21.
//

#include "BST.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename ItemType>
BST<ItemType>::BST() {
    root = nullptr;
}

template<typename ItemType>
BST<ItemType>::~BST() {
    destroyTree(root);
}

template<typename ItemType>
void BST<ItemType>::destroyTree(Node *&ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
    ptr = nullptr;
}

template<typename ItemType>
bool BST<ItemType>::contains(ItemType item) {
    Node * ptr = root;
    while (ptr != nullptr) {
        if (ptr->data == item)
            return true;
        else if (ptr->data > item)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return false;
}

template<typename ItemType>
void BST<ItemType>::insert(ItemType item) {
    Node * newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template<typename ItemType>
void BST<ItemType>::insert(Node *& ptr, Node *& newNode) {
    if (ptr == nullptr)
        ptr = newNode;
    else if (ptr->data > newNode->data)
        insert(ptr->left, newNode);
    else
        insert(ptr->right, newNode);
}

template<typename ItemType>
void BST<ItemType>::remove(ItemType item) {
    remove(root, item);
}

template<typename ItemType>
void BST<ItemType>::remove(Node *& ptr, ItemType item) {
    if (ptr != nullptr) {
        if (ptr->data > item)
            remove(ptr->left, item);
        else if (ptr->data < item)
            remove(ptr->right, item);
        else
            makeDeletion(ptr);
    }
}

template<typename ItemType>
void BST<ItemType>::makeDeletion(Node *& ptr) {
    Node * curr = nullptr;
    if (ptr != nullptr) {
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {
            curr = ptr->right;
            while (curr->left != nullptr)
                curr = curr->left;
            ptr->data = curr->data;
            remove(ptr->right, curr->data);
        }
    }
}

template<typename ItemType>
void BST<ItemType>::displayPreOrder() {
    displayPreOrder(root);
}

template<typename ItemType>
void BST<ItemType>::displayPreOrder(Node * ptr) {
    if (ptr != nullptr) {
        //cout << ptr->data << endl;
        displayPreOrder(ptr->left);
        displayPreOrder(ptr->right);
    }
}

template<typename ItemType>
void BST<ItemType>::dumpInOrderHelper(Node *ptr, std::vector<ItemType>& dest) {
    if (ptr != nullptr) {
        dumpInOrderHelper(ptr->left, dest);
        dest.push_back(ptr->data);
        dumpInOrderHelper(ptr->right, dest);
    }
}

// Writes the BST in-order to the given array. Note that this function is both inflexible
// and a not memory-efficient way to do a traversal (why?).
template<typename ItemType>
void BST<ItemType>::dumpInOrder(std::vector<ItemType>& dest) {
    dumpInOrderHelper(root, dest);
}

// TODO: try to write displayInOrder and displayPostOrder

