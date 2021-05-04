//
// Created by Antonio Santana on 5/1/21.
//
#include "BST.h"
#include <iostream>
#include <sstream>
#include <string>
//#include <vector>

using namespace std;

template<class ItemType>
BST<ItemType>::BST() {
    root = nullptr;
}

template<class ItemType>
BST<ItemType>::~BST() {
    destroyTree(root);
}

template<class ItemType>
void BST<ItemType>::destroyTree(Node *&ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
    ptr = nullptr;
}

template<class ItemType>
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

template<class ItemType>
void BST<ItemType>::insert(ItemType item) {
    Node * newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template<class ItemType>
void BST<ItemType>::insert(Node *& ptr, Node *& newNode) {
    if (ptr == nullptr)
        ptr = newNode;
    else if (ptr->data > newNode->data)
        insert(ptr->left, newNode);
    else
        insert(ptr->right, newNode);
}

template<class ItemType>
void BST<ItemType>::remove(ItemType item) {
    remove(root, item);
}

template<class ItemType>
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

template<class ItemType>
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

template<class ItemType>
void BST<ItemType>::displayPreOrder() {
    displayPreOrder(root);
}

template<class ItemType>
void BST<ItemType>::displayPreOrder(Node * ptr) {
    if (ptr != nullptr) {
        cout << ptr->data << endl;
        displayPreOrder(ptr->left);
        displayPreOrder(ptr->right);
    }
}

template<class ItemType>
void BST<ItemType>::dumpInOrderHelper(Node *ptr, std::vector<ItemType>& dest) {
    if (ptr != nullptr) {
        dumpInOrderHelper(ptr->left, dest);
        dest.push_back(ptr->data);
        dumpInOrderHelper(ptr->right, dest);
    }
}

// Writes the BST in-order to the given array. Note that this function is both inflexible
// and a not memory-efficient way to do a traversal (why?).
template<class ItemType>
void BST<ItemType>::dumpInOrder(std::vector<ItemType>& dest) {
    dumpInOrderHelper(root, dest);
}

// TODO: try to write displayInOrder and displayPostOrder
template<class ItemType>
void BST<ItemType>::displayInOrder() {
    displayInOrder(root);
}

template<class ItemType>
void BST<ItemType>::displayInOrder(Node * ptr) {
    if (ptr != nullptr) {
        cout << ptr->data << endl;
        displayInOrder(ptr->left);
        displayInOrder(ptr->right);
    }
}

template<class ItemType>
void BST<ItemType>::displayPostOrder() {
    displayPostOrder(root);
}

template<class ItemType>
void BST<ItemType>::displayPostOrder(Node * ptr) {
    if (ptr != nullptr) {
        cout << ptr->data << endl;
        displayPostOrder(ptr->right);
        displayPostOrder(ptr->left);
    }
}

template<class ItemType>
string BST<ItemType>::PreOrderTraversal(){
    stringstream ss;
    PreOrderTraversal(root, ss);
    string s = ss.str();
    s.pop_back();
    return s;
}

template<class ItemType>
void BST<ItemType>::PreOrderTraversal(Node *& ptr, stringstream &ss) {
    if (ptr != nullptr) {
        ss << ptr->data << " ";
        PreOrderTraversal(ptr->left, ss);
        PreOrderTraversal(ptr->right, ss);
    }
}

template<class ItemType>
string BST<ItemType>::InOrderTraversal() {
    stringstream ss;
    InOrderTraversal(root, ss);
    string s = ss.str();
    s.pop_back();
    return s;
}


template<class ItemType>
void BST<ItemType>::InOrderTraversal(Node *& ptr, stringstream& ss) {
    if (ptr != nullptr) {
        InOrderTraversal(ptr->left, ss);
        ss << ptr->data << " ";
        InOrderTraversal(ptr->right, ss);
    }
}

template<class ItemType>
string BST<ItemType>::PostOrderTraversal() {
    stringstream ss;
    PostOrderTraversal(root, ss);
    string s = ss.str();
    s.pop_back();
    return s;
}

template<class ItemType>
void BST<ItemType>::PostOrderTraversal(Node *& ptr, stringstream& ss) {
    if (ptr != nullptr) {
        PostOrderTraversal(ptr->left, ss);
        PostOrderTraversal(ptr->right, ss);
        ss << ptr->data << " ";
    }
}

template<class ItemType>
int BST<ItemType>::getHeight() {
    return getHeightHelper(root);
}

template<class ItemType>
int BST<ItemType>::getHeightHelper(Node *& ptr) {
    if (ptr == nullptr) {
        return 0;
    }
    else{
        return 1 + max(getHeightHelper(ptr->left), getHeightHelper(ptr->right));
    }
}

template<class ItemType>
int BST<ItemType>::getLevel(ItemType newEntry) {
    return getLevelHelper(root, newEntry, 0);
}

template<class ItemType>
int BST<ItemType>::getLevelHelper(Node *& ptr, ItemType newEntry, int level) {
    if (ptr == nullptr){
        return -1;
    }
    if (ptr->data == newEntry){
        return level;
    }

    int minusLevel = getLevelHelper(ptr->left, newEntry, level + 1);

    if (minusLevel != -1){
        return minusLevel;
    }

    minusLevel = getLevelHelper(ptr->right, newEntry, level + 1);

    return minusLevel;
}

template<class ItemType>
int BST<ItemType>::getLeafCount() {
    return getLeafCountHelper(root);
}

template<class ItemType>
int BST<ItemType>::size() {
    return sizeHelper(root);
}

template<class ItemType>
int BST<ItemType>::sizeHelper(Node *& ptr) {
    int count = 1;
    if (ptr == nullptr){
        return 0;
    }
    else{
        count += sizeHelper(ptr->left);
        count += sizeHelper(ptr->right);
        return count;
    }
}


template<class ItemType>
bool BST<ItemType>::empty() {
    return false;
}

template<class ItemType>
std::string BST<ItemType>::getAncestors(ItemType item) {
    return getAncestorsHelper(root, item);
}
template<class ItemType>
std::string BST<ItemType>::getAncestorsHelper(Node *& ptr, ItemType item) {
    std::string emptyData = " ";
    std::string newData;
    std::stringstream ss;

    if (contains(item)){
        if (ptr->data > item){
            if ((ptr->data) == item) {
                return emptyData;
            }
            ss << ptr->data;
            ss >> newData;
            emptyData += newData;
            return getAncestorsHelper(ptr->left, item) + emptyData + " ";
        }
        else{
            if ((ptr->data) == item) {
                return emptyData;
            }
            ss << ptr->data;
            ss >> newData;
            emptyData += newData;
            return getAncestorsHelper(ptr->right, item) + emptyData + " ";
        }
    }
    return NULL;
}

template<class ItemType>
int BST<ItemType>::getLeafCountHelper(Node *& ptr) {
    if (ptr == nullptr){
        return 0;
    }
    if (ptr->left == nullptr && ptr->right == nullptr){
        return 1;
    }
    else{
        return getLeafCountHelper(ptr->left) + getLeafCountHelper(ptr->right);
    }
}





