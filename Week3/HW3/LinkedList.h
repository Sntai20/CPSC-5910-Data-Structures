//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
// Created by Antonio Santana on 4/25/21.
//

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList); // This is the copy constructor definition.
    LinkedList<ItemType>& operator=(LinkedList<char> *aList);

    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    void append(const ItemType& newEntry);
    bool remove(int position);
    void clear();

    /** @throw std::invalid_argument if position < 1 or
                                        position > getLength(). */
    ItemType getEntry(int position) const;

    int getFrequencyOf(const ItemType& anEntry) const;

    /** @throw std::invalid_argument if position < 1 or
                                        position > getLength(). */
    ItemType replace(int position, const ItemType& newEntry);

    /** @throw std::invalid_argument if position < 1 or
     *                                  position > getLength().
     * @param position
     * @param Entry
     * @return
     */
    bool contains(const ItemType& anEntry) const;
    bool containsRecursive(const ItemType& anEntry) const;
    bool containsRecursive_(const ItemType &anEntry, Node<ItemType> *curPtr) const ;

}; // end LinkedList

#include "LinkedList.cpp"
#endif
