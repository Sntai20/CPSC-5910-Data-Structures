//
// Created by Antonio Santana on 4/25/21.
//
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>
#include <assert.h>

using namespace std;


template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {
} // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList) {
    this();
    Node<ItemType> *current = aList.headPtr;

    while (current != nullptr) {
        this->append(current->getItem());
        current = current->getNext();
    }

} // This is the copy constructor definition.


template<class ItemType>
LinkedList<ItemType> &LinkedList<ItemType>::operator=(LinkedList<char> *aList) {
    itemCount = aList->itemCount;
    Node<ItemType> *origChainPtr = aList->headPtr;

    if (origChainPtr == nullptr) {
        headPtr = nullptr; // Original bag is empty; so is copy
    } else {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        // Copy remaining nodes
        Node<ItemType> *newChainPtr = headPtr; // Last-node pointer

        while (origChainPtr != nullptr) {
            origChainPtr = origChainPtr->getNext(); // Advance pointer
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            // Create a new node containing the next item
            Node<ItemType> *newNodePtr = new Node<ItemType>(nextItem);
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
        } // end while
        newChainPtr->setNext(nullptr); // Flag end of new chain
    } // end if
} // end Copy constructor implementation

template<class ItemType>
void LinkedList<ItemType>::clear() {
    while (!isEmpty())
        remove(1);
} // end clear

template<class ItemType>
void LinkedList<ItemType>::append(const ItemType &newEntry) {
    insert(this->getLength()+1, newEntry);
} // end append

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
} // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}  // end getLength

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet) {
        Node<ItemType> *nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    } else {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw (std::invalid_argument(message));
    } // end if
} // end getEntry

// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType> *LinkedList<ItemType>::getNodeAt(int position) const {
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));

    // Count from the beginning of the chain
    Node<ItemType> *curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType &newEntry) {
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert) {
        // Create a new node containing the new entry
        Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);
        // Attach new node to chain
        if (newPosition == 1) {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        } else {
            // Find node that will be before new node
            Node<ItemType> *prevPtr = getNodeAt(newPosition - 1);

            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        } // end if

        itemCount++; // Increase count of entries
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove) {
        Node<ItemType> *curPtr = nullptr;
        if (position == 1) {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        } else {
            // Find node that is before the one to remove
            Node<ItemType> *prevPtr = getNodeAt(position - 1);

            // Point to node to remove
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        } // end if

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--; // Decrease count of entries
    } // end if

    return ableToRemove;
} // end remove


template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType &newEntry) {
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet) {
        Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);

        Node<ItemType> *curPtr = nullptr;
        if (position == 1) {
            // Replace the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = newNodePtr;
            newNodePtr->setNext(curPtr->getNext());
        } else {
            // Find node that is before the one to remove
            Node<ItemType> *prevPtr = getNodeAt(position - 1);

            // Point to node to replace
            curPtr = prevPtr->getNext();

            prevPtr->setNext(newNodePtr);
            newNodePtr->setNext(curPtr->getNext());
        } // end if

        // Return node to system and clean up the removed node.
        ItemType ret = curPtr->getItem();
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        return ret;
    } else {
        std::string message = "replace() called with an empty list or ";
        message = message + "invalid position.";
        throw (std::invalid_argument(message));
    } // end if
}  // end replace

template<class ItemType>
int LinkedList<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    int frequency = 0;
    int counter = 0;
    Node<ItemType> *curPtr = headPtr;

    while ((curPtr != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType &anEntry) const {
    bool listContains = getFrequencyOf(anEntry) > 0;
    return listContains;
} // end contains


template<class ItemType>
bool LinkedList<ItemType>::containsRecursive(const ItemType &anEntry) const {
    return containsRecursive_(anEntry, headPtr);
}

template<class ItemType>
bool LinkedList<ItemType>::containsRecursive_(const ItemType &anEntry, Node<ItemType> *curPtr) const {
    if (curPtr != nullptr) {
        if (anEntry == curPtr->getItem()) {
            return true;
        } else {
            return containsRecursive_(anEntry, curPtr->getNext());
        }
    }

    return false;
}