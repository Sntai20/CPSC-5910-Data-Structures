//
// Created by Scott McMaster on 5/16/2021.
//

#include <cmath>
#include "ArrayMaxHeap.h"

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize):
        itemCount(arraySize), maxItems(2 * arraySize)
{
    // Allocate the array
    items = new ItemType[maxItems];

    // Copy given values into the array
    for (int i = 0; i < itemCount; i++)
        items[i] = someArray[i];

    // Reorganize the array into a heap
    heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
    items = new ItemType[maxItems];
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {
    delete[] items;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
    for (int index = itemCount / 2 - 1; index >= 0; index--)
    {
        heapRebuild(index);
    }  // end for
}  // end heapCreate

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
    return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
    return std::max((nodeIndex - 1) / 2, 0);
}  // end getParentIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
    return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const {
    return ceil(log2(itemCount + 1));
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const
{
    if (isEmpty())
        throw std::length_error("Attempted peek into an empty heap.");

    return items[0];
}  // end peekTop

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
    return (itemCount == 0);
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {
    bool hasRoomToAdd = (itemCount < maxItems);
    if(!hasRoomToAdd)
    {
        ItemType* oldArray = items;
        items = new ItemType[2 * maxItems];
        for(int i = 0; i < maxItems; i++)
            items[i] = oldArray[i];
        delete[] oldArray;
        maxItems *= 2;
    }

    items[itemCount] = newData;

    int newDataIndex = itemCount;
    bool inPlace = false;
    while((newDataIndex > 0) && !inPlace)
    {
        int parentIndex = (newDataIndex - 1) / 2;
        if(items[newDataIndex] > items[parentIndex])
        {
            ItemType temp = items[newDataIndex];
            items[newDataIndex] = items[parentIndex];
            items[parentIndex] = temp;

            newDataIndex = parentIndex;
        }
        else
            inPlace = true;
    }
    itemCount++;

    return true;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove() {
    items[0] = items[itemCount - 1];
    itemCount--;
    heapRebuild(0);
    return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear() {
    itemCount = 0;
}

// private member function of ArrayMaxHeap
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int rootIndex) {
    if(2 * rootIndex + 1 < itemCount) // the root is not a leaf (that is, it has a left child)
    {
        int largerChildIndex = 2 * rootIndex + 1; // left child index
        if(largerChildIndex + 1 < itemCount) // the root has a right child
        {
            int rightChildIndex = largerChildIndex + 1;
            if(items[rightChildIndex] > items[largerChildIndex])
                largerChildIndex = rightChildIndex;
        }

        if(items[rootIndex] < items[largerChildIndex])
        {	// swap
            ItemType temp = items[rootIndex];
            items[rootIndex] = items[largerChildIndex];
            items[largerChildIndex] = temp;

            heapRebuild(largerChildIndex);
        }
    }
}