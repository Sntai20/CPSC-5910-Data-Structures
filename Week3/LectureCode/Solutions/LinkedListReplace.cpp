template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            // Replace the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = newNodePtr;
            newNodePtr->setNext(curPtr->getNext());
        }
        else
        {
            // Find node that is before the one to remove
            Node<ItemType>* prevPtr = getNodeAt(position - 1);

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
    }
    else
    {
        std::string message = "replace() called with an empty list or ";
        message = message + "invalid position.";
        throw(std::invalid_argument(message));
    } // end if
}  // end replace
