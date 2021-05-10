//
// Created by Antonio Santana on 5/10/21.
//
#include "LinkedList.h"
#include <stdexcept>
#include <iostream>
#include <assert.h>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
void LinkedList<ItemType>::copyListNodes(const LinkedList<ItemType>& other) {
    itemCount = other.itemCount;
    Node<ItemType>* origChainPtr = other.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original list is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainPtr->setNext(nullptr);              // Flag end of new chain
    }  // end if
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
    copyListNodes(aList);
} // end copy constructor

template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& rightHandSide)
{
    // Check for assignment to self
    if (this != &rightHandSide)
    {
        this->clear();                       // Deallocate left-hand side
        copyListNodes(rightHandSide);        // Copy list nodes
    }  // end if

    return *this;
}  // end operator=

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
} // end clear

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
} // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(std::invalid_argument(message));
    } // end if
} // end getEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        } // end if

        itemCount++; // Increase count of entries
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to remove
            Node<ItemType>* prevPtr = getNodeAt(position - 1);

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
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
    std::cout << "replacing at position " << position << " with " + newEntry << std::endl;

    // TODO
    return getEntry(3);
}  // end replace

// TODO: LinkedList<ItemType>>::contains
template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType& findme){
    Node<ItemType>* cur = headPtr;
    while (cur != nullptr) {
        if (cur->getItem() == findme) {
            return true;
        }
        cur = cur->getNext();
    }
    return false;
}

// TODO: LinkedList<ItemType>>::containsRecursive
template<class ItemType>
bool LinkedList<ItemType>::containsRecursiveHelper(const Node<ItemType>* head, const ItemType& findme) {
    if (head == nullptr) {
        return false;
    }
    return head->getItem() == findme || containsRecursiveHelper(head->getNext(), findme);
}

template<class ItemType>
bool LinkedList<ItemType>::containsRecursive(const ItemType& findme) {
    return containsRecursiveHelper(headPtr, findme);
}

template<class ItemType>
void LinkedList<ItemType>::copyReverseHelper(Node<ItemType>* head, LinkedList<ItemType>& dest) const {
    if (head == nullptr) {
        return;
    }
    copyReverseHelper(head->getNext(), dest);
    dest.insert(dest.getLength() + 1, head->getItem());
}

template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::copyReverse() const {
    LinkedList<ItemType> dest;
    copyReverseHelper(headPtr, dest);
    return dest;
}